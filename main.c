#include "hash.h"
#include "arvbb.h"

#include <stdio.h>

int main(void)
{
	hash *hashMap = criarHash(4);

	initHash(hashMap);
	int i;

	//Adicionando palavras que serão pesquisadas
	char *palavras[8] = {"and","be","by","easy","human-engineered","programming","programs","to"};

	for(i = 0; i < 8; i++)
	{
		if(i != 1)
			addPalavraHash(hashMap,criaPalavra(palavras[i])); 
	}

	addPalavraHash(hashMap, criaPalavra(palavras[1]));

	LePalavras("Alfabeto.txt", "teste.txt", MODE_HASH, hashMap);

	for(i = 0; i < 8; i++)
	{
		printPalavra(buscaHash(hashMap, palavras[i]));
	}

    return 0;
}
