#include "supermercado.h"
#include <stdio.h>
#include <stdlib.h>

void inicializarFila(Fila *fila) {
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tamanho = 0;
}

int filaVazia(Fila *fila) {
    return (fila->tamanho == 0);
}

void enfileirar(Fila *fila, Cliente cliente) {
    No *novo = (No*)malloc(sizeof(No));
    novo->cliente = cliente;
    novo->proximo = NULL;
    if (filaVazia(fila)) {
        fila->inicio = novo;
    } else {
        fila->fim->proximo = novo;
    }
    fila->fim = novo;
    fila->tamanho++;
}

Cliente desenfileirar(Fila *fila) {
    Cliente cliente;
    if (!filaVazia(fila)) {
        No *temp = fila->inicio;
        cliente = temp->cliente;
        fila->inicio = fila->inicio->proximo;
        free(temp);
        fila->tamanho--;
    }
    return cliente;
}

void imprimirTempoEspera(Fila *fila) {
    if (filaVazia(fila)) {
        printf("Fila vazia.\n");
        return;
    }
    time_t agora = tempoAtual();
    No *atual = fila->inicio;
    while (atual != NULL) {
        printf("Senha: %d, Tempo de espera: %ld segundos\n", atual->cliente.senha, agora - atual->cliente.horaChegada);
        atual = atual->proximo;
    }
}

time_t tempoAtual() {
    return time(NULL);
}
