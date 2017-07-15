//palavra.c

#include "palavra.h"

struct Palavra
{
	char *texto;
    int posicao[100], tam;
};

palavra *criaPalavra (char *texto)
{
	palavra *new = malloc(sizeof(palavra));
	new->texto = texto;
	new->tam = 0;

	return new;
}

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

int comparePalavras (palavra *p1, palavra *p2)
{
	return strcmp(p1->texto, p2->texto);
}
