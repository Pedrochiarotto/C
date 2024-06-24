#include <stdio.h>
#include <stdlib.h>

struct nodo
{
    int valor; 
    struct nodo *dir;
    struct nodo *esq; 
};

typedef struct nodo nodo; 

//Função para criar os nodos.
nodo* create(int valor){ 

    nodo *n = malloc(sizeof(nodo));
    n->valor = valor;
    n->dir = NULL;
    n->esq= NULL;
    return n;
}

// Função para imprimir a arvore
void imprimir(nodo *n){
    if(n==NULL)
        return;
    printf("\n%d", n->valor);
    imprimir(n->esq);
    imprimir(n->dir);
}

int main()
{
    nodo *nodo5 = create(5);
    nodo *nodo2 = create(2);
    nodo *nodo1 = create(1);
    nodo *nodo4 = create(4);
    nodo *nodo8 = create(8);

    //Logica de uma estrutura de arvore
    nodo5->esq = nodo2;
    nodo2->esq = nodo1;
    nodo5->dir = nodo8;
    nodo2->dir = nodo4;

    //Passar o nodo raiz(inicial) para exibir a arvore toda
    imprimir(nodo5) ;

    return 0; 
    
}
