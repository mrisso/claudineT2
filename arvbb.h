#ifndef ARVBB_H_INCLUDED
#define ARVBB_H_INCLUDED
#include "palavra.h"
typedef struct arvbb Arvbb;

Arvbb * Inicializa(palavra * chave);

void Percorre(Arvbb * raiz);

palavra * Pesquisa(Arvbb * raiz, char * chave);

Arvbb * Insere_arvbb();

Arvbb * Max_arvbb(Arvbb * raiz);

Arvbb * Max_arvbb(Arvbb * raiz);

size_t sizeOfArv();

Arvbb *inicializaArvbb();

#endif // ARVBB_H_INCLUDED
