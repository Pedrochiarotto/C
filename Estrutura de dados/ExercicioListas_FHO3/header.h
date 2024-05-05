// header.h

#ifndef LISTA_H
#define LISTA_H

// definição da estrutura
typedef struct _no {
	int dado;
	struct _no *proximo;
} No;

// declaração das operações
void inicializaLista(No **);
int estaVazia (No *);

void exibeLista(No *);

void insereInicio(No **, int);
void insereFinal(No **, int);

void removeInicio(No **);
void removeFinal(No **);

#endif
