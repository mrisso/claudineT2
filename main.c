#include "hash.h"
#include "arvbb.h"

#include <stdio.h>

int main(void)
{
	palavra *p = criaPalavra("aleatorio");
	hash *hashMap = criarHash(4);

	addPalavraHash(hashMap, p);
	p = criaPalavra("géépeto");
	addPalavraHash(hashMap, p);
	p = criaPalavra("gerundismo");
	addPalavraHash(hashMap, p);
	p = criaPalavra("claudia");
	addPalavraHash(hashMap, p);
	p = criaPalavra("simbionte");
	addPalavraHash(hashMap, p);
	p = criaPalavra("amigos");
	addPalavraHash(hashMap, p);
	p = criaPalavra("clientela");
	addPalavraHash(hashMap, p);
	p = criaPalavra("josias");
	addPalavraHash(hashMap, p);
	p = criaPalavra("claudinha");
	addPalavraHash(hashMap, p);
	p = criaPalavra("bochecho");
	addPalavraHash(hashMap, p);
	p = criaPalavra("dedinho");
	addPalavraHash(hashMap, p);
	p = criaPalavra("bochecho");
	addPalavraHash(hashMap, p);

    return 0;
}
