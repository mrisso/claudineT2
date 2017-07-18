#include <stdio.h>
#include <stdlib.h>
#include "arvbb.h"
#include "palavra.h"

struct arvbb
{
	palavra * palavra;
	Arvbb * pai;
	Arvbb * esq;
	Arvbb * dir;
};

Arvbb * Inicializa(palavra * chave)
{
	Arvbb * no = malloc(sizeof(Arvbb));
	no->pai=NULL;
	no->esq=NULL;
	no->dir=NULL;
	no->palavra=chave;

	return no;
}

void imprimirRaiz (Arvbb *raiz)
{
	printPalavra(raiz->palavra);
}

void Percorre(Arvbb * raiz, void (*acao) (Arvbb *))
{
	if(raiz != NULL)
	{
		Percorre(raiz->dir, acao);
		//utiliza a chave.
		acao(raiz);
		Percorre(raiz->esq, acao);
	}
}

palavra * Pesquisa(Arvbb * raiz, char * chave)
{
	Arvbb * aux = raiz;
	while(aux != NULL && chave != getTexto(aux->palavra))
	{
		if(compareStrPalavra(chave,(aux->palavra)) == 0)
			return aux->palavra;

		else if(compareStrPalavra(chave,(aux->palavra)))
			aux = aux->esq;

		else
			aux = aux->dir;
	}

	return NULL;
}

Arvbb * Insere_arvbb(Arvbb * raiz, palavra * novo)
{
	if(raiz==NULL)
		return Inicializa(novo);
	if(compareStrPalavra(getTexto(raiz->palavra),novo))
		raiz->esq = Insere_arvbb(raiz->esq,novo);
	else if (compareStrPalavra(getTexto(novo),raiz->palavra))
		raiz->dir = Insere_arvbb(raiz->dir,novo);
	return raiz;
}

Arvbb * Max_arvbb(Arvbb * raiz) //Função que encontra o maximo na arvore, indo sempre pra direita
{
	Arvbb * aux = raiz;
	while(raiz->dir != NULL)
	{
		aux = raiz->dir;
	}
	return aux;
}

Arvbb * Min_arvbb(Arvbb * raiz) //Função que encontra o minimo na arvore, indo sempre pra esquerda
{
	Arvbb * aux = raiz;
	while(raiz->esq != NULL)
	{
		aux = raiz->esq;
	}
	return aux;
}

size_t sizeOfArv()
{
	return sizeof(Arvbb);
}

Arvbb *inicializaArvbb()
{
	return NULL;
}

void freeArvbb (Arvbb *arvbb)
{
	freePalavra(arvbb->palavra);
	free(arvbb);
}

void freeAllArvbb (Arvbb *raiz)
{
	Percorre(raiz, freeArvbb);
}
