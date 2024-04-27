#include "c.h"  
#include <stdio.h>

//Construção do método ImprimirDados
void ImprimirDados(aluno *a,char nome,int ra, int idade, float media ){

    a->ra = ra;
    a->nome[20] = nome; 
    a->idade = idade;
    a->media = media; 

    printf("Nome: %s\n ", a->nome);
    printf("RA: %d\n ", a->ra);
    printf("Idade: %d\n ", a->idade);
    printf("Media: %.2f\n ", a->media);
};

// Construção do método ImprimirPonteiro
void ImprimirPonteiro(aluno *a){
    printf("Endereco da memoria: %p\n ", &a); 
    printf("Tamanho de memoria: %zu\n", sizeof(&a)); 
}
