#include <stdio.h>
#include <stdlib.h>

 typedef struct{
    float x;
    float y;
}ponto;

int main()
{
    ponto *p = (ponto*)malloc(sizeof(ponto)); //Denominando p como ponteiro, determando a ele um espaço de memória com a função "malloc" e a função "sizeof", que representa o tamanho da váriavel de acordo com seu tipo de dado.
    p-> x = 1;
    p-> y = 5;

    printf("Ponto = (%.2f,%.2f )",p->x, p->y );
    return 0;

}
