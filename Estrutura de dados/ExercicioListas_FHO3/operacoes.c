// operacoes.c

#include <stdio.h>
#include <stdlib.h>
#include "header.h"

// operacoes de inicializar a lista
void inicializaLista(No **lista) {
	*lista = NULL;
}

// operacao que avalia se a lista esta vazia
int estaVazia(No *lista) {
	if (lista = NULL ) 
		return 1;
		
	return 0; // indica lista nao vazia
}

void exibeLista(No *lista) {
	No *aux = lista;
	
	if(estaVazia(lista)) {
		printf("A lista esta vazia\n\n");
		return;
	}
	
	printf("Lista [");
	
	while(aux != NULL) {
		printf("%d ", aux->dado);
		aux = aux->proximo;
	}
	
	printf("]\n");
	
}

void insereInicio(No **lista, int n) {
	No *novoNo;
	
	//cria o novo No a ser inserido na lista
	novoNo = (No*) malloc(sizeof(No));
	novoNo->dado = n;
	
	// se a lista estiver vazia, novo no aponta para NULL
	if(estaVazia(*lista) == 1) {
		novoNo->proximo = NULL;
	} else {
		novoNo->proximo = *lista;
	}
	
	// Novo no passa a ser o inicio da lista
	*lista = novoNo;
} // fim da funcao insereInicio

void insereFinal(No **lista, int n) {
	No *novoNo;
	No *aux = *lista;

	// criar o novo nó
	novoNo = (No*)malloc(sizeof(No));
	novoNo->dado = n;
	novoNo->proximo = NULL;
	
	// se a lista estiver vazia, move nulo para o prox
	if(estaVazia(*lista)) {
		*lista = novoNo;
		return;
	}
	
	//caminhar na lista até chegar no ultimo nó
	while(aux->proximo != NULL) {
		aux = aux->proximo;
	}
	
	aux->proximo = novoNo;
}

void removeInicio(No **lista) {
	No *aux = *lista;
	
	if(estaVazia(*lista)) {
		printf("Lista esta vazia!");
		return;
	}
	
	// fazer o inicio da lista apontar para o segundo No
	*lista = aux->proximo;
	
	
	// liberar a memória para o sistema operacional
	free(aux);
}

void removeFinal(No **lista) {
	No *aux = *lista;
	No *anterior = *lista;
	
	if(estaVazia(*lista)) {
		printf("Lista esta vazia!");
		return;
	}
	
	// caminha ate o final da lista
	while(aux->proximo != NULL) {
		anterior = aux;
		aux = aux->proximo;
	}
	
	// se houver apenas um elemento, entao, inicio torna-se NULL
	if(aux == *lista)
		*lista = NULL;
	// caso contrario, remove o ultimo no da lista
	else
		anterior->proximo = NULL;
	
	free(aux);
}

