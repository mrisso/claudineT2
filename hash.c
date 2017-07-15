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
	unsigned long tamanhoRelativo;
	unsigned long tamanhoReal;
	unsigned long n;
	celula **tabela;
};

hash *criarHash (int tamanho)
{
	hash *h = malloc(sizeof(hash));

	h->tabela = malloc(tamanho * sizeof(celula*));
	h->tamanho = tamanho;
	h->tamanhoRelativo = tamanho;
	h->tamanhoReal = tamanho;
	h->n = 0;
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
	unsigned long hash = 5381;
	char *texto = getTexto(p);
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
	if(indice > h->tamanhoReal)
		return NULL;

	celula *aux = h->tabela[indice];

	if(aux==NULL)
		return NULL;
	
	h->tabela[indice] = aux->prox;

	return aux->palavra;
}


void hashTamHandler (hash *h)
{
	palavra *auxP = NULL;

	// Preparar a hash para a adição de um nvo elemento
	if(((float)h->nElementos + 1)/(float)h->tamanho > COEFICIENTE_HASH)
	{
		if(h->n == 0)
		{
			h->tamanho *= 2;
		}

	    h->n++;
		h->tabela = realloc(h->tabela, (h->tamanhoRelativo + h->n) * sizeof(celula*));
		h->tamanhoReal++;
		
		if(h->tabela[h->n -1] != NULL)
		{
			auxP = hashRetiraPalavra(h, (hFun(h->tabela[h->n - 1]->palavra) % h->tamanhoRelativo));
			while(1)
			{
				addAux(h, auxP, hFun(auxP) % h->tamanho);
				if(hFun(auxP)%h->tamanho == hFun(auxP)%h->tamanhoRelativo)
					break;
				if(h->tabela[h->n -1] == NULL)
					break;
				auxP = hashRetiraPalavra(h, (hFun(h->tabela[h->n - 1]->palavra) % h->tamanhoRelativo));
			}
		}

		if(h->tamanho == h->tamanhoReal)
		{
			h->n = 0;
			h->tamanhoRelativo = h->tamanho;
		}
	}
}
	
void addPalavraHash (hash *h, palavra *p)
{
	//Chama o handler para alocar mais espaço se necessário
	hashTamHandler(h);

	unsigned long pos = hFun(p) % h->tamanhoRelativo;

	if(pos < h->n)
	{
		pos = hFun(p) % h->tamanho;
	}

	printf("Tamanho: %lu\n", h->tamanho);
	printf("Tamanho Relativo: %lu\n", h->tamanhoRelativo);
	printf("Tamanho Real: %lu\n", h->tamanhoReal);
	printf("n: %lu\n", h->n);
	printf("\n");
	
	addAux(h, p, pos);
}
