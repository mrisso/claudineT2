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

void Percorre(Arvbb * raiz){
	if(raiz != NULL){
		Percorre(raiz->esq);
		//utiliza a chave.
		printf("%s" , getTexto(raiz->palavra));
		Percorre(raiz->dir);
	}
}

Arvbb * Pesquisa(Arvbb * raiz, char * chave){
	Arvbb * aux = raiz;
	while(raiz != NULL && chave != getTexto(raiz->palavra))
	{
		if(compareStrPalavra(chave,(raiz->palavra)))
			aux = aux->dir;
		else
			aux = aux->esq;
	}
	return aux;
}

void Insere_arvbb(){
}

Arvbb * Max_arvbb(){
return NULL;
}

Arvbb * Min_arvbb(){
return NULL;
}

