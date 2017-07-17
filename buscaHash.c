#include "hash.h"
#include "arvbb.h"

#include <stdio.h>
#define ERRO_NUMERO_DE_ARGUMENTOS  1

#define MAX_TAM_LINHA   1000000
#define MAX_TAM_PALAVRAS 20
#define MAX_TAM  2000

int comparPalavras(const void *p1, const void *p2) 
{ 
    const char **ip1 = (const char **)p1;
    const char **ip2 = (const char **)p2;
    return strcmp(*ip1, *ip2);
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
	char Palavra[MAX_TAM];
	char *tok;
	palavra *Palavras[MAX_TAM_PALAVRAS];

	FILE *arqPalavras = fopen(argv[2], "r");

	//Criando hash map
	hash *hashMap = criarHash(128);

	//Inicializando hash
	initHash(hashMap);
	int tamanho = 0;
	int nTok = 0;
	unsigned long vecIntersec[MAX_TAM_PALAVRAS], tamVec;

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

	printf("Digite as palavras que serao buscadas: ");
	gets(Palavra);
	for(tok = strtok(Palavra, " "); tok != NULL; tok = strtok(NULL, " "))
	{
		Palavras[nTok] = buscaHash(hashMap, tok);
		nTok++;
	}

	tamVec = devolveIntersec(Palavras, nTok, vecIntersec);

	//free na hash
	freeHash(hashMap); //consertar o free de palavra

    return 0;
}
