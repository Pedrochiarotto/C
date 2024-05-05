// header.h

#ifndef LISTA_H
#define LISTA_H

// defini��o da estrutura
typedef struct _no {
	int dado;
	struct _no *proximo;
} No;

// declara��o das opera��es
void inicializaLista(No **);
int estaVazia (No *);

void exibeLista(No *);

void insereInicio(No **, int);
void insereFinal(No **, int);

void removeInicio(No **);
void removeFinal(No **);

#endif
