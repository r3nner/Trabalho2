#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pesquisa.h"

void converteStringMatriz(char **mat, char *string, int linhas, int colunas){
    int i, j;
    for (i=0; i<linhas; i++){
        for (j=0; j<colunas; j++){
            mat[i][j]= string[i*colunas+j];
        }
    }
}

void printaMatriz(char **mat, char *string, int linha, int coluna){
    int i, j, cont, tam;
    cont=0;
    tam = strlen(string);
    printf("    ");
    for (int k=0; k<coluna; k++){ //numero da coluna
        printf(" %d ", k+1);
    }
    printf("\n");
    for(i=0; i<linha; i++){
        printf(" %d  ", i+1);
        for (j=0; j<coluna; j++){
            if (cont >= tam){
                mat[i][j] = '\0';
            }
            printf(" %c ", mat[i][j]);
            cont++;
        }
        printf("\n");
    }
}

void elaboraMatriz(char **mat, int linhas, int colunas){
    int i=0, j=0;
    char *string;
    char *novastring;
    string = (char*)malloc(linhas * colunas * sizeof(char) + 1);
    novastring = (char*)malloc(linhas * colunas * sizeof(char) + 1);
    if (novastring == NULL || string == NULL){
        printf("\n\nERRO na alocação de memória\n\n");
        exit(1);
    }

    // Limpa a string novastring
    for (i=0; i < linhas * colunas; i++){
        novastring[i] = '\0';
    }

    printf("\nEscreva um texto para completar a matriz: ");
    fgets(string, linhas * colunas + 1, stdin);
    fgets(string, linhas * colunas + 1, stdin);  // para limpar o buffer
    printf("\n\n%s\n\n", string);
    
    i = 0;
    while (string[i] != '\0'){ //tira espaços em branco
        if (string[i] == ' '){
            i++;
        } else {
            novastring[j] = string[i];
            j++;
            i++;
        }
    }
    novastring[j] = '\0';
    
    converteStringMatriz(mat, novastring, linhas, colunas);
    printaMatriz(mat, novastring, linhas, colunas);
    
    free(novastring);
    free(string);
}

void recebeEntrada(char **mat, int l, int c){
    char palavra[20];
    do{
        printf("\nEscreva a palavra que deseja procurar ou escreva SAIR para sair: ");
        scanf("%s", palavra);
        if (strcmp(palavra, "SAIR") == 0){
            return;
        }
        pesquisa(mat, palavra, l, c);
    } while (strcmp(palavra, "1") != 0);
}

int main(){
    int l, c, i;
    char **mat;
    printf("\nDigite o numero de linhas: ");
    scanf("%d", &l);
    printf("\nDigite o numero de colunas: ");
    scanf("%d", &c);

    // Aloca matriz
    mat = (char**)malloc(l * sizeof(char*));
    for (i = 0; i < l; i++){
        mat[i] = (char*)malloc(c * sizeof(char));
    }

    elaboraMatriz(mat, l, c);
    recebeEntrada(mat, l, c);

    // Desaloca a matriz
    for (i = 0; i < l; i++){
        free(mat[i]);
    }
    free(mat);

    return 0;
}
