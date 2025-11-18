#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int destino;
    struct No* prox;
} No;

No* lista[10005];
int grauEntrada[10005];
int fila[10005];

void adicionar(int a, int b) {
    No* novo = malloc(sizeof(No));
    novo->destino = b;
    novo->prox = lista[a];
    lista[a] = novo;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        // Inicializa as estruturas
        for (int i = 1; i <= N; i++) {
            lista[i] = NULL;
            grauEntrada[i] = 0;
        }

        // Lê as dependências e preenche a lista de adjacência
        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            adicionar(A, B);
            grauEntrada[B]++;
        }

        int ini = 0, fim = 0;

        // Enfileira todos os nós com grau de entrada 0
        for (int i = 1; i <= N; i++) {
            if (grauEntrada[i] == 0) {
                fila[fim++] = i;
            }
        }

        int removidos = 0;

        // Processa a fila de BFS
        while (ini < fim) {
            int v = fila[ini++];  // Retira o elemento da frente da fila
            removidos++;  // Conta o nó removido

            No* atual = lista[v];
            while (atual != NULL) {
                grauEntrada[atual->destino]--;  // Diminui o grau de entrada do destino
                if (grauEntrada[atual->destino] == 0) {
                    fila[fim++] = atual->destino;  // Enfileira o nó com grau de entrada 0
                }
                atual = atual->prox;
            }
        }

        // Se todos os nós foram removidos, não há ciclo
        if (removidos == N) {
            printf("NAO\n");
        } else {
            printf("SIM\n");
        }

        // Libera a memória
        for (int i = 1; i <= N; i++) {
            No* aux = lista[i];
            while (aux != NULL) {
                No* tmp = aux;
                aux = aux->prox;
                free(tmp);
            }
        }
    }

    return 0;
}
