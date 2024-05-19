#ifndef ESTACIONAMENTO_H
#define ESTACIONAMENTO_H

#define MAX_VAGAS 18

typedef struct {
    char placa[9];
} Carro;

typedef struct {
    Carro carros[MAX_VAGAS];
    int topo;
} Estacionamento;

void inicializarEstacionamento(Estacionamento *est);
int estacionamentoVazio(Estacionamento *est);
int estacionamentoCheio(Estacionamento *est);
int estacionarCarro(Estacionamento *est, Carro carro);
int removerPrimeiroCarro(Estacionamento *est);
int numCarrosEstacionados(Estacionamento *est);
void listarCarros(Estacionamento *est);

#endif // ESTACIONAMENTO_H
