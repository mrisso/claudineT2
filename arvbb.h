#ifndef ARVBB_H_INCLUDED
#define ARVBB_H_INCLUDED
#include "palavra.h"
typedef struct arvbb Arvbb;

Arvbb * Inicializa(palavra * chave);

void imprimirRaiz (Arvbb *raiz);

void Percorre(Arvbb * raiz, void (*acao) (Arvbb *));

palavra * Pesquisa(Arvbb * raiz, char * chave);

Arvbb * Insere_arvbb(Arvbb * raiz, palavra * novo);

Arvbb * Max_arvbb(Arvbb * raiz);

Arvbb * Max_arvbb(Arvbb * raiz);

size_t sizeOfArv();

Arvbb *inicializaArvbb();

void freeArvbb (Arvbb *arvbb);

void freeAllArvbb (Arvbb *raiz);

#endif // ARVBB_H_INCLUDED
