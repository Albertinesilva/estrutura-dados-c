#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define InicioVetor 1
#define MaxTam 6

typedef int Apontador;
typedef int TipoChave;


typedef struct
{
    TipoChave chave;

} TipoItem;

typedef struct
{
    TipoItem Item[MaxTam];
    Apontador Frente, Fundo;

} TipoFila;


int Menu_Lista(int Opcao);

void Iniciar_Fila(TipoFila *Fila);

int Fila_Vazia(TipoFila *Fila);

void Fura_Fila(TipoItem x, TipoFila *Fila);

void Imprimir_Fila(TipoFila Fila);


void main()
{
    setlocale(LC_ALL,"portuguese");

    TipoFila Fila;
    TipoItem x;

    int Opcao = 0, Verificador = 0;

    while(Opcao != 4)
    {
        Opcao = Menu_Lista(Opcao);

        switch(Opcao)
        {
        case 1:

            Iniciar_Fila(&Fila);
            Verificador = 1;

            printf("\n\tFila Inicializada com sucesso!...\n");

            break;

        case 2:

            if(Verificador == 1)
            {
                if(Fila_Vazia(&Fila))
                {
                    printf("\n\tFila Vazia, Pode Enfileirar!...\n\n");
                    do
                    {
                        printf("\n\tDigite um elemento para a Fila:  ");
                        fflush(stdin);
                        scanf("%d",&x);
                        system("cls");

                        Fura_Fila(x, &Fila);
                    }
                    while(Fila.Fundo != MaxTam);

                    printf("\n\tDigite um elemento para furar a Fila:  ");
                    fflush(stdin);
                    scanf("%d",&x);
                    system("cls");

                    Fura_Fila(x, &Fila);

                }
                else
                {
                    printf("\n\tFila Cheia!...\n");
                }
            }
            else
            {
                printf("\n\tA fila não foi Inicializada!...\n");
            }

            break;

        case 3:

            if(Verificador == 1)
            {
                if(Fila_Vazia(&Fila))
                {
                    printf("\n\tFila Vazia, não tem elementos para Imprimir!...\n\n");
                }
                else
                {
                    Imprimir_Fila(Fila);
                }
            }
            else
            {
                printf("\n\tA fila não foi Inicializada!...\n");
            }

            break;

        default:

            printf("\n\tPrograma Finalizado!...\n");

            break;
        }
    }
}

int Menu_Lista(int Opcao)
{
    printf("\n\t----------------Fura Fila----------------\n");

    do
    {
        printf("\n\t[1] - Iniciar a Fila");
        printf("\n\t[2] - Enfileirar a Fila");
        printf("\n\t[3] - Imprimir a Fila");
        printf("\n\t[4] - Sair");
        printf("\n\tEntrada:  ");
        fflush(stdin);
        scanf("%d",&Opcao);
        system("cls");

    }
    while(Opcao > 4 || Opcao < 1);

    return Opcao;

}

void Iniciar_Fila(TipoFila *Fila)
{
    Fila->Frente = InicioVetor;
    Fila->Fundo =  Fila->Frente;
}

int Fila_Vazia(TipoFila *Fila)
{
    return (Fila->Frente == Fila->Fundo);
}

void Fura_Fila(TipoItem x, TipoFila *Fila)
{

    if(Fila->Frente == (Fila->Fundo % MaxTam + 1))
    {
        Fila->Item[Fila->Fundo - 6] = x;
        printf("\n\tFila cheia, mas o elemento %d furou a Fila!...\n",x);
    }
    else
    {
        Fila->Item[Fila->Fundo] = x;
        Fila->Fundo = (Fila->Fundo % MaxTam) + 1;
    }

}

void Imprimir_Fila(TipoFila Fila)
{
    printf("\n\t---------------Fura a Fila---------------\n\n");
    int Aux = 0;

    for(Aux = Fila.Frente - 1; Aux < Fila.Fundo - 1; Aux++)
    {
        printf("\t%d",Fila.Item[Aux].chave);
    }
    printf("\n\n\t-----------------------------------------\n");
}

