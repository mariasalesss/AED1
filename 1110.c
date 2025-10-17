#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int cap;
    int cabeca;
    int cauda;
} fila;

static fila *criar_Fila(int cap) {
    fila *q = (fila*) malloc(sizeof(fila));
    if (!q) return NULL;
    q->data = (int*) malloc(sizeof(int) * cap);
    if (!q->data) { free(q); return NULL; }
    q->cap = cap;
    q->cabeca = 0;
    q->cauda = 0;
    return q;
}

static void free_Fila(fila *q) {
    if (!q) return;
    free(q->data);
    free(q);
}

static int fila_Vazia(const fila *q) {
    return q->cabeca == q-
