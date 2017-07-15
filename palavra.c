//palavra.c

#include "palavra.h"

struct Palavra
{
	char *texto;
    int posicao[100], tam;
};

void setTexto (palavra *p, char *texto)
{
	p->texto = texto;
}

char *getTexto (palavra *p)
{
	return p->texto;
}

void addPosicao (palavra *p, int pos)
{
	p->posicao[p->tam] = pos;
	p->tam++;
}

int *getPosicao (palavra *p)
{
	return p->posicao;
}

void setTam (palavra *p, int tam)
{
	p->tam = tam;
}

int getTam (palavra *p)
{
	return p->tam;
}

void incrementTam (palavra *p)
{
	p->tam++;
}

int compareStrPalavra (char *str, palavra *p)
{
	return strcmp(str, p->texto);
}
