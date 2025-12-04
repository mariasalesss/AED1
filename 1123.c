#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define INF 100000
#define TAM_MAX 101010

int visitado[TAM_MAX];
int distancia[TAM_MAX];

typedef struct _no {

    int destino, peso;
    struct _no *prox;

} no_t;

typedef struct _grafo {

    no_t *lista_adj;

} grafo_t;

grafo_t *criar_grafo(int);
no_t *criar_no(int, int);
void dijkstra(grafo_t *, int, int);
void inserir(grafo_t *, int, int, int);

int main(int argc, char **argv)
{    
    int i;
    int n, m, c, k, a, b, peso;

    while (scanf("%d %d %d %d", &n, &m, &c, &k), (c && n && m && k))
    {    
        grafo_t *grafo = criar_grafo(n + 1);

        for (i = 0; i < m; ++i)
        {
            scanf("%d %d %d", &a, &b, &peso);

            if ( (a >= c && b >= c) || (a < c && b < c && abs(a - b) == 1) )
                inserir(grafo, a, b, peso), inserir(grafo, b, a, peso);

            if (a >= c && b < c)
                inserir(grafo, b, a, peso);

            if (b >= c && a < c)
                inserir(grafo, a, b, peso);
        }

        dijkstra(grafo, k, n);
        printf("%d\n", distancia[c - 1]);
    }

    return 0;
}

void dijkstra(grafo_t *g, int origem, int tamanho)
{
    no_t *ptr;
    int i, j, v;

    for (i = 0; i < tamanho; ++i)
        distancia[i] = INF;

    memset(visitado, false, sizeof(visitado));

    distancia[origem] = 0;

    for (i = 0; i < tamanho; ++i)
    {
        v = -1;

        for (j = 0; j < tamanho; ++j)
            if (!visitado[j] && (v == -1 || distancia[j] < distancia[v]))
                v = j;

        if (distancia[v] == INF)
            break;

        visitado[v] = true;

        for (ptr = g->lista_adj[v].prox; ptr != NULL; ptr = ptr->prox)
        {
            int destino = ptr->destino;
            int peso = ptr->peso;

            if (distancia[v] + peso < distancia[destino])
                distancia[destino] = distancia[v] + peso;
        }
    }
}

grafo_t *criar_grafo(int tamanho)
{
    int i;
    grafo_t *g = (grafo_t *) malloc(sizeof(grafo_t));
    g->lista_adj = (no_t *) malloc(sizeof(no_t) * (tamanho + 1));

    for (i = 0; i < tamanho; ++i)
        g->lista_adj[i].prox = NULL;

    return g;
}

no_t *criar_no(int destino, int peso)
{
    no_t *novo = (no_t *) malloc(sizeof(no_t));

    novo->destino = destino;
    novo->peso = peso;
    novo->prox = NULL;

    return novo;
}

void inserir(grafo_t *g, int destino, int origem, int peso)
{
    no_t *novo = criar_no(destino, peso);
    novo->prox = g->lista_adj[origem].prox;
    g->lista_adj[origem].prox = novo;
}
