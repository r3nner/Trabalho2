#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pesquisa.h"

int direcao(int x, int y, char *palavra, char **matriz, int l, int c){
    int tamPalavra = strlen(palavra);
    int match, i;

    //horizontal para a direita
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

    //horizontal para a esquerda
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

    //vertical para cima
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

    //vertical para baixo
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

    //diagonal principal normal
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

    //diagonal secundária normal
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

    //diagonal principal reversa
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

    //diagonal secundária reversa
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

    return 0;  //se não tiver direção válida
}

int restantePalavra(int x, int y, char* palavra, char **matriz, int l, int c) {
    int tamPalavra = strlen(palavra);

    int sentido = direcao(x, y, palavra, matriz, l, c);
    if (sentido==0){ //se a palavra nao bater
        return 0;
    }
    //posicoes validas
    if (sentido == 1) {
        printf("\nPalavra %s ocorre na horizontal direta, iniciando na posicao [%i,%i] e terminando na posicao [%d, %d].\n", palavra, x + 1, y + 1, x + 1, y + tamPalavra);
    } else if (sentido == 2) {
        printf("\nPalavra %s ocorre na horizontal reversa, iniciando na posicao [%i,%i] e terminando na posicao [%d, %d].\n", palavra, x + 1, y + 1, x + 1, y - tamPalavra + 2);
    } else if (sentido == 3) {
        printf("\nPalavra %s ocorre na vertical reversa, iniciando na posicao [%i,%i] e terminando na posicao [%d, %d].\n", palavra, x + 1, y + 1, x - tamPalavra + 2, y + 1);
    } else if (sentido == 4) {
        printf("\nPalavra %s ocorre na vertical direta, iniciando na posicao [%i,%i] e terminando na posicao [%d, %d].\n", palavra, x + 1, y + 1, x + tamPalavra, y + 1);
    } else if (sentido == 5) {
        printf("\nPalavra %s ocorre na diagonal principal direta, iniciando na posicao [%i,%i] e terminando na posicao [%d, %d].\n", palavra, x + 1, y + 1, x + tamPalavra, y + tamPalavra);
    } else if (sentido == 6) {
        printf("\nPalavra %s ocorre na diagonal secundária direta, iniciando na posicao [%i,%i] e terminando na posicao [%d, %d].\n", palavra, x + 1, y + 1, x + tamPalavra, y - tamPalavra + 2);
    } else if (sentido == 7) {
        printf("\nPalavra %s ocorre na diagonal principal reversa, iniciando na posicao [%i,%i] e terminando na posicao [%d, %d].\n", palavra, x + 1, y + 1, x - tamPalavra + 2, y + tamPalavra);
    } else if (sentido == 8) {
        printf("\nPalavra %s ocorre na diagonal secundária reversa, iniciando na posicao [%i,%i] e terminando na posicao [%d, %d].\n", palavra, x + 1, y + 1, x - tamPalavra + 2, y - tamPalavra + 2);
    }

    return 1;
}

void pesquisa(char **matriz, char palavra[], int l, int c) {
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
