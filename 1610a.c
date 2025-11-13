#include <stdio.h>
#include <stdlib.h>

#define MAX 10010  
#define MAXM 30010  

int visitado[MAX];
int grafo[MAX][MAX];
int listaAdj[MAX][MAX]; 
int qtdAdj[MAX];        
int N, M;
int ciclo;

void dfs(int u) {
    visitado[u] = 1; 

    for (int i = 0; i < qtdAdj[u]; i++) {
        int v = listaAdj[u][i];

        if (visitado[v] == 0) {
            dfs(v);
        } else if (visitado[v] == 1) {
            
            ciclo = 1;
            return;
        }
    }

    visitado[u] = 2; 
}

int main() {
    int T;
    scanf("%d", &T);

    while (T--) {
        scanf("%d %d", &N, &M);

        
        for (int i = 1; i <= N; i++) {
            qtdAdj[i] = 0;
            visitado[i] = 0;
        }

        for (int i = 0; i < M; i++) {
            int A, B;
            scanf("%d %d", &A, &B);
            listaAdj[A][qtdAdj[A]++] = B;
        }

        ciclo = 0;

        for (int i = 1; i <= N; i++) {
            if (visitado[i] == 0) {
                dfs(i);
                if (ciclo) break;
            }
        }

        if (ciclo)
            printf("SIM\n");
        else
            printf("NAO\n");
    }

    return 0;
}
