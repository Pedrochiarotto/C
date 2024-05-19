#ifndef SUPERMERCADO_H
#define SUPERMERCADO_H

#include <time.h>

#define MAX_CAIXAS 25
#define MIN_CAIXAS 3

typedef enum { RAPIDO, PREFERENCIAL, COMUM } TipoFila;

typedef struct {
    int senha;
    TipoFila tipo;
    time_t horaChegada;
} Cliente;

typedef struct No {
    Cliente cliente;
    struct No *proximo;
} No;

typedef struct {
    No *inicio;
    No *fim;
    int tamanho;
} Fila;

typedef struct {
    int id;
    int atendendo;
    time_t horaUltimoAtendimento;
} Caixa;

void inicializarFila(Fila *fila);
int filaVazia(Fila *fila);
void enfileirar(Fila *fila, Cliente cliente);
Cliente desenfileirar(Fila *fila);
void imprimirTempoEspera(Fila *fila);

time_t tempoAtual();

#endif // SUPERMERCADO_H
