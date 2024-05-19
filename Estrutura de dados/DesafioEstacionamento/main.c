#include <stdio.h>
#include "estacionamento.h"

int main() {
    Estacionamento est;
    inicializarEstacionamento(&est);

    Carro c1 = {"AAA-1111"};
    Carro c2 = {"BBB-2222"};
    Carro c3 = {"CCC-3333"};
    Carro c4 = {"DDD-4444"};
    Carro c5 = {"EEE-5555"};
    Carro c6 = {"FFF-6666"};
    Carro c7 = {"GGG-7777"};

    printf("Adicionando carro %s\n", c1.placa);
    estacionarCarro(&est, c1);
    printf("Carros no estacionamento:\n");
    listarCarros(&est);
    printf("\n");

    printf("Adicionando carro %s\n", c2.placa);
    estacionarCarro(&est, c2);
    printf("Carros no estacionamento:\n");
    listarCarros(&est);
    printf("\n");

    printf("Adicionando carro %s\n", c3.placa);
    estacionarCarro(&est, c3);
    printf("Carros no estacionamento:\n");
    listarCarros(&est);
    printf("\n");

    printf("Removendo o primeiro carro...\n");
    removerPrimeiroCarro(&est);
    printf("Carros no estacionamento após remoção:\n");
    listarCarros(&est);
    printf("\n");

    printf("Adicionando carro %s\n", c4.placa);
    estacionarCarro(&est, c4);
    printf("Carros no estacionamento:\n");
    listarCarros(&est);
    printf("\n");

    printf("Adicionando carro %s\n", c5.placa);
    estacionarCarro(&est, c5);
    printf("Carros no estacionamento:\n");
    listarCarros(&est);
    printf("\n");

    printf("Adicionando carro %s\n", c6.placa);
    estacionarCarro(&est, c6);
    printf("Carros no estacionamento:\n");
    listarCarros(&est);
    printf("\n");

    printf("Adicionando carro %s\n", c7.placa);
    estacionarCarro(&est, c7);
    printf("Carros no estacionamento:\n");
    listarCarros(&est);
    printf("\n");

    printf("Número de carros estacionados: %d\n", numCarrosEstacionados(&est));

    return 0;
}
