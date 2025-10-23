#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    unsigned short id;
    unsigned short indice;
} Pessoa;

int main() {
    unsigned short total, sairam;
    unsigned short i, idAtual;
    Pessoa fila[51000];

    scanf("%hu", &total);
    memset(fila, 0, sizeof(fila));

    for (i = 0; i < total; i++) {
        scanf("%hu", &idAtual);
        fila[i].id = idAtual;
        fila[idAtual].indice = i;
    }

    scanf("%hu", &sairam);

    for (i = 0; i < sairam; i++) {
        scanf("%hu", &idAtual);
        fila[fila[idAtual].indice].id = 0;
    }

    bool primeiro = true;
    for (i = 0; i < total; i++) {
        if (fila[i].id != 0) {
            if (!primeiro)
                printf(" ");
            printf("%hu", fila[i].id);
            primeiro = false;
        }
    }

    printf("\n");
    return 0;
}
