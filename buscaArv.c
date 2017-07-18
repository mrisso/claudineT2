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
	char Palavra[MAX_TAM];
	char *tok;
	palavra *Palavras[MAX_TAM_PALAVRAS];

	FILE *arqPalavras = fopen(argv[2], "r");

	//Criando árvore
	Arvbb *arvbb = inicializaArvbb();

	int nTok = 0;
	unsigned long vecIntersec[MAX_TAM_PALAVRAS], tamVec, i;

	//Lendo palavras que serão pesquisadas e adicionando na árvore
	while (fgets(Linha, 1000000, arqPalavras) != NULL)
	{
		Linha[strlen(Linha)-1] = '\0';
		arvbb = Insere_arvbb(arvbb, criaPalavra(Linha));
	}

	//Lendo as palavras e contando ocorrencias
	LePalavras("Alfabeto.txt", "Texto.txt", MODE_ARVBB, arvbb);

	printf("Digite as palavras que serao buscadas: ");
	gets(Palavra);
	for(tok = strtok(Palavra, " "); tok != NULL; tok = strtok(NULL, " "))
	{
		Palavras[nTok] = Pesquisa(arvbb, tok);
		nTok++;
	}

	tamVec = devolveIntersec(Palavras, nTok, vecIntersec);

	if(tamVec == 0)
		printf("Não encontrado.\n");

	for (i = 0; i < tamVec; i++)
	{
		printLinha(argv[1], vecIntersec[i]);
	}

	freeAllArvbb(arvbb);

    return 0;
}
