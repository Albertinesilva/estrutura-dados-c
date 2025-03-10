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

void Verifica_sea_Lista_L1eL2e_Igual(TipoLista L1, TipoLista L2);

int main()
{
    setlocale(LC_ALL,"Portuguese");

    TipoLista L1, L2;
    TipoItem Lista1, Lista2;

    int verificador = 0;
    int opcao;
    while(opcao != 7)
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
                printf("\n\tA Lista L2 Esta cheia!...\n");
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

            if(L2.Ultimo == TamMax)
            {
                printf("\n\tA Lista L2 Esta cheia!...\n");
            }
            else
            {
                if(verificador == 1)
                {
                    Insere_Lista2(Lista2, &L2);
                }
                else
                {
                    printf("\n\tA Lista L2 não foi Inicializada!...\n");
                }
            }

            break;

        case 4:

            Verifica_sea_Lista_L1eL2e_Igual(L1, L2);

            break;

        case 5:

            ImprimeLista(L1, L2);

            break;

        case 6:

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
        printf("\n\t3 - Informar elementos de L2");
        printf("\n\t4 - Verificar se L1 é igual a L2");
        printf("\n\t5 - Imprime Listas L1 e L2");
        printf("\n\t6 - Iniciar a Lista Novamente");
        printf("\n\t7 - Sair");
        printf("\n\tEntrada: ");
        scanf("%d",&opcao);
        system("cls");

    }
    while(opcao > 7 || opcao < 1);
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

int Insere_Lista2(TipoItem x2, TipoLista *L2)
{
    int i = 0;

    if(Lista2_Vazia(*L2))
    {

        do
        {
            printf("\n\tInforme o %d Elemento de L1: ",i + 1);
            fflush(stdin);
            scanf("%d",&x2.Num2);

            if(L2->Ultimo > TamMax -1)
            {
                return (0);
            }
            else
            {
                L2->itens[L2->Ultimo] = x2;
                L2->Ultimo++;
            }
            i++;
        }
        while(i < TamMax);

    }
}

void Verifica_sea_Lista_L1eL2e_Igual(TipoLista L1, TipoLista L2)
{
    int Igual=0;
    for(int i = 0; i < TamMax; i++)
    {
        if(L1.itens[i].Num1 == L2.itens[i].Num2)
        {
            Igual++;
        }
    }
    if(Igual == 5)
    {
        printf("\n\n\tA lista L1 é igual a Lista L2!\n");
    }
    else
    {
        printf("\n\n\tA Lista L1 não é igual a Lista L2!\n");
    }
}

void ImprimeLista(TipoLista L1, TipoLista L2)
{
    printf("\n------------------------------Lista L1----------------------------\n\n");
    for(int i = 0; i < L1.Ultimo; i++)
    {
        printf("\t");
        printf("%d,",L1.itens[i].Num1);
    }

    printf("\n\n------------------------------Lista L2----------------------------\n\n");
    for(int i = 0; i < L2.Ultimo; i++)
    {
        printf("\t");
        printf("%d,",L2.itens[i].Num2);
    }

    printf("\n\n");
}

