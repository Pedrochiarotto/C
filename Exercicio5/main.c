#include "c.c"
#include <stdlib.h>
#include <stdio.h>

int main(){
    aluno *a;
    //Passando os argumentos para as funçoes
    
    ImprimirDados(&a,"Pedro",115133,19,6.3 );
    ImprimirPonteiro(&a);

    return 0;
}
