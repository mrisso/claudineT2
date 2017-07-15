// hash.h

#ifndef HASH_H
#define HASH_H

#define COEFICIENTE_HASH               0.75

#include <stdlib.h>

#include "palavra.h"

typedef struct Celula celula;

typedef struct Hash hash;

hash *criarHash (int tamanho);

void initHash (hash *h);

void addPalavraHash (hash *h, palavra *p);

#endif
