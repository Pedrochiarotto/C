#include <stdlib.h>
#include <stdio.h>

struct prato{
    char cor; 
    struct prato *prox;
};

typedef struct prato prato;

prato *inicio;

void add(char cor){
    prato *p = (prato *) malloc(sizeof(prato));
    p->cor = cor;
    p->prox = inicio; //p-> aponta para o primeiro elemento da fila
    inicio = p; 
}

void imprime(prato *p){
    if(p != NULL)
    {
        printf("\n%c",p->cor); 
        imprime(p->prox); 
    }
     
}

void rem(){
    if(inicio == NULL){
        printf("Pilha vazia\n");
    }
    inicio = inicio->prox;
}

int main()
{
   add('b');
   add('g');
   add('y'); 
   add('r');
   rem();

    prato *aux = inicio; 
    imprime(aux);
    
}

