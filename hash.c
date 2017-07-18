//hash.c

#include "hash.h"
#include <string.h>
#include <stdio.h>

struct Celula
{
	palavra *palavra;
	struct Celula *prox;
};

struct Hash
{
	unsigned long tamanho;
	unsigned long nElementos;
	celula **tabela;
};

hash *criarHash (int tamanho)
{
	hash *h = malloc(sizeof(hash));

	h->tabela = malloc(tamanho * sizeof(celula*));
	h->tamanho = tamanho;
	h->nElementos = 0;

	return h;
}

void initHash (hash *h)
{
	unsigned long i;

	for (i = 0; i < h->tamanho; i++)
	{
		h->tabela[i] = NULL;
	}
}

unsigned long hFun (palavra *p)
{
	if(p!=NULL)
	{
		unsigned long hash = 5381;
		char *texto = getTexto(p);
		int c;

		while ((c = *texto++))
			hash = ((hash << 5) + hash) + c;

		return hash;
	}

	return 0;
}

unsigned long hFunTexto (char *texto)
{
	unsigned long hash = 5381;
	int c;

	while ((c = *texto++))
		hash = ((hash << 5) + hash) + c;

	return hash;
}

void addAux (hash *h, palavra *p, unsigned long indice)
{
	celula *andador = NULL;

	if(h->tabela[indice] == NULL)
	{
		h->tabela[indice] = malloc(sizeof(celula));
		h->tabela[indice]->palavra = p;
		h->tabela[indice]->prox = NULL;
		h->nElementos++;
	}

	else
	{
		for (andador = h->tabela[indice]; andador != NULL; andador = andador->prox)
		{
			// Se igual, não adicione
			if(comparePalavras(andador->palavra, p) == 0)
				break;

			if(andador->prox == NULL)
			{
				andador->prox = malloc(sizeof(celula));
				andador->prox->palavra = p;
				andador->prox->prox = NULL;
				h->nElementos++;

				break;
			}
		}
	}
}


palavra *hashRetiraPalavra(hash *h, unsigned long indice)
{
	if(indice >= h->tamanho)
		return NULL;

	celula *aux = h->tabela[indice];

	if(aux==NULL)
		return NULL;
	
	h->tabela[indice] = aux->prox;

	return aux->palavra;
}


	
void addPalavraHash (hash *h, palavra *p)
{
	unsigned long pos = hFun(p) % h->tamanho;

	addAux(h, p, pos);
}

palavra *buscaHash(hash *h, char *texto)
{
	unsigned long pos = hFunTexto(texto) % h->tamanho;
	celula *andador = NULL;

	if(h->tabela[pos] == NULL)
		return NULL;

	else
	{
		for (andador = h->tabela[pos]; andador != NULL; andador = andador->prox)
		{
			if(compareStrPalavra(texto, andador->palavra) == 0)
				return andador->palavra;
		}
	}

	return NULL;
}

void freeHash (hash *h)
{
	unsigned long i;

	for (i = 0; i < h->tamanho; i++)
	{
		celula *andador;
		celula *aux;

		for (andador = h->tabela[i]; andador != NULL; andador = aux)
		{
			aux = andador->prox;
			freePalavra(andador->palavra);
			free(andador);
		}
	}

	free(h->tabela);
}
