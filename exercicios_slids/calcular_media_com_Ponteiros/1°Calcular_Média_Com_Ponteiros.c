#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>


void main()
{
    setlocale(LC_ALL,"portuguese");
    srand(time(NULL));

    float Vet[100];
    float *Media, *Soma = &Vet[0];
    Media = Soma;

    printf("\n----------Atribui Valores ao Vetor de Forma Randómica----------\n\n");

    for(int i = 0; i < 100; i++)
    {
        Vet[i] = rand() % 10 + 1;
        printf("%1.f,",Vet[i]);
    }

    //Soma os Elementos do Vetor, Para Ponteiro Soma.
    for(int i = 1; i < 100; i++)
    {
        *Soma += Vet[i];
    }

    printf("\n--------------Resultado da Soma, no Ponteiro Média-------------\n\n");

    printf("Soma = %1.f\n",*Media);

    printf("\n--------------Resultado da Média, no Ponteiro Média------------\n");

    *Media = *Media / 5;
    printf("\nMédia = %.1f\n",*Media);
}
