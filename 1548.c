#include <stdio.h>

int contagem;

void ordenar_selection(short *v, unsigned short n) {
    for (unsigned short i = 0; i < n - 1; i++) {
        unsigned short posMaior = i;
        for (unsigned short j = i + 1; j < n; j++) {
            if (v[j] > v[posMaior])
                posMaior = j;
        }
        if (posMaior != i) {
            short aux = v[i];
            v[i] = v[posMaior];
            v[posMaior] = aux;
        }
    }
}

int main() {
    unsigned short testes;
    scanf("%hu", &testes);

    while (testes--) {
        unsigned short qtd;
        scanf("%hu", &qtd);

        short original[qtd], ordenado[qtd];

        for (int k = 0; k < qtd; k++) {
            scanf("%hd", &original[k]);
            ordenado[k] = original[k];
        }

        contagem = 0;
        ordenar_selection(ordenado, qtd);

        for (int k = 0; k < qtd; k++)
            if (original[k] == ordenado[k])
                contagem++;

        printf("%d\n", contagem);
    }

    return 0;
}
