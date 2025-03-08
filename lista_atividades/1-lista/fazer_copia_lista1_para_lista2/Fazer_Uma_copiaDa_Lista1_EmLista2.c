#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define inicio 0
#define TamMax 5

typedef int TipoChave;
typedef int Apontador;

typedef struct
{
    TipoChave Num1,Num2;

} TipoItem;

typedef struct
{
    TipoItem itens[TamMax];
    Apontador Primeiro, Ultimo;

} TipoLista;

int Menu(int opcao);
void Iniciar_Lista(TipoLista *L1, TipoLista *L2);

int Lista1_Vazia(TipoLista L1);
int Lista2_Vazia(TipoLista L2);

int Insere_Lista1(TipoItem x1, TipoLista *L1);
int Insere_Lista2(TipoItem x2, TipoLista *L2);

void ImprimeLista(TipoLista L1, TipoLista L2);

void Copiar_L1_Para_L2(TipoLista L1, TipoLista *L2);

int main()
{
    setlocale(LC_ALL,"Portuguese");

    TipoLista L1, L2;
    TipoItem Lista1, Lista2;

    int verificador = 0;
    int opcao;
    while(opcao != 5)
    {
        opcao = Menu(opcao);

        switch(opcao)
        {
        case 1:

            if(verificador == 0)
            {
                Iniciar_Lista(&L1, &L2);

                printf("\n\n\tListas L1 e L2, Inicializadas com Sucesso\n\n");
                verificador = 1;
            }
            else
            {
                printf("\n\n\tAs Listas L1 e L2, Já forma Inicializadas\n\n");
            }

            break;

        case 2:

            if(L1.Ultimo == TamMax)
            {
                printf("\n\tA Lista L1 Esta cheia!...\n");
            }
            else
            {

                if(verificador == 1)
                {
                    Insere_Lista1(Lista1, &L1);
                }
                else
                {
                    printf("\n\tA Lista L1 não foi Inicializada!...\n");
                }
            }

            break;

        case 3:

            if(Lista1_Vazia(L1))
            {
                printf("\n\tA lista L1 esta Vazia, não tem como fazer uma copia!...");
            }
            else
            {

                if(L2.Ultimo == TamMax)
                {
                    printf("\n\tA Lista L2 Esta cheia, já foi feito a Copia!...\n");
                }
                else
                {
                    if(verificador == 1)
                    {
                        Copiar_L1_Para_L2(L1, &L2);
                        ImprimeLista(L1, L2);
                    }
                    else
                    {
                        printf("\n\tA Lista L1 não foi Inicializada!...\n");
                    }
                }
            }

            break;

        case 4:

            if(verificador == 1)
            {
                Iniciar_Lista(&L1, &L2);
                printf("\n\tAs Listas L1 e L2 forma iniciadas novamente!...\n\n");
            }
            else
            {
                printf("\n\tAs Listas L1 e L2 Não foram inicializadas, escolha a opção 1!\n\n");
            }

            break;

        default:

            printf("\n\tPrograma Finalizado!\n");

            break;
        }
    }

    return 0;
}

int Menu(int opcao)
{
    printf("\n\n\t---------------Verificar Lista L1---------------\n");

    do
    {
        printf("\n\t1 - Iniciar Lista L1 e L2");
        printf("\n\t2 - Informar elementos de L1");
        printf("\n\t3 - Resultado da Copia de L1 Para L2");
        printf("\n\t4 - Iniciar a Lista Novamente");
        printf("\n\t5 - Sair");
        printf("\n\tEntrada: ");
        scanf("%d",&opcao);
        system("cls");

    }
    while(opcao > 5 || opcao < 1);
}

void Iniciar_Lista(TipoLista *L1, TipoLista *L2)
{
    L1->Primeiro = inicio;
    L1->Ultimo = L1->Primeiro;

    L2->Primeiro = inicio;
    L2->Ultimo = L2->Primeiro;
}

int Lista1_Vazia(TipoLista L1)
{
    return L1.Primeiro == L1.Ultimo;
}

int Lista2_Vazia(TipoLista L2)
{
    return L2.Primeiro == L2.Ultimo;
}

int Insere_Lista1(TipoItem x1, TipoLista *L1)
{
    int i = 0;

    if(Lista1_Vazia(*L1))
    {

        do
        {
            printf("\n\tInforme o %d Elemento de L1: ",i + 1);
            fflush(stdin);
            scanf("%d",&x1.Num1);

            if(L1->Ultimo > TamMax -1)
            {
                return (0);
            }
            else
            {
                L1->itens[L1->Ultimo] = x1;
                L1->Ultimo++;
            }
            i++;
        }
        while(i < TamMax);

    }
}

void Copiar_L1_Para_L2(TipoLista L1, TipoLista *L2)
{
    if(Lista2_Vazia(*L2))
    {
        for(int i = 0; i < TamMax; i++)
        {
            L2->itens[ L2->Ultimo].Num2 = L1.itens[i].Num1;
            L2->Ultimo++;
        }
    }
}

void ImprimeLista(TipoLista L1, TipoLista L2)
{
    printf("\n----------------------------Lista L1--------------------------\n\n");
    for(int i = 0; i < L1.Ultimo; i++)
    {
        printf("\t");
        printf("%d,",L1.itens[i].Num1);
    }

    printf("\n\n\n------------------------Copia de L1 em L2---------------------\n\n");
    for(int i = 0; i < L2.Ultimo; i++)
    {
        printf("\t");
        printf("%d,",L2.itens[i].Num2);
    }

    printf("\n\n");
}
