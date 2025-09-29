#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 9

bool ChecaVetor(int *v) {
    bool seen[10] = {false};
    for (int i = 0; i < N; i++) {
        if (v[i] < 1 || v[i] > 9) return false;
        if (seen[v[i]]) return false;
        seen[v[i]] = true;
    }
    return true;
}

bool ChecaLinhas(int **m) {
    for (int i = 0; i < N; i++) {
        if (!ChecaVetor(m[i])) return false;
    }
    return true;
}

bool ChecaColunas(int **m) {
    for (int j = 0; j < N; j++) {
        int v[N];
        for (int i = 0; i < N; i++) v[i] = m[i][j];
        if (!ChecaVetor(v)) return false;
    }
    return true;
}

bool ChecaBlocos(int **m) {
    for (int bi = 0; bi < N; bi += 3) {
        for (int bj = 0; bj < N; bj += 3) {
            int v[N];
            int k = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    v[k++] = m[bi + i][bj + j];
                }
            }
            if (!ChecaVetor(v)) return false;
        }
    }
    return true;
}

int main() {
    int t;
    scanf("%d", &t);

    for (int inst = 1; inst <= t; inst++) {
        // aloca a matriz dinamicamente
        int **m = (int**) malloc(N * sizeof(int*));
        for (int i = 0; i < N; i++) {
            m[i] = (int*) malloc(N * sizeof(int));
        }

        // leitura da matriz
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                scanf("%d", &m[i][j]);
            }
        }

        bool valido = ChecaLinhas(m) && ChecaColunas(m) && ChecaBlocos(m);

        printf("Instancia %d\n", inst);
        printf(valido ? "SIM\n\n" : "NAO\n\n");

        // libera a memória
        for (int i = 0; i < N; i++) {
            free(m[i]);
        }
        free(m);
    }

    return 0;
}
