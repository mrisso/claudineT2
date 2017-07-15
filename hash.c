//hash.c

#include "hash.h"
#include <string.h>

struct Celula
{
	palavra *palavra;
	struct Celula *prox;
};

struct Hash
{
	int tamanho;
	int nElementos;
	celula **tabela;
};

hash *criarHash (int tamanho)
{
	hash *h = malloc(sizeof(hash));

	h->tabela = malloc(tamanho * sizeof(celula**));
	h->tamanho = tamanho;
	h->nElementos = 0;

	return h;
}

void initHash (hash *h)
{
	int i;

	for (i = 0; i < h->tamanho; i++)
	{
		h->tabela[i] = NULL;
	}
}

unsigned long hFun (palavra *p)
{
	unsigned long hash = 5381;
	char *texto = getTexto(p);
	int c;

	while ((c = *texto++))
		hash = ((hash << 5) + hash) + c;

	return hash;
}

void addPalavraHash (hash *h, palavra *p)
{
	unsigned long pos = hFun(p);
	celula *andador = NULL;

	if(h->tabela[pos] == NULL)
	{
		h->tabela[pos] = malloc(sizeof(celula));
		h->tabela[pos]->palavra = p;
		h->tabela[pos]->prox = NULL;
	}

	else
	{
		for (andador = h->tabela[pos]->prox; andador != NULL; andador = andador->prox)
		{
			if(andador->prox == NULL)
			{
				andador->prox = malloc(sizeof(celula));
				andador->prox->palavra = p;
				andador->prox->prox = NULL;

				break;
			}
		}
	}
}
