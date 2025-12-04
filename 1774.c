#include <stdio.h>
#include <stdlib.h>

#define verdadeiro 1
#define falso 0

typedef struct {

	int a, b, peso;

} aresta;

aresta grafo[250];
int pai[70];

int comparar(aresta *, aresta *);
int encontrar_componente(int);
int kruskal(int);

int main(int argc, char **argv)
{

	int total_vertices, total_arestas, i;
	scanf("%d %d", &total_vertices, &total_arestas);

	for (i = 0; i < total_arestas; ++i)
		scanf("%d %d %d", &grafo[i].a, &grafo[i].b, &grafo[i].peso);

	qsort(grafo, total_arestas, sizeof(aresta), comparar);

	for (i = 1; i <= total_vertices; ++i)
		pai[i] = i;

	printf("%d\n", kruskal(total_arestas));

	return 0;

}

int comparar(aresta *x, aresta *y)
{
	return x->peso - y->peso;
}

int encontrar_componente(int idx)
{

	if (idx == pai[idx])
		return idx;

	return encontrar_componente(pai[idx]);

}

int kruskal(int qtd)
{

	int i, resposta, v, u;

	for (i = 0, resposta = 0; i < qtd; ++i)
	{

		v = encontrar_componente(grafo[i].a);
		u = encontrar_componente(grafo[i].b);

		if (v != u)
			pai[v] = pai[u], resposta += grafo[i].peso;
			
	}

	return resposta;

}
