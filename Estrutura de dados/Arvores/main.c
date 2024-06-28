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
void rem(nodo *n, int valor){
    nodo *filho = n;
    nodo *pai;
    
    do{
        pai = filho;
        if(valor < filho->valor){
            filho = filho->esq;
        }else if(valor > filho->valor){
            filho = filho->dir;

        }
    }while(filho != NULL && filho->valor != valor);

    if (filho != NULL)
    {
        if(filho->esq == NULL && filho->dir == NULL){//caso 1: nodo nao tem filhos.
            if (pai->esq == filho)
            {
                pai->esq = NULL;
            }
            if (pai->dir == filho)
            {
                pai->dir = NULL;
            }
        }
        if (filho->esq != NULL && filho->dir == NULL)//Caso 2: nodo filho tem um filho a esquerda.
        {
            if (pai->esq == filho)
            {
                pai->esq = filho->esq;
            }
            if (pai->dir == filho)
            {
                pai->dir = filho->esq;
            }
            
            
        }
        if (filho->dir != NULL && filho->esq == NULL)//Caso 2: nodo filho tem um filho a direita.
        {
            if (pai->esq == filho)
            {
                pai->esq = filho->dir;
            }
            if (pai->dir == filho)
            {
                pai->dir = filho->dir;
            }
        }
        //Caso 3: Nodo filho tem um filho a direita e a esquerda
       if(filho->esq != NULL && filho->dir != NULL) {
        if (filho->esq->dir == NULL)
        {
            filho->valor = filho->esq->valor;
        }else{
            nodo *p = filho->esq;
            nodo *aux = p;
            while (p->dir !=NULL)
            {
                aux= p;
                p = p->dir;

            }
            aux->dir = NULL;
            filho->valor = p->valor;
        }
        
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
   
    rem(root, 2);

    imprimir(root) ;
 

    return 0; 
    
}
