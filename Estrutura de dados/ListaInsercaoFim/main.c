#include <stdio.h>
#include <stdlib.h>

typedef struct ponto {
    float x;
    float y;
    struct ponto *prox;
}ponto;

// Ponteiro que aponta para o primeiro elemento da lista
ponto *listaPontos; 

//Função para adicionar elementos a lista no inicio
void addIni(float x, float y){

    ponto *p =(ponto*) malloc(sizeof(ponto));
    p->x=x;
    p->y=y;
    p->prox = listaPontos;
    listaPontos = p;
}
//Função para adicionar elementos a lista no final
void addFim(float x, float y){
    ponto *p =(ponto*) malloc(sizeof(ponto));
    p->x=x;
    p->y=y;
    p->prox = NULL; //Será o ultimo elemento da lista

    //Verificar se o primeiro elemento é NULL(Lista vazia)

    if (listaPontos == NULL)
    {
        listaPontos = p;
    }else {
        ponto *aux = listaPontos;
        while (aux->prox !=NULL)
        {
            aux=aux->prox;
        }
        aux->prox=p;
    }
    
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
    addIni(1,5);
    addIni(2,7);
    addIni(5,3);
    addFim(9,3);
    addFim(1,1);
    addFim(16,19);


    

    imprime();
    // criação de encadeamento
    // p->prox = p1;
    // p1->prox = p2;
    // p2->prox = NULL
}