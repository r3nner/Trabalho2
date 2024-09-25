#ifndef pesquisa_h

#define pesquisa_h

int direcao(int x, int y, char *palavra, char **matriz, int l, int c);

int restantePalavra(int x, int y, char palavra[], char **matriz, int l, int c);

//faz a pesquisa
void pesquisa(char **matriz, char palavra[], int l, int c);

#endif
