#include "arvbb.h"

#include <stdio.h>

#define ERRO_NUMERO_DE_ARGUMENTOS  1

#define MAX_TAM_LINHA   1000000
#define MAX_TAM  2500

int comparPalavras (const void *p1, const void *p2)
{
	return strcmp((char *)p1, (char *)p2);
}

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Uso: %s <arquivo-de-texto> <arquivo-de-palavras-chave>\n", argv[0]);
		return ERRO_NUMERO_DE_ARGUMENTOS;
	}

	char Linha[MAX_TAM_LINHA];

	FILE *arqPalavras = fopen(argv[2], "r");
	
	Arvbb * arvbb = inicializaArvbb();

	//Lendo palavras que serão pesquisadas e adicionando na arvore
	while (fgets(Linha, 256, arqPalavras) != NULL)
	{
		Linha[strlen(Linha)-1] = '\0';
		arvbb = Insere_arvbb(arvbb, criaPalavra(Linha));
	}

	//Lendo as palavras e contando ocorrencias
	LePalavras("Alfabeto.txt", "Texto.txt", MODE_ARVBB, arvbb);

	//Imprimindo índice remissivo
	Percorre(arvbb, imprimirRaiz);

	freeAllArvbb(arvbb);

    return 0;
}
