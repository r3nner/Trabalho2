#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pesquisa.h"

void liberaMatriz(char **mat, int l) //para desalocar a matriz
{
    int i;
    for (i= 0; i< l; i++){
        free(mat[i]);
    }
    free(mat);
}

void converteStringMatriz(char **mat, char *string, int linhas, int colunas){ //passa a string texto para uma matriz
    int i, j;
    for (i=0; i<linhas; i++){
        for (j=0; j<colunas; j++){
            mat[i][j]= string[i*colunas+j];
        }
    }
}

void printaMatriz(char **mat, char *string, int linha, int coluna){ //mostra a matriz na tela
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
    string = (char*)malloc(linhas * colunas * sizeof(char) + 1); //alocação dinamica da string principal e do espelho
    novastring = (char*)malloc(linhas * colunas * sizeof(char) + 1);

    if (novastring == NULL || string == NULL){
        printf("\n\nERRO na alocação de memória\n\n");
        exit(1);
    }

    for (i=0; i < linhas * colunas; i++){ //para tirar lixo e limpar a nova string
        novastring[i] = '\0';
    }

    printf("\nEscreva um texto para completar a matriz: ");
    scanf(" %[^\n]", string);

    i= 0;
    while (string[i] != '\0'){ //tira espaços em branco
        if (string[i] == ' '){
            i++;
        }else{
            novastring[j] = string[i];
            j++;
            i++;
        }
    }
    novastring[j] = '\0'; //finaliza a string

    converteStringMatriz(mat, novastring, linhas, colunas);
    printaMatriz(mat, novastring, linhas, colunas);

}

void recebeEntrada(char **mat, int l, int c){
    char palavra[20];
    while (1>0){
        printf("\nEscreva a palavra que deseja procurar ou escreva SAIR para sair: ");
        scanf("%s", palavra);
        if (strcmp(palavra, "SAIR")==0){
            return;
        }
        pesquisa(mat, palavra, l, c);
        for (int i=0; i<20; i++){ //limpa a palavra apos cada iteracao
            palavra[i]='\0';
        }
    }
}

int main(){
    int l, c, i;
    char **mat;
    printf("\nDigite o numero de linhas: ");
    scanf("%d", &l); //obter linhas
    printf("\nDigite o numero de colunas: ");
    scanf("%d", &c); //obter colunas

    mat= (char**)malloc(l * sizeof(char*)); //para alocar dinamicamente a matriz
    for (i= 0; i< l; i++){
        mat[i] = (char*)malloc(c * sizeof(char));
    }

    //funções que executam o trabalho
    elaboraMatriz(mat, l, c);
    recebeEntrada(mat, l, c);

    liberaMatriz(mat, l);//para desalocar a matriz

    return 0;
}
