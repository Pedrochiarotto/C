#include <stdio.h>

int v[10] = {4,8,12,2,56,34,7,1,25,98};

int main()
{
    int num = 12;
    
    for ( int i = 0; i < 10; i++)
    {
        if (v[i] == num){
            printf("Elemento encontrado na posicao %d\n", i);
        }

    }
    
    return 0;
}
