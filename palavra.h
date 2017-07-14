// palavra.h

#ifndef PALAVRA_H
#define PALAVRA_H

typedef struct Palavra palavra;

void setTexto (palavra *p, char *texto);

char *getTexto (palavra *p);

void addPosicao (palavra *p, int pos);

int *getPosicao (palavra *p);

void setTam (palavra *p, int tam);

int getTam (palavra *p);
   
#endif
