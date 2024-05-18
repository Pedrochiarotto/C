
#include <stdio.h>
#include <stdlib.h>

typedef struct ponto {
    float x;
    float y;
    struct ponto *prox;
}ponto;

// Ponteiro que aponta para o primeiro elemento da lista
ponto *listaPontos; 

//Variavel para indicar a quantidade de elementos na lista
int length = 0;

//Função para adicionar elementos a lista no inicio


void addIndex(float x, float y, int index){
    ponto *p = (ponto *) malloc(sizeof(ponto));
    p->x = x;
    p->y = y;

    if (index>length)
    {
        printf("Posição inválida");

    }else{
        if (index == 0)
        {
            p->prox = listaPontos; 
            listaPontos = p; 
        }else{
            ponto *listaAux = listaPontos; 
            int i=0;

            
            while(i!=index-1){
              listaAux = listaAux ->prox; 
                i++;

            }
            p-> prox = listaAux->prox;
            listaAux->prox = p; 
        }
        length++;
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
    addIndex(1,1,0);
    addIndex(3,4,0);
    addIndex(2,6,2);

   


    imprime();
    // criação de encadeamento
    // p->prox = p1;
    // p1->prox = p2;
    // p2->prox = NULL
}

