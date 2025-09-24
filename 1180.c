#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    scanf("%d", &N);

    int *X = (int*) malloc(N * sizeof(int));
    if (X == NULL) {
        printf("Erro de alocacao\n");
        return 1;
    }

    for (int i = 0; i < N; i++) {
        scanf("%d", &X[i]);
    }

    int menorValor = X[0];
    int posicao = 0;

    for (int i = 1; i < N; i++) {
        if (X[i] < menorValor) {
            menorValor = X[i];
            posicao = i;
        }
    }

    printf("Menor valor: %d\n", menorValor);
    printf("Posicao: %d\n", posicao);

    free(X);
    return 0;
}
