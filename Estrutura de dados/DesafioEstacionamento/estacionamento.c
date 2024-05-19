#include "estacionamento.h"
#include <stdio.h>
#include <string.h>

void inicializarEstacionamento(Estacionamento *est) {
    est->topo = -1;
}

int estacionamentoVazio(Estacionamento *est) {
    return (est->topo == -1);
}

int estacionamentoCheio(Estacionamento *est) {
    return (est->topo == MAX_VAGAS - 1);
}

int estacionarCarro(Estacionamento *est, Carro carro) {
    if (estacionamentoCheio(est)) {
        return 0;
    }
    est->carros[++est->topo] = carro;
    return 1;
}

int removerPrimeiroCarro(Estacionamento *est) {
    if (estacionamentoVazio(est)) {
        return 0;
    }
    for (int i = 0; i < est->topo; i++) {
        est->carros[i] = est->carros[i + 1];
    }
    est->topo--;
    return 1;
}

int numCarrosEstacionados(Estacionamento *est) {
    return est->topo + 1;
}

void listarCarros(Estacionamento *est) {
    if (estacionamentoVazio(est)) {
        printf("Estacionamento vazio.\n");
        return;
    }
    for (int i = 0; i <= est->topo; i++) {
        printf("Placa: %s\n", est->carros[i].placa);
    }
}
