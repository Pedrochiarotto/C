#include <stdlib.h>
#include <stdio.h>

int comp(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int A, D, ata[11], def[11];

    while (scanf("%d %d", &A, &D) == 2)
    {
        if (A == 0 && D == 0)
            break;

        for (int i = 0; i < A; ++i)
        {
            scanf("%d", &ata[i]);
        }

        for (int i = 0; i < D; ++i)
        {
            scanf("%d", &def[i]);
        }

        qsort(ata, A, sizeof(int), comp);
        qsort(def, D, sizeof(int), comp);

        int atacante = ata[0];
        int penultimo = def[1];

        printf("%c\n", atacante < penultimo ? 'Y' : 'N');
    }

    return 0;
}