#include <stdio.h>
#include <stdlib.h>
#include "arvbb.h"
#include "palavra.h"

struct arvbb{
	palavra * palavra;
	Arvbb * pai;
	Arvbb * esq;
	Arvbb * dir;
};

Arvbb * Inicializa(palavra * chave){
	Arvbb * no = malloc(sizeof(Arvbb));
	no->pai=NULL;
	no->esq=NULL;
	no->dir=NULL;
	no->palavra=chave;

	return no;
}

void Percorre(Arvbb * raiz){
	if(raiz != NULL){
		Percorre(raiz->esq);
		//utiliza a chave.
		printPalavra(raiz->palavra);
		Percorre(raiz->dir);
	}
}

palavra * Pesquisa(Arvbb * raiz, char * chave){
	Arvbb * aux = raiz;
	while(raiz != NULL && chave != getTexto(raiz->palavra))
	{
		if(compareStrPalavra(chave,(raiz->palavra)))
			aux = aux->dir;
		else
			aux = aux->esq;
	}
	return aux->palavra;
}

Arvbb * Insere_arvbb(Arvbb * raiz, palavra * novo){
	if(raiz==NULL)
		return Inicializa(novo);
	if(compareStrPalavra(getTexto(raiz->palavra),novo))
		raiz->esq = Insere_arvbb(raiz->esq,novo);
	else if (compareStrPalavra(getTexto(novo),raiz->palavra))
		raiz->dir = Insere_arvbb(raiz->dir,novo);
	return raiz;
}

Arvbb * Max_arvbb(Arvbb * raiz){//Função que encontra o maximo na arvore, indo sempre pra direita
	Arvbb * aux = raiz;
	while(raiz->dir != NULL)
	{
		aux = raiz->dir;
	}
	return aux;
}

Arvbb * Min_arvbb(Arvbb * raiz){//Função que encontra o minimo na arvore, indo sempre pra esquerda
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
	Arvbb *new = malloc(sizeof(Arvbb));

	new->pai = NULL;
	new->dir = NULL;
	new->esq = NULL;
	new->palavra = NULL;

	return new;
}
