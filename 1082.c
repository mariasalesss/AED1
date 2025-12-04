#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define verdadeiro 1
#define falso 0
#define TAM_MAX 35

_Bool visitado[TAM_MAX];
char adjacencia[TAM_MAX][TAM_MAX];
char lista_vertices[TAM_MAX];

int tamanho;
int qtd_vertices, qtd_arestas;

void dfs(int);
int comparar(char *, char *);

void main ()
{

	char vert_a, vert_b;
	int i, j, total_casos;
	int caso_atual = 0;

	scanf("%d", &total_casos);

	while (total_casos--)
	{

		scanf("%d %d", &qtd_vertices, &qtd_arestas);

		for (i = 0; i < qtd_arestas; ++i)
		{

			scanf(" %c %c", &vert_a, &vert_b);
			adjacencia[vert_a - 'a'][vert_b - 'a'] = 1;
			adjacencia[vert_b - 'a'][vert_a - 'a'] = 1;

		}
		
		printf("Case #%d:\n", ++caso_atual);
		int resposta = 0;

		for (i = 0; i < qtd_vertices; ++i)
		{

			if (!visitado[i])
			{

				++resposta, dfs(i);
				qsort(lista_vertices, tamanho, sizeof(char), comparar);

				for (j = 0; j < tamanho; ++j)
					printf("%c,", lista_vertices[j] + 'a');

				printf("\n");

			}

			tamanho = 0;

		}

		printf("%d connected components\n", resposta);
		printf("\n");

		memset(visitado, falso, sizeof(visitado));
		memset(adjacencia, 0, sizeof(adjacencia));

	}

}


void dfs(int u)
{

	int i;
	visitado[u] = verdadeiro;
	lista_vertices[tamanho++] = u;

	for (i = 0; i < qtd_vertices; ++i)
		if (adjacencia[u][i])
			if (!visitado[i])
				dfs(i);

}

int comparar(char *a, char *b)
{

	if (*a == *b)
		return 0;
	else if (*a > *b)
		return 1;
	else
		return -1;
		
}
