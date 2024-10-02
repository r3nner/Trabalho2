#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pesquisa.h"

// Função para detectar a direção da palavra
int direcao(int x, int y, char *palavra, char **matriz, int l, int c) {
    int tamPalavra = strlen(palavra);
    int match, i;
    
    // Horizontal para a direita
    if (y + tamPalavra - 1 < c) {
        match = 1;
        for (i = 1; i < tamPalavra; i++) {
            if (matriz[x][y + i] != palavra[i]) {
                match = 0;
                break;
            }
        }
        if (match) return 1;
    }

    // Horizontal para a esquerda
    if (y - (tamPalavra - 1) >= 0) {
        match = 1;
        for (i = 1; i < tamPalavra; i++) {
            if (matriz[x][y - i] != palavra[i]) {
                match = 0;
                break;
            }
        }
        if (match) return 2;
    }

    // Vertical para cima
    if (x - (tamPalavra - 1) >= 0) {
        match = 1;
        for (i = 1; i < tamPalavra; i++) {
            if (matriz[x - i][y] != palavra[i]) {
                match = 0;
                break;
            }
        }
        if (match) return 3;
    }

    // Vertical para baixo
    if (x + tamPalavra - 1 < l) {
        match = 1;
        for (i = 1; i < tamPalavra; i++) {
            if (matriz[x + i][y] != palavra[i]) {
                match = 0;
                break;
            }
        }
        if (match) return 4;
    }

    // Diagonal principal normal (baixo-direita)
    if (x + tamPalavra - 1 < l && y + tamPalavra - 1 < c) {
        match = 1;
        for (i = 1; i < tamPalavra; i++) {
            if (matriz[x + i][y + i] != palavra[i]) {
                match = 0;
                break;
            }
        }
        if (match) return 5;
    }

    // Diagonal secundária normal (baixo-esquerda)
    if (x + tamPalavra - 1 < l && y - (tamPalavra - 1) >= 0) {
        match = 1;
        for (i = 1; i < tamPalavra; i++) {
            if (matriz[x + i][y - i] != palavra[i]) {
                match = 0;
                break;
            }
        }
        if (match) return 6;
    }

    // Diagonal principal reversa (cima-direita)
    if (x - (tamPalavra - 1) >= 0 && y + tamPalavra - 1 < c) {
        match = 1;
        for (i = 1; i < tamPalavra; i++) {
            if (matriz[x - i][y + i] != palavra[i]) {
                match = 0;
                break;
            }
        }
        if (match) return 7;
    }

    // Diagonal secundária reversa (cima-esquerda)
    if (x - (tamPalavra - 1) >= 0 && y - (tamPalavra - 1) >= 0) {
        int match = 1;
        for (int i = 1; i < tamPalavra; i++) {
            if (matriz[x - i][y - i] != palavra[i]) {
                match = 0;
                break;
            }
        }
        if (match) return 8;
    }

    return 0;  // Não encontrou direção válida
}

// Função para verificar o restante da palavra em uma direção específica
int restantePalavra(int x, int y, char* palavra, char **matriz, int l, int c) {
    int tamPalavra = strlen(palavra);  // Aqui sem subtrair 1, para calcular a posição final corretamente

    int sentido = direcao(x, y, palavra, matriz, l, c);

    // Exibir as direções detectadas
    if (sentido == 1) {
        printf("\nPalavra %s ocorre na horizontal direta, iniciando na posicao [%i,%i] e terminando na posicao [%d, %d].\n", palavra, x + 1, y + 1, x + 1, y + tamPalavra);
    } else if (sentido == 2) {
        printf("\nPalavra %s ocorre na horizontal reversa, iniciando na posicao [%i,%i] e terminando na posicao [%d, %d].\n", palavra, x + 1, y + 1, x + 1, y - tamPalavra + 1);
    } else if (sentido == 3) {
        printf("\nPalavra %s ocorre na vertical reversa, iniciando na posicao [%i,%i] e terminando na posicao [%d, %d].\n", palavra, x + 1, y + 1, x - tamPalavra + 1, y + 1);
    } else if (sentido == 4) {
        printf("\nPalavra %s ocorre na vertical direta, iniciando na posicao [%i,%i] e terminando na posicao [%d, %d].\n", palavra, x + 1, y + 1, x + tamPalavra, y + 1);
    } else if (sentido == 5) {
        printf("\nPalavra %s ocorre na diagonal principal direta, iniciando na posicao [%i,%i] e terminando na posicao [%d, %d].\n", palavra, x + 1, y + 1, x + tamPalavra, y + tamPalavra);
    } else if (sentido == 6) {
        printf("\nPalavra %s ocorre na diagonal secundária direta, iniciando na posicao [%i,%i] e terminando na posicao [%d, %d].\n", palavra, x + 1, y + 1, x + tamPalavra, y - tamPalavra + 1);
    } else if (sentido == 7) {
        printf("\nPalavra %s ocorre na diagonal principal reversa, iniciando na posicao [%i,%i] e terminando na posicao [%d, %d].\n", palavra, x + 1, y + 1, x - tamPalavra + 1, y + tamPalavra);
    } else if (sentido == 8) {
        printf("\nPalavra %s ocorre na diagonal secundária reversa, iniciando na posicao [%i,%i] e terminando na posicao [%d, %d].\n", palavra, x + 1, y + 1, x - tamPalavra + 1, y - tamPalavra + 1);
    }
    
    return 1;
}

// Função para pesquisar a palavra na matriz
void pesquisa(char **matriz, char* palavra, int l, int c) {
    // Busca a primeira letra da palavra
    int flag = 0;
    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            if (matriz[i][j] == palavra[0]) {
                flag = restantePalavra(i, j, palavra, matriz, l, c);
                if (flag == 1) {
                    return;
                }
            }
        }
    }
    if (flag == 0) {
        printf("Palavra nao encontrada.\n");
    }
}
