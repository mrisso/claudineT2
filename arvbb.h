#ifndef ARVBB_H_INCLUDED
#define ARVBB_H_INCLUDED
#include "palavra.h"
typedef struct arvbb Arvbb;

Arvbb * Inicializa(palavra * chave);

void Percorre(Arvbb * raiz);

Arvbb * Pesquisa(Arvbb * raiz, char * chave);

Arvbb * Insere_arvbb();

Arvbb * Max_arvbb(Arvbb * raiz);

Arvbb * Max_arvbb(Arvbb * raiz);

#endif // ARVBB_H_INCLUDED
