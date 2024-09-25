#ifndef pesquisa_h

#define pesquisa_h

int direcao(int x, int y, char *palavra, char **matriz, int tamMatriz);

int restantePalavra(int x, int y, char palavra[], char **matriz, int tamMatriz);

//faz a pesquisa
void pesquisa(char **matriz, char palavra[], int tamMatriz);

#endif
