//hash.c

#include "hash.h"
#include <string.h>

struct Celula
{
	palavra *palavra;
	struct Celula *prox;
};

hash criarHash (int tamanho)
{
	hash h = malloc(tamanho * sizeof(hash));

	return h;
}

void initHash (hash h, int tam)
{
	int i;

	for (i = 0; i < tam; i++)
	{
		h[i] = NULL;
	}
}

unsigned long hFun (palavra *p, int tam)
{
	unsigned long hash = 5381;
	char *texto = getTexto(p);
	int c;

	while ((c = *texto++))
		hash = ((hash << 5) + hash) + c;

	return hash % tam;
}

void addPalavraHash (hash h, palavra *p, int tam)
{
	unsigned long pos = hFun(p, tam);
	celula *andador = NULL;

	if(h[pos] == NULL)
	{
		h[pos] = malloc(sizeof(celula));
		h[pos]->palavra = p;
		h[pos]->prox = NULL;
	}

	else
	{
		for (andador = h[pos]->prox; andador != NULL; andador = andador->prox)
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
