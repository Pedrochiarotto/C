#include <stdio.h>

 struct pessoa {
   int idade;
   float altura;  
   //criação dos atributos da struct
}; //criação da struct do tipo "pessoa"


int main(){


    struct pessoa p;

    p.idade = 5;
    p.altura = 1.65;

    printf("%d %.2f\n", p.idade, p.altura);
    return 0;
}
