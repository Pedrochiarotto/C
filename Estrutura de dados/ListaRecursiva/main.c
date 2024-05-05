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

//Função para imprimir a lista com recursividade
void imprime(ponto *p){
    
   if(p!=NULL){
        	
        printf("\nPonto (%.1f,%.1f)", p->x,p->y); 
        imprime(p->prox); // Imprime o proximo ponto até ele  estar vazio 
   }
}

int main()
{
    add(1,5);
    add(2,7);
    add(5,3);
    ponto *auxLista = listaPontos; // Aponta para a primeira posição da lista
  

    imprime(auxLista);
    // criação de encadeamento
    // p->prox = p1;
    // p1->prox = p2;
    // p2->prox = NULL
}
