#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pesquisa.h"

int direcao(int x, int y, char *palavra, char **matriz, int l, int c){
    // Direções:
    // horizontal para a direita
    if (y + 1 < c && matriz[x][y + 1] == palavra[1]) {
        return 1;
    }
    // horizontal para a esquerda
    else if (y - 1 >= 0 && matriz[x][y - 1] == palavra[1]) {
        return 2;
    }
    // vertical para cima
    else if (x - 1 >= 0 && matriz[x - 1][y] == palavra[1]) {
        return 3;
    }
    // vertical para baixo
    else if (x + 1 < l && matriz[x + 1][y] == palavra[1]) {
        return 4;
    }
    // diagonal principal normal
    else if (x + 1 < l && y + 1 < c && matriz[x + 1][y + 1] == palavra[1]) {
        return 5;
    }
    // diagonal secundária normal
    else if (x + 1 < l && y - 1 >= 0 && matriz[x + 1][y - 1] == palavra[1]) {
        return 6;
    }
    // diagonal principal reversa
    else if (x - 1 >= 0 && y + 1 < c && matriz[x - 1][y + 1] == palavra[1]) {
        return 7;
    }
    // diagonal secundária reversa
    else if (x - 1 >= 0 && y - 1 >= 0 && matriz[x - 1][y - 1] == palavra[1]) {
        return 8;
    }
    return 0;
}

int restantePalavra(int x, int y, char palavra[], char **matriz, int l, int c){
    int tamPalavra = strlen(palavra);
    int sentido = direcao(x, y, palavra, matriz, l, c);

    int j;
    switch (sentido){
        case 0:
            return 0;

        case 1: // horizontal direita
            for (j = 0; j < tamPalavra; j++){  // Inicializando j corretamente
                if ( y + j >= c || matriz[x][y + j] != palavra[j] ){
                    return 0;
                }
            }
            break;

        case 2: // horizontal esquerda
            for (j = 0; j < tamPalavra; j++){
                if ( y - j < 0 || matriz[x][y - j] != palavra[j]){
                    return 0;
                }
            }
            break;

        case 3: // vertical para cima
            for (j = 0; j < tamPalavra; j++){
                if (x - j < 0 || matriz[x - j][y] != palavra[j]){
                    return 0;
                }
            }
            break;

        case 4: // vertical para baixo
            for (j = 0; j < tamPalavra; j++){
                if (x + j >= l || matriz[x + j][y] != palavra[j] ){
                    return 0;
                }
            }
            break;

        case 5: // diagonal principal normal
            for (j = 0; j < tamPalavra; j++){
                if ( x + j >= l || y + j >= c || matriz[x + j][y + j] != palavra[j]){
                    return 0;
                }
            }
            break;

        case 6: // diagonal secundária normal
            for (j = 0; j < tamPalavra; j++){
                if ( x + j >= l || y - j < 0 || matriz[x + j][y - j] != palavra[j] ){
                    return 0;
                }
            }
            break;

        case 7: // diagonal principal reversa
            for (j = 0; j < tamPalavra; j++){
                if (x - j < 0 || y + j >= c || matriz[x - j][y + j] != palavra[j] ){
                    return 0;
                }
            }
            break;

        case 8: // diagonal secundária reversa
            for (j = 0; j < tamPalavra; j++){
                if (x - j < 0 || y - j < 0 || matriz[x - j][y - j] != palavra[j]){
                    return 0;
                }
            }
            break;
    }

   //exibir
    if (sentido == 1){
        printf("\nPalavra %s ocorre na horizontal direta, iniciando na posição [%i,%i] e terminando na posição [%d, %d].\n", palavra, x + 1, y + 1, x + 1, y + j);
    } else if (sentido == 2){
        printf("\nPalavra %s ocorre na horizontal reversa, iniciando na posição [%i,%i] e terminando na posição [%d, %d].\n", palavra, x + 1, y + 1, x + 1, y - j + 2);
    } else if (sentido == 3){
        printf("\nPalavra %s ocorre na vertical reversa, iniciando na posição [%i,%i] e terminando na posição [%d, %d].\n", palavra, x + 1, y + 1, x - j + 2, y + 1);
    } else if (sentido == 4){
        printf("\nPalavra %s ocorre na vertical direta, iniciando na posição [%i,%i] e terminando na posição [%d, %d].\n", palavra, x + 1, y + 1, x + j, y + 1);
    } else if (sentido == 5){
        printf("\nPalavra %s ocorre na diagonal principal direta, iniciando na posição [%i,%i] e terminando na posição [%d, %d].\n", palavra, x + 1, y + 1, x + j, y + j);
    } else if (sentido == 6){
        printf("\nPalavra %s ocorre na diagonal secundária direta, iniciando na posição [%i,%i] e terminando na posição [%d, %d].\n", palavra, x + 1, y + 1, x + j, y - j + 2);
    } else if (sentido == 7){
        printf("\nPalavra %s ocorre na diagonal secundária reversa, iniciando na posição [%i,%i] e terminando na posição [%d, %d].\n", palavra, x + 1, y + 1, x - j + 2, y + j);
    } else if (sentido == 8){
        printf("\nPalavra %s ocorre na diagonal principal reversa, iniciando na posição [%i,%i] e terminando na posição [%d, %d].\n", palavra, x + 1, y + 1, x - j + 2, y - j + 2);
    }
    return 1;
}

void pesquisa(char **matriz, char* palavra, int l, int c){
    // Busca a primeira letra da palavra
    int flag = 0;
    for (int i = 0; i < l; i++){
        for (int j = 0; j < c; j++){
            if (matriz[i][j] == palavra[0]){
                flag = restantePalavra(i, j, palavra, matriz, l, c);
                if (flag == 1){
                    return;
                }
            }
        }
    }
    if (flag == 0){
        printf("Palavra nao encontrada.\n");
    }
}
