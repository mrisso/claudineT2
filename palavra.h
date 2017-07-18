// palavra.h

#ifndef PALAVRA_H
#define PALAVRA_H

#define MAXALFABETO 255
#define TRUE  1
#define FALSE 0
#define MODE_ARVBB  1
#define MODE_HASH   2

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct Palavra palavra;

palavra *criaPalavra (char *texto);

void setTexto (palavra *p, char *texto);

char *getTexto (palavra *p);

void addPosicao (palavra *p, unsigned long pos);

unsigned long *getPosicao (palavra *p);

void setTam (palavra *p, unsigned long tam);

void incrementTam (palavra *p);

int getTam (palavra *p);

int compareStrPalavra (char *str, palavra *p);

int comparePalavras (palavra *p1, palavra *p2);

void LePalavras (char *arquivoAlfabeto, char *arquivoTexto, int mode, void *ed);

void printPalavra (palavra *p);

unsigned long devolveIntersec (palavra **lPalavras, unsigned long tam, unsigned long *vecIntersec);

void printLinha (char *arquivo, unsigned long linha);

unsigned long contaLinhas (char *arquivo);

void freePalavra (palavra *p);

#endif
