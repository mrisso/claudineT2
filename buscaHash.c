#include "hash.h"

#include <stdio.h>
#define ERRO_NUMERO_DE_ARGUMENTOS  1

#define MAX_TAM_LINHA   1000000
#define MAX_TAM_PALAVRAS 20
#define MAX_TAM  2000

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Uso: %s <arquivo-de-texto> <arquivo-de-palavras-chave>\n", argv[0]);
		return ERRO_NUMERO_DE_ARGUMENTOS;
	}

	char Linha[MAX_TAM_LINHA];
	char Palavra[MAX_TAM];
	char *tok;
	palavra *Palavras[MAX_TAM_PALAVRAS];

	FILE *arqPalavras = fopen(argv[2], "r");

	//Criando hash map
	const unsigned long tamHash = 1.33 * contaLinhas(argv[2]);
	hash *hashMap = criarHash(tamHash);

	int nTok = 0;
	int indice = 0;
	unsigned long vecIntersec[MAX_TAM_PALAVRAS], tamVec, i;

	//Lendo palavras que serão pesquisadas e adicionando na árvore
	while (fgets(Linha, 1000000, arqPalavras) != NULL)
	{
		Linha[strlen(Linha)-1] = '\0';
		addPalavraHash(hashMap, criaPalavra(Linha));
	}

	//Lendo as palavras e contando ocorrencias
	LePalavras("Alfabeto.txt", "Texto.txt", MODE_HASH, hashMap);

	printf("Digite as palavras que serao buscadas: ");
	gets(Palavra);
	for(tok = strtok(Palavra, " "); tok != NULL; tok = strtok(NULL, " "))
	{
		Palavras[indice] = buscaHash(hashMap, tok);
		if(Palavras[indice] != NULL)
			indice++;
		nTok++;
	}

	tamVec = devolveIntersec(Palavras, indice, nTok, vecIntersec);

	if(tamVec == 0)
		printf("Não encontrado.\n");

	for (i = 0; i < tamVec; i++)
	{
		printLinha(argv[1], vecIntersec[i]);
	}

	freeHash(hashMap);
    return 0;
}
