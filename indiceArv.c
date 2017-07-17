#include "hash.h"
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
	char *palavrasChave[MAX_TAM];

	FILE *arqPalavras = fopen(argv[2], "r");
	
	Arqbb * arqbb = malloc(sizeof(Arvbb));

	//Lendo palavras que serão pesquisadas e adicionando na hash
	while (fgets(Linha, 256, arqPalavras) != NULL)
	{
		Linha[strlen(Linha)-1] = '\0';
		addPalavraHash(hashMap, criaPalavra(Linha));
		palavrasChave[tamanho] = malloc((strlen(Linha) + 1) * sizeof(char));
		strcpy(palavrasChave[tamanho], Linha);
		tamanho++;
	}

	//Lendo as palavras e contando ocorrencias
	LePalavras("Alfabeto.txt", "Texto.txt", MODE_HASH, hashMap);

	//Printar ocorrencias
	int i;

	//qsort(palavrasChave, tamanho, sizeof(char *), comparPalavras);
	for (i = 0; i < tamanho; i++)
	{
		printPalavra(buscaHash(hashMap, palavrasChave[i]));
	}

	//free na hash
	freeHash(hashMap); //consertar o free de palavra

    return 0;
}
