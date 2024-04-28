int main()
{
   int val = 5;
   int *ponteiro; //Criação do ponteiro

   ponteiro = &val; // Aponta para o endereço da variável val

   printf("O valor apontado por 'ponteiro' é: %d\n", *ponteiro);

   printf("O valor da variável ponteiro é: %zu\n", ponteiro);
   return 0;
}
