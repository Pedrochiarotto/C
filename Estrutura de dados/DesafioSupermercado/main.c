#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "supermercado.h"

int main() {
    Fila filaRapida, filaPreferencial, filaComum;
    Caixa caixas[MAX_CAIXAS];
    int numCaixasAbertas = MIN_CAIXAS;
    int proximaSenha = 1;

    inicializarFila(&filaRapida);
    inicializarFila(&filaPreferencial);
    inicializarFila(&filaComum);

    for (int i = 0; i < MAX_CAIXAS; i++) {
        caixas[i].id = i + 1;
        caixas[i].atendendo = 0;
        caixas[i].horaUltimoAtendimento = 0;
    }

    for (int i = 0; i < 50; i++) {
        Cliente cliente;
        cliente.senha = proximaSenha++;
        cliente.horaChegada = tempoAtual();
        cliente.tipo = rand() % 3;

        if (cliente.tipo == RAPIDO) {
            enfileirar(&filaRapida, cliente);
        } else if (cliente.tipo == PREFERENCIAL) {
            enfileirar(&filaPreferencial, cliente);
        } else {
            enfileirar(&filaComum, cliente);
        }

        for (int j = 0; j < numCaixasAbertas; j++) {
            if (!caixas[j].atendendo) {
                if (!filaVazia(&filaPreferencial)) {
                    caixas[j].atendendo = 1;
                    caixas[j].horaUltimoAtendimento = tempoAtual();
                    desenfileirar(&filaPreferencial);
                } else if (!filaVazia(&filaRapida)) {
                    caixas[j].atendendo = 1;
                    caixas[j].horaUltimoAtendimento = tempoAtual();
                    desenfileirar(&filaRapida);
                } else if (!filaVazia(&filaComum)) {
                    caixas[j].atendendo = 1;
                    caixas[j].horaUltimoAtendimento = tempoAtual();
                    desenfileirar(&filaComum);
                }
            } else {
                if (tempoAtual() - caixas[j].horaUltimoAtendimento > 5) {
                    caixas[j].atendendo = 0;
                }
            }
        }

        if (i % 15 == 0 && i != 0) {
            if (filaPreferencial.tamanho > 10 || filaRapida.tamanho > 10 || filaComum.tamanho > 10) {
                if (numCaixasAbertas < MAX_CAIXAS) {
                    numCaixasAbertas++;
                }
            } else {
                if (numCaixasAbertas > MIN_CAIXAS) {
                    numCaixasAbertas--;
                }
            }
        }

        printf("Estado das filas após %d minutos:\n", i);
        printf("Fila Rápida:\n");
        imprimirTempoEspera(&filaRapida);
        printf("Fila Preferencial:\n");
        imprimirTempoEspera(&filaPreferencial);
        printf("Fila Comum:\n");
        imprimirTempoEspera(&filaComum);
        printf("Número de caixas abertos: %d\n", numCaixasAbertas);

        sleep(1);
    }

    return 0;
}
