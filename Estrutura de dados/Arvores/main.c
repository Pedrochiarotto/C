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
    imprimir(n->esq);
    printf("\n%d", n->valor);
    imprimir(n->dir);
}
//Função para inserir dados na árvore

void add(nodo *n, int valor){
    if(valor < n->valor){
        if(n->esq == NULL){
            n->esq = create(valor); 
        }else{
            add(n->esq,valor);
        }
    }else {
        if (n->dir == NULL){
            n->dir = create(valor);
        }else{
            add(n->dir, valor);
        }     
    }
    
}

int main()
{
    //Criação do nodo raíz
    nodo *root = create(5);
   
    add(root,2);
    add(root,3);
    add(root,4);
    add(root,6);
    /*Logica de uma estrutura de arvore
    nodo5->esq = nodo2;
    nodo2->esq = nodo1;
    nodo5->dir = nodo8;
    nodo2->dir = nodo4;*/

    //Passar o nodo raiz(inicial) para exibir a arvore toda
    imprimir(root) ;

    return 0; 
    
}
