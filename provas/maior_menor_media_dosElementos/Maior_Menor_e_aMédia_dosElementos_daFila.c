#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define InicioVetor 1
#define MaxTam 7

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

void Enfileirar_Fila(TipoItem x, TipoFila *Fila);

void Desinfileirar_Fila(TipoFila *Fila, TipoItem *Item);

void Encontrar_Maior_e_Menor_Elemento_eMedia(TipoFila *Fila);

void Imprimir_Fila(TipoFila Fila);


void main()
{
    setlocale(LC_ALL,"portuguese");

    TipoFila Fila;
    TipoItem x;

    int Opcao = 0, Verificador = 0;

    while(Opcao != 5)
    {
        Opcao = Menu_Lista(Opcao);

        switch(Opcao)
        {
        case 1:

            Iniciar_Fila(&Fila);
            Verificador = 1;

            printf("\n\tFila Inicializada com Sucesso!...\n");

            break;

        case 2:

            if(Verificador == 1)
            {

                if(Fila_Vazia(&Fila))
                {

                    while(Fila.Fundo != MaxTam)
                    {
                        printf("\n\tInforme os elementos para a Fila:  ");
                        fflush(stdin);
                        scanf("%d",&x);
                        system("cls");

                        Enfileirar_Fila(x, &Fila);
                    }

                }
                else
                {
                    printf("\n\tFila Cheia!...\n");
                }
            }
            else
            {
                printf("\n\tA Fila não foi Inicializada!...\n");
            }

            break;

        case 3:

            if(Verificador == 1)
            {

                if(Fila_Vazia(&Fila))
                {
                    printf("\n\tFila Vazia!...\n");
                }
                else
                {
                    Encontrar_Maior_e_Menor_Elemento_eMedia(&Fila);
                }
            }
            else
            {
                printf("\n\tA Fila não foi Inicializada!...\n");
            }

            break;

        case 4:

            if(Verificador == 1)
            {

                if(Fila_Vazia(&Fila))
                {
                    printf("\n\tFila Vazia!...\n");
                }
                else
                {
                    Imprimir_Fila(Fila);
                }
            }
            else
            {
                printf("\n\tA Fila não foi Inicializada!...\n");
            }

            break;

        default:

            printf("\n\tPrograma Finalizado com Sucesso!...\n");
        }
    }

}

int Menu_Lista(int Opcao)
{

    printf("\n\n\t----------Fila: Maior Elemento, Menor e a Média----------\n");

    do
    {
        printf("\n\t[1] - Iniciar a Fila");
        printf("\n\t[2] - Inserir Elementos na Fila");
        printf("\n\t[3] - Encontrar o Maior e Menor Elemento e a Média");
        printf("\n\t[4] - Imprimir Fila");
        printf("\n\t[5] - Sair");
        printf("\n\tEntrada:  ");
        fflush(stdin);
        scanf("%d",&Opcao);
        system("cls");

    }
    while(Opcao > 5 || Opcao < 1);

    return Opcao;

}

void Iniciar_Fila(TipoFila *Fila)
{
    Fila->Frente = InicioVetor;
    Fila->Fundo = Fila->Frente;
}

int Fila_Vazia(TipoFila *Fila)
{
    return (Fila->Frente == Fila->Fundo);
}

void Enfileirar_Fila(TipoItem x, TipoFila *Fila)
{
    if(Fila->Frente == (Fila->Fundo % MaxTam + 1))
    {
        printf("\n\tErro, Fila esta Cheia!...\n");
    }
    else
    {
        Fila->Item[Fila->Fundo - 1] = x;
        Fila->Fundo = (Fila->Fundo % MaxTam) + 1;
    }
}

void Desinfileirar_Fila(TipoFila *Fila, TipoItem *Item)
{
    if(Fila_Vazia(Fila))
    {
        printf("\n\tErro, Fila esta Vazia!...\n");
    }
    else
    {
        *Item = Fila->Item[Fila->Frente - 1];
        Fila->Frente = (Fila->Frente % MaxTam) + 1;
    }
}

void Encontrar_Maior_e_Menor_Elemento_eMedia(TipoFila *Fila)
{
    TipoFila Aux;
    TipoItem Item;
    int Maior = 0, Menor = Fila->Item[Fila->Frente].chave;
    float Media = 0, Soma = 0;

    Iniciar_Fila(&Aux);


    while(!Fila_Vazia(Fila))
    {
        Desinfileirar_Fila(Fila, &Item);

        Enfileirar_Fila(Item, &Aux);

        if(Item.chave > Maior)
        {
            Maior = Item.chave;
        }

        if(Item.chave < Menor)
        {
            Menor = Item.chave;
        }

        Soma += Item.chave;

    }

    Media = Soma / (MaxTam - 1);

    Iniciar_Fila(Fila);

    while(!Fila_Vazia(&Aux))
    {
        Desinfileirar_Fila(&Aux, &Item);

        Enfileirar_Fila(Item, Fila);
    }

    Imprimir_Fila(*Fila);

    printf("\n\n\tMaior Elemento da Fila: %d\n\tMenor Elemento da Fila: %d\n\tSoma dos Elementos da Fila: %.2f\n\tMédia dos Elementos da Fila: %.2f\n\n",Maior,Menor,Soma,Media);
}

void Imprimir_Fila(TipoFila Fila)
{
    printf("\n\t--------------------Fila--------------------\n\n");

    int Aux = 0;

    for(Aux = Fila.Frente - 1; Aux < Fila.Fundo - 1; Aux++)
    {
        printf("\t%d,",Fila.Item[Aux].chave);
    }

    printf("\n\n\t--------------------------------------------\n");
}
