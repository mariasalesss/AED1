#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int destino;
    struct No* prox;
} No;

No* lista[10005];
int visitado[10005];
int pilha[10005];

void adicionar(int a, int b) {
    No* novo = malloc(sizeof(No));
    novo->destino = b;
    novo->prox = lista[a];
    lista[a] = novo;
}

int dfs(int v) {
    visitado[v] = 1;
    pilha[v] = 1;
    No* atual = lista[v];

    while (atual != NULL) {
        int d = atual->destino;
        if (!visitado[d]) {
            if (dfs(d)) return 1;
        } else if (pilha[d]) {
            return 1;
        }
        atual = atual->prox;
    }

    pilha[v] = 0;
    return 0;
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        int N, M;
        scanf("%d %d", &N, &M);

        for (int i = 1; i <= N; i++) {
            lista[i] = NULL;
            visitado[i] = 0;
            pilha[i] = 0;
        }

        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            adicionar(A, B);
        }

        int achou = 0;
        for (int i = 1; i <= N; i++) {
            if (!visitado[i]) {
                if (dfs(i)) {
                    achou = 1;
                    break;
                }
            }
        }

        if (achou) printf("SIM\n");
        else printf("NAO\n");

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
