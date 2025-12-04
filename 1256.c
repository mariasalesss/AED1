#include <stdio.h>
#include <stdlib.h>

typedef struct no_lista {

	int valor;
	struct no_lista *proximo;

} no_lista;

typedef struct lista_encadeada {

	no_lista *primeiro;
	no_lista *ultimo;

} lista_encadeada;

void hash_inserir(lista_encadeada *, const int);
unsigned tamanho_hash;

void main ()
{

	unsigned num_casos;
	no_lista *cursor;
	int quantidade_chaves, i, chave_temp;

	scanf("%u", &num_casos);

	while (num_casos--)
	{

		scanf("%u %d", &tamanho_hash, &quantidade_chaves);

		lista_encadeada tabela[tamanho_hash];

		for (i = 0; i < tamanho_hash; ++i)
			tabela[i].primeiro = NULL, tabela[i].ultimo = NULL;

		for (i = 0; i < quantidade_chaves; ++i)
			scanf("%d", &chave_temp), hash_inserir(tabela, chave_temp);

		for (i = 0; i < tamanho_hash; ++i)
		{	
			printf("%d -> ", i);

			for (cursor = tabela[i].primeiro; cursor; cursor = cursor->proximo)
				printf("%d -> ", cursor->valor);

			printf("\\");
			printf("\n");

		}

		if (num_casos)
			printf("\n");

	}

}

void hash_inserir(lista_encadeada *tabela, const int chave)
{

	no_lista *novo;
	novo = (no_lista *) malloc(sizeof(no_lista));

	if (!novo)
		exit(1);

	int indice = chave % tamanho_hash;

	if (tabela[indice].primeiro)
		tabela[indice].ultimo->proximo = novo;
	else
		tabela[indice].primeiro = novo;

	tabela[indice].ultimo = novo;
	novo->proximo = NULL;
	novo->valor = chave;
	
}
