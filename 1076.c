#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define verdadeiro 1
#define falso 0
#define TAMANHO_MAX 110

int visitado[TAMANHO_MAX];
char adjacencia[TAMANHO_MAX][TAMANHO_MAX];

int quantidade_vertices, resposta;
void dfs(int);

int main(int argc, char **argv)
{

    int num_testes, origem;
    int num_arestas, a, b, i;

    scanf("%d", &num_testes);

    while (num_testes--)
    {

        scanf("%d", &origem);
        scanf("%d %d", &quantidade_vertices, &num_arestas);

        memset(visitado, 0, sizeof(visitado));
        memset(adjacencia, 0, sizeof(adjacencia));

        for (i = 0; i < num_arestas; ++i)
        {

            scanf("%d %d", &a, &b);
            adjacencia[a][b] = adjacencia[b][a] = verdadeiro;

        }

        resposta = 0;
        dfs(origem);
        printf("%d\n", resposta << 1);

    }

    return 0;

}

void dfs(int u)
{

    int i;
    visitado[u] = verdadeiro;

    for (i = 0; i < quantidade_vertices; ++i)
        if (adjacencia[u][i])
            if (!visitado[i])
                dfs(i), resposta++;
}
