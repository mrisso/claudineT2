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

void addPosicao (palavra *p, unsigned long pos)
{
	if(p->tam > 0)
		if(p->posicao[p->tam] == p->posicao[p->tam - 1])
			return;

	p->posicao[p->tam] = pos;
	p->tam++;
}

int *getPosicao (palavra *p)
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
	DefineAlfabeto(Alfabeto);   /* Le alfabeto definido em arquivo */
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
					//puts(Palavra);
					*Palavra = '\0';
					if(mode == MODE_HASH)
					{
						auxP = buscaHash((hash*)ed, Palavra);
						if(auxP != NULL)
							addPosicao(auxP, linha);
					}

					else if(mode == MODE_ARVBB)
					{

					}
					aux = FALSE;
				}
		}
	}

	if (aux) 
	{
		//puts(Palavra);
		*Palavra = '\0';
		if(mode == MODE_HASH)
		{
			auxP = buscaHash((hash*)ed, Palavra);
			if(auxP != NULL)
				addPosicao(auxP, linha);
		}
		else if(mode == MODE_ARVBB)
		{

		}
	}

	fclose(ArqTxt);
	fclose(ArqAlf);
}
