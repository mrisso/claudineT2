// hash.h

#ifndef HASH_H
#define HASH_H

#include <stdlib.h>

#include "palavra.h"

typedef struct Celula celula;
typedef celula** hash;

hash criarHash (int tamanho);

void initHash (hash h, int tam);

#endif
