#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define TAM_MAX 1010
#define TAM_MAX_ARESTAS (((TAM_MAX) * (TAM_MAX - 1)) >> 1)

typedef struct aresta
{
    int u, v, w;
} aresta_t;

int pai[TAM_MAX];
int tamanho[TAM_MAX];
aresta_t arestas[TAM_MAX_ARESTAS];
bool visitado[TAM_MAX];
int adj[TAM_MAX][TAM_MAX];

void dfs(int);
int encontrar(int);
int kruskal(int);
void trocar(int *, int *);
int comparar(const void *, const void *);

char ler_int(int *);
void imprimir_int(int);

int num_vertices;

int main(int argc, char **argv)
{

    int num_arestas;

    while (~scanf("%d %d%*c", &num_vertices, &num_arestas))
    {

        memset(adj, 0, sizeof(adj));

        for (int i = 0; i < num_arestas; ++i)
        {
            ler_int(&arestas[i].u);
            ler_int(&arestas[i].v);
            ler_int(&arestas[i].w);

            adj[arestas[i].u][arestas[i].v] = arestas[i].w;
        }

        int componentes = 0;
        memset(visitado, 0, sizeof(visitado));

        for (int i = 1; i <= num_vertices; ++i)
            if (!visitado[i])
                ++componentes, dfs(i);

        if (componentes > 1)
        {
            puts("impossivel");
            continue;
        }

        for (int i = 1; i <= num_vertices; ++i)
            pai[i] = i, tamanho[i] = 1;

        qsort(arestas, num_arestas, sizeof(aresta_t), comparar);

        imprimir_int(kruskal(num_arestas));
        putchar_unlocked('\n');
    }

    return 0;
}

int comparar(const void *a, const void *b)
{
    return ((aresta_t *)a)->w - ((aresta_t *)b)->w;
}

inline void trocar(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int encontrar(int u)
{
    if (u == pai[u])
        return u;
    else
        return pai[u] = encontrar(pai[u]);
}

int kruskal(int total)
{
    int resposta = 0;

    for (int i = 0; i < total; ++i)
    {
        int p = encontrar(arestas[i].u);
        int q = encontrar(arestas[i].v);

        if (p != q)
        {
            if (tamanho[p] > tamanho[q])
                trocar(&p, &q);

            pai[p] = q;
            tamanho[q] += tamanho[p];

            resposta += arestas[i].w;
        }
    }

    return resposta;
}

void dfs(int s)
{
    visitado[s] = true;

    for (int i = 1; i <= num_vertices; ++i)
        if (adj[s][i] && !visitado[i])
            dfs(i);
}

inline char ler_int(int *a)
{
    register char c = 0;
    *a = 0;
    c = getchar_unlocked();

    while (c >= 48)
        *a = *a * 10 + (c - '0'), c = getchar_unlocked();

    return c;
}

inline void imprimir_int(int n)
{
    int i = 10;
    char buffer[10];

    do
    {
        buffer[--i] = (n % 10) + '0';
        n /= 10;
    } while (n);

    do
    {
        putchar_unlocked(buffer[i]);
    } while (++i < 10);
}
