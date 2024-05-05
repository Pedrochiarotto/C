#include <stdio.h>
#include <stdlib.h>

typedef struct ponto {
    float x;
    float y;
    struct ponto *prox;
}ponto;

// Ponteiro que aponta para o primeiro elemento da lista
ponto *listaPontos; 

//Função para adicionar elementos a lista
void add(float x, float y){

    ponto *p =(ponto*) malloc(sizeof(ponto));
    p->x=x;
    p->y=y;
    p->prox = listaPontos;
    listaPontos = p;
}

//Função para imprimir a lista
void imprime(){
    ponto *auxLista = listaPontos; // Aponta para a primeira posição da lista
    while(auxLista != NULL){
        printf("\nPonto(%.1f,%.1f)",auxLista->x, auxLista->y);
        auxLista =auxLista ->prox;//A variável auxiliar irá receber a proxima posicao
    }
}

int main()
{
    add(1,5);
    add(2,7);
    add(5,3);

    printf("%.0f", listaPontos->prox->x);

    imprime();
    // criação de encadeamento
    // p->prox = p1;
    // p1->prox = p2;
    // p2->prox = NULL
}
