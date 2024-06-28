int main()
{
    int v[100];
    
    //Preenchendo os espaços do vetor
    for (int i = 0; i < 100; i++)
    {
        v[i] = i+1;
       
    }
    int num = 50;

    int comparacoes = 0;

    int continuar = 1;

    int ini = 0;

    int fim = 99; 
    while (continuar == 1)
    {
        comparacoes++;

        int pivo = (ini + fim)/2;
        if (v[pivo] == num)
        {
            printf("Número encontrado na posicao %d", pivo);
            continuar = 0;
        }else{
            if (num > v[pivo])
            {
                ini = pivo + 1;

            }else 
                fim = pivo -1;
        }  

        if (fim<ini)
        {
            printf("Elemento nao encontrado!\n");
            continuar = 0;
        }
              
    }
    
    printf("Comparacoes: %d", comparacoes);

    return 0;
}
