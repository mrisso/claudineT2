#include <stdio.h>
#include <stdlib.h>
#include "arvbb.h"
#include "palavra.h"

struct arvbb{
	Palavra * palavra;
	Arvbb * esq;
	Arvbb * dir;
};

Arvbb * inicializa_arvbb(Palavra * palavra, Arvbb * noesquerdo, Arvbb * nodireito){
	Arvbb * arvbb = malloc(sizeof(Arvbb));
	arvbb->palavra = palavra;
	arvbb->esq = noesquerdo;
	arvbb->dir = nodireito;

	return arvbb;
}


