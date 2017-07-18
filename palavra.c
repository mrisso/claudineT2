//palavra.c

#include "palavra.h"
#include "hash.h"
#include "arvbb.h"

typedef short TipoAlfabeto[MAXALFABETO + 1];

FILE *ArqTxt, *ArqAlf;

TipoAlfabeto Alfabeto;

char Palavra[256];

char Linha[256];

unsigned long i;

short aux;


struct Palavra
{
	char *texto;
    unsigned long posicao[1000], tam;
};

palavra *criaPalavra (char *texto)
{
	palavra *new = malloc(sizeof(palavra));
	new->texto = malloc(strlen(texto) * sizeof(char));
	strcpy(new->texto, texto);
	new->tam = 0;

	return new;
}

void setTexto (palavra *p, char *texto)
{
	p->texto = texto;
}

char *getTexto (palavra *p)
{
	if(p != NULL)
		return p->texto;

	return NULL;
}

void addPosicao (palavra *p, unsigned long pos)
{
	if(p->tam > 0)
		if(p->posicao[p->tam] == p->posicao[p->tam - 1])
			return;

	p->posicao[p->tam] = pos;
	p->tam++;
}

unsigned long *getPosicao (palavra *p)
{
	return p->posicao;
}

void setTam (palavra *p, unsigned long tam)
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
	if(p1 == NULL)
		return 1;

	if(p2 == NULL)
		return -1;

	return strcmp(p1->texto, p2->texto);
}

void DefineAlfabeto(short *Alfabeto)
{
	char Simbolos[MAXALFABETO + 1];
	int i, CompSimbolos;
	char *TEMP;
	for (i = 0; i <= MAXALFABETO; i++)
		Alfabeto[i] = FALSE;
	fgets(Simbolos, MAXALFABETO + 1, ArqAlf);
	TEMP = strchr(Simbolos, '\n');
	if (TEMP != NULL) *TEMP = 0;
	CompSimbolos = strlen(Simbolos);
	for (i = 0; i < CompSimbolos; i++)
		Alfabeto[Simbolos[i]+127] = TRUE;
	Alfabeto[0] = FALSE;
}

void LePalavras (char *arquivoAlfabeto, char *arquivoTexto, int mode, void *ed)
{
	ArqTxt = fopen(arquivoTexto, "r");
	ArqAlf = fopen(arquivoAlfabeto, "r");
	DefineAlfabeto(Alfabeto);
	aux = FALSE;
	unsigned long linha = 0;
	palavra *auxP;
	while (fgets(Linha, 256, ArqTxt) != NULL) 
	{
		for (i = 1; i <= strlen(Linha); i++) 
		{
			if(i == 1)
				linha++;

			if (Alfabeto[Linha[i-1]+127]) 
			{
				sprintf(Palavra + strlen(Palavra), "%c", Linha[i-1]);
				aux = TRUE;
			}  
			else
				if (aux) 
				{
					if(mode == MODE_HASH)
					{
						auxP = buscaHash((hash*)ed, Palavra);
						if(auxP != NULL)
							addPosicao(auxP, linha);
					}

					else if(mode == MODE_ARVBB)
					{
						auxP = Pesquisa((Arvbb*)ed, Palavra);
						if(auxP != NULL)
							addPosicao(auxP, linha);
					}

					*Palavra = '\0';
					aux = FALSE;
				}
		}
	}

	if (aux) 
	{
		if(mode == MODE_HASH)
		{
			auxP = buscaHash((hash*)ed, Palavra);
			if(auxP != NULL)
				addPosicao(auxP, linha);
		}
		else if(mode == MODE_ARVBB)
		{
			auxP = Pesquisa((Arvbb *)ed, Palavra); if(auxP != NULL)
				addPosicao(auxP, linha);
		}
		*Palavra = '\0';
	}

	fclose(ArqTxt);
	fclose(ArqAlf);
}

void printPalavra (palavra *p)
{
	unsigned long i;

	if(p == NULL)
		return;

	printf("%s\t", p->texto);

	for(i = 0; i < p->tam; i++)
	{
		printf("%lu ", p->posicao[i]);
	}

	printf("\n");
}

unsigned long devolveIntersec (palavra **lPalavras, unsigned long tam, unsigned long *vecIntersec)
{
	unsigned long i, j, k;
	unsigned long verif = 0;
	unsigned long retorno = 0;

	palavra *aux = lPalavras[0];

	if(tam == 0)
		return 0;

	if(tam == 1)
	{
		for(i = 0; i < aux->tam; i++)
			vecIntersec[i] = aux->posicao[i];

		return aux->tam;
	}

	for (i = 0; i < aux->tam; i++)
	{
		for (j = 1; j < tam; j++)
		{
			for (k = 0; k < lPalavras[j]->tam; k++)
			{
				if(lPalavras[j]->posicao[k] > aux->posicao[i])
					break;

				else if(lPalavras[j]->posicao[k] == aux->posicao[i])
				{
					verif++;
					break;
				}
			}
		}

		if(verif == tam)
		{
			vecIntersec[retorno] = aux->posicao[i];
			retorno++;
		}
	}

	return retorno;
}

void printLinha (char *arquivo, unsigned long linha)
{
	FILE * arqTexto = fopen(arquivo, "r");
	rewind(arqTexto);
	char Linha[1000000];
	unsigned long i = 1;
	
	while (fgets(Linha, 1000000, arqTexto) != NULL)
	{
		Linha[strlen(Linha)-1] = '\0';
		if(i == linha)
		{
			printf("%lu\t%s\n",linha,Linha);
			break;
		}
		i++;
	}

	fclose(arqTexto);
}

unsigned long contaLinhas (char *arquivo)
{
	FILE * arqTexto = fopen(arquivo, "r");
	rewind(arqTexto);
	char Linha[256];
	unsigned long i = 0;
	
	while (fgets(Linha, 256, arqTexto) != NULL)
	{
		i++;
	}

	fclose(arqTexto);

	return i;
}

void freePalavra (palavra *p)
{
	free(p->texto);
	free(p);
}
