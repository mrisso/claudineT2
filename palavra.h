// palavra.h

#ifndef PALAVRA_H
#define PALAVRA_H

#include <stdlib.h>
#include <string.h>

typedef struct Palavra palavra;

palavra *criaPalavra (char *texto);

void setTexto (palavra *p, char *texto);

char *getTexto (palavra *p);

void addPosicao (palavra *p, int pos);

int *getPosicao (palavra *p);

void setTam (palavra *p, int tam);

void incrementTam (palavra *p);

int getTam (palavra *p);

int compareStrPalavra (char *str, palavra *p);

int comparePalavras (palavra *p1, palavra *p2);
   
#endif
