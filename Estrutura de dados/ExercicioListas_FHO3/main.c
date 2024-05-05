// arquivo principal

#include <stdio.h>
#include "operacoes.c"

int main () {
	No *inicio;
	
	inicializaLista(&inicio);
	exibeLista(inicio);
	
	insereInicio(&inicio, 1);
	exibeLista(inicio);
	insereInicio(&inicio, 6);
	exibeLista(inicio);
	insereInicio(&inicio, 11);
	exibeLista(inicio);
	
	insereFinal(&inicio, 5);
	exibeLista(inicio);
	insereFinal(&inicio, 27);
	exibeLista(inicio);
	insereFinal(&inicio, 18);
	exibeLista(inicio);
	
	removeInicio(&inicio);
	exibeLista(inicio);
	removeFinal(&inicio);
	exibeLista(inicio);
	removeInicio(&inicio);
	exibeLista(inicio);
	removeFinal(&inicio);
	exibeLista(inicio);
	removeFinal(&inicio);
	exibeLista(inicio);
	
	return 0;
}
