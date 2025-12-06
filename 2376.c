#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef struct No{

	char time;
	struct No *proximo;

} No;

typedef struct Fila{

	No *primeiro;
	No *ultimo;

} Fila;

void inicializarFila(Fila *fila);
void inserir(Fila *fila, char time);
_Bool remover(Fila *fila, char *retorno);

int main()
{

	int golsA, golsB;
	Fila fila;
	char i, timeA, timeB, retorno;

	inicializarFila(&fila);

	// Insere times de A até P
	for (i = 'A'; i <= 'P'; ++i)
		inserir(&fila, i);

	// 15 partidas da copa
	for (i = 0; i < 15; ++i)
	{

		remover(&fila, &retorno);
		timeA = retorno;

		remover(&fila, &retorno);
		timeB = retorno;

		scanf("%d %d", &golsA, &golsB);

		if (golsA > golsB)
			inserir(&fila, timeA);
		else
			inserir(&fila, timeB);
	}

	remover(&fila, &retorno);
	printf("%c\n", retorno);

	return 0;
}

void inicializarFila(Fila *fila)
{
	fila->primeiro = NULL;
	fila->ultimo = NULL;
}

void inserir(Fila *fila, char time)
{

	No *novoNo;

	novoNo = (No *) malloc(sizeof(No));

	if (!novoNo)
		exit(1);

	if (fila->primeiro)
	{
		fila->ultimo->proximo = novoNo;
		novoNo->proximo = NULL;
	}
	else
		fila->primeiro = novoNo;

	fila->ultimo = novoNo;
	novoNo->time = time;
}

_Bool remover(Fila *fila, char *retorno)
{
	No *auxiliar;

	if (fila->primeiro)
	{

		if (fila->primeiro->proximo)
		{
			*retorno = fila->primeiro->time;
			auxiliar = fila->primeiro;
			fila->primeiro = fila->primeiro->proximo;
			free(auxiliar);
			return true;
		}
		else
		{
			*retorno = fila->primeiro->time;
			auxiliar = fila->primeiro;
			fila->primeiro = fila->ultimo = NULL;
			free(auxiliar);
			return true;
		}

	}
	else
	{
		retorno = NULL;
		return false;
	}
}
