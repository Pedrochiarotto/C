#include <stdlib.h>
#include <stdio.h>

struct pessoa{
    int senha; 
    struct pessoa *prox;
};

typedef struct pessoa pessoa;

pessoa *inicio;

void add(int senha){
    pessoa *p = (pessoa *)malloc(sizeof(pessoa));
    p->senha = senha;
    p->prox = NULL;

    if(inicio == NULL){
        inicio = p; 
    }else{

        pessoa *aux = inicio;
        while (aux->prox!=NULL)
        {
            aux= aux->prox; 
        }
        aux->prox = p; 
    }
}

void imprime(pessoa *f){
    if(f != NULL)
    {
        printf("\nSenha da pessoa: %d",f->senha); 
        imprime(f->prox); 
    }
     
}

void rem(){
    if (inicio==NULL){
        printf("Fila vazia!");
    }else{//primeiro elemento é excluido e ele recebe o proximo elemento
        inicio = inicio->prox; 
    }
    
}

int main()
{
    add(5);
    add(10);
    add(25);
    add(22);

    pessoa *aux = inicio; 
    imprime(aux);
    rem();
    aux = inicio; 
    imprime(aux);
}
