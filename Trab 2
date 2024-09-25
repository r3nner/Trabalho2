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

void elaboraMatriz(char **mat,int linhas,int colunas){
    int i=0, j=0, tam;
    char *string;
    char *novastring;
    string=(char*)malloc(linhas*colunas*sizeof(char)+1);
    novastring=(char*)malloc(linhas*colunas*sizeof(char)+1);
    if (novastring==NULL){
        printf("\n\nERRO\N\N");
    }
    for (i=0; i<linhas*colunas; i++){
        novastring[i]='\0';
    }
    printf("\nEscreva um texto para completar a matriz: ");
    scanf(" %[^\n]s", string);
    printf("\n\n%s\n\n", string);
    i=0;
    while (string[i]!='\0'){ //tira espaço em branco
        if (string[i]==' '){
            i++;
        }
        else{
            novastring[j]=string[i];
            j++;
            i++;
        }
    }
    novastring[j]='\0';
    //free(string);
    printf("\n\n%s\n\n", novastring);
    converteStringMatriz(mat, novastring, linhas, colunas);
    printaMatriz(mat, novastring, linhas, colunas);
    //free(novastring);
}

void printaMatriz(char **mat, char *string, int linha, int coluna){
    int i, j, cont, tam;
    cont=0;
    tam= strlen(string);
    printf("    ");
    for (int k=0; k<coluna; k++){ //numero da coluna
        printf(" %d ", k+1);
    }
    printf("\n");
    for(i=0; i<linha; i++){
        printf(" %d  ", i+1);
        for (j=0; j<coluna; j++){
            if (cont>=tam){
                mat[i][j]='\0';
            }
            printf(" %c ", mat[i][j]);
            cont++;
        }
        printf("\n");
    }
}

void recebeEntrada(char **mat, int l, int c){
    char palavra[20];
    do{
        printf("\nEscreva a palavra que deseja procurar ou escreva SAIR para sair:");
        scanf("%s", palavra);
        if (!(strcmp(palavra, "SAIR"))){
            exit(1);
        }
        pesquisa(mat, palavra, l, c);
    } while (palavra!="1");
}

int main()
{
    int l, c, i;
    char **mat;
    printf("\nDigite o numero de linhas:");
    scanf("%d", &l);
    printf("\nDigite o numero de colunas:");
    scanf("%d", &c);
    mat=(char**)malloc(l*sizeof(char*));
    for (i=0; i<l; i++){
        mat[i]=(char*)malloc(c*sizeof(char));
    }
    elaboraMatriz(mat, l, c);

    recebeEntrada(mat, l, c);
    return 0;
}
