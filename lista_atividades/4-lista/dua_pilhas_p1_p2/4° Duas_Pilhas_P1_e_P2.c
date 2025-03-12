#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define InicioVetor 0
#define MaxTam 5

typedef int Apontador;
typedef int TipoChave;

typedef struct
{
    TipoChave chave;

} TipoItem;

typedef struct
{
    TipoItem Item[MaxTam];
    Apontador Topo, Primeiro, Ultimo;

} TipoPilha, TipoLista;

int Menu_Pilha(int Opcao);

void Inicia_Pilha(TipoPilha *Pilha1);
void Iniciar_Lista(TipoLista *Lista);

int Pilha1_Vazia(TipoPilha Pilha1);
int Lista_Vazia(TipoLista Lista);

void Empilhar_aPilha1(TipoItem x, TipoPilha *Pilha1);
int Insere_Lista(TipoItem x,TipoLista *Lista);

void Desempilhar_aPilha(TipoPilha *Pilha, TipoItem *Item);
void Retira_Lista(Apontador p, TipoLista *Lista, TipoItem *Item);

void Transferir_Elementos_Mantendo_Aorderm(TipoPilha *Pilha1, TipoPilha *Pilha2, TipoLista *Lista);

void Imprime_Pilha1(TipoPilha Pilha1);
void Imprime_Pilha2(TipoPilha Pilha2);


void main()
{
    setlocale(LC_ALL,"portuguese");

    TipoPilha Pilha1, Pilha2;
    TipoLista Lista;
    TipoItem x;

    int Opcao = 0, verificador = 0;

    while(Opcao != 6)
    {
        Opcao = Menu_Pilha(Opcao);

        switch(Opcao)
        {
        case 1:

            Inicia_Pilha(&Pilha1);
            Inicia_Pilha(&Pilha2);
            Iniciar_Lista(&Lista);
            verificador = 1;

            printf("\n\tPilha e Lista Inicializadas!...\n\n");

            break;

        case 2 :

            if(verificador == 1)
            {
                if(Pilha1_Vazia(Pilha1))
                {
                    printf("\n\tPilha Vazia, pode inserir elementos!...\n\n");
                    printf("\n\tQuantos Elementos a Pilha vai ter? ");
                    fflush(stdin);
                    scanf("%d",&Opcao);

                    for(int i = 0; i < Opcao; i++)
                    {
                        printf("\n\tInforme o %d° Elemento da Pilha: ",i + 1);
                        fflush(stdin);
                        scanf("%d",&x);

                        Empilhar_aPilha1(x, &Pilha1);
                    }

                }
                else
                {
                    if(Pilha1.Topo < MaxTam)
                    {
                        printf("\n\tFalta %d Elementos para chegar no Topo\n",Pilha1.Topo);
                        printf("\n\tPode inserir na Pilha");

                        for(int i = Pilha1.Topo; i < MaxTam; i++)
                        {
                            printf("\n\tInforme o %d° Elemento da Pilha: ",i + 1);
                            fflush(stdin);
                            scanf("%d",&x);

                            Empilhar_aPilha1(x, &Pilha1);
                        }

                    }
                }
            }
            else
            {
                printf("\n\tA Pilha não foi Inicializada!...\n\n");
            }

            break;

        case 3:

             if(verificador == 1)
            {
                if(Pilha1_Vazia(Pilha1))
                {
                    printf("\n\tPilha 1 e Pilha 2 Vazias!...\n\n");
                }
                else
                {
                    Transferir_Elementos_Mantendo_Aorderm(&Pilha1, &Pilha2, &Lista);
                }
            }
            else
            {
                printf("\n\tA Pilha 1 e Pilha 2 não foram Inicializadas!...\n\n");
            }

            break;

        case 4:

            if(verificador == 1)
            {
                if(Pilha1_Vazia(Pilha1))
                {
                    printf("\n\tPilha 1 Vazia!...\n\n");
                }
                else
                {
                    printf("\n\t***************Pilha 1***************\n\n");

                    Imprime_Pilha1(Pilha1);
                }
            }
            else
            {
                printf("\n\tA Pilha 1 não foi Inicializada!...\n\n");
            }


            break;

        case 5:

            if(verificador == 1)
            {
                if(Pilha1_Vazia(Pilha2))
                {
                    printf("\n\tPilha 2 Vazia!...\n\n");
                }
                else
                {
                    printf("\n\n\t************Elementos Transferidos para Pilha 2**************\n\n");

                    Imprime_Pilha2(Pilha2);
                }
            }
            else
            {
                printf("\n\tA Pilha 1 não foi Inicializada!...\n\n");
            }

            break;

        default:

            printf("\n\tPrograma Finalizado!...\n\n");
        }
    }
}

int Menu_Pilha(int Opcao)
{
    printf("\n\t----------Transferir Elementos para Pilha 2----------\n\n");

    do
    {
        printf("\n\t1 - Iniciar a Pilha");
        printf("\n\t2 - Empilhar a Pilha");
        printf("\n\t3 - Transferir Elementos para Pilha 2");
        printf("\n\t4 - Imprimir Pilha 1");
        printf("\n\t5 - Imprimir Pilha 2");
        printf("\n\t6 - Sair");
        printf("\n\tEntrada: ");
        fflush(stdin);
        scanf("%d",&Opcao);
        system("cls");

    }
    while(Opcao > 6 || Opcao < 1);
}

void Inicia_Pilha(TipoPilha *Pilha)
{
    Pilha->Topo = - 1;
}

void Iniciar_Lista(TipoLista *Lista)
{
    Lista->Primeiro = InicioVetor;
    Lista->Ultimo = Lista->Primeiro;
}


int Pilha1_Vazia(TipoPilha Pilha)
{
    return (Pilha.Topo == - 1);
}

int Lista_Vazia(TipoLista Lista)
{
    return Lista.Primeiro == Lista.Ultimo;
}


void Empilhar_aPilha1(TipoItem x, TipoPilha *Pilha1)
{
    if(Pilha1->Topo == MaxTam - 1)
    {
        printf("\n\tErro pilha cheia!...\n");
    }
    else
    {
        Pilha1->Topo++;
        Pilha1->Item[Pilha1->Topo] = x;
    }
}

int Insere_Lista(TipoItem x, TipoLista *Lista)
{
    if(Lista->Ultimo > MaxTam -1)
    {
        return (0);
    }
    else
    {
        Lista->Item[Lista->Ultimo] = x;
        Lista->Ultimo++;

        return(1);
    }
}

void Desempilhar_aPilha(TipoPilha *Pilha1, TipoItem *Item)
{
    if(Pilha1_Vazia(*Pilha1))
    {
        printf("\n\tErro pilha esta vazia\n");
    }
    else
    {
        *Item = Pilha1->Item[Pilha1->Topo];
        Pilha1->Topo--;
    }
}

void Retira_Lista(Apontador p, TipoLista *Lista, TipoItem *Item)
{
    int Aux;
    if(Lista_Vazia(*Lista) || p - 1 >= Lista->Ultimo)
    {
        return;
    }

    *Item = Lista->Item[p - 1];

    for(Aux = p; Aux < Lista->Ultimo; Aux++)
    {
        Lista->Item[Aux -1] = Lista->Item[Aux];
    }
    Lista->Ultimo--;
}

void Transferir_Elementos_Mantendo_Aorderm(TipoPilha *Pilha1, TipoPilha *Pilha2, TipoLista *Lista)
{
    TipoItem x;
    Apontador p = 5;

    printf("\n\n\t*******************Elementos da Pilha 1*********************\n\n");

    Imprime_Pilha1(*Pilha1);


    while(!Pilha1_Vazia(*Pilha1))
    {
        Desempilhar_aPilha(Pilha1, &x);

        Insere_Lista(x, Lista);
    }

    Inicia_Pilha(Pilha2);

    while(!Lista_Vazia(*Lista))
    {
        Retira_Lista(p, Lista, &x);

        Empilhar_aPilha1(x, Pilha2);
        p--;
    }

    printf("\n\n\t************Elementos Transferidos para Pilha 2**************\n\n");

    Imprime_Pilha2(*Pilha2);

}

void Imprime_Pilha1(TipoPilha Pilha1)
{

    int Aux;

    for(Aux = Pilha1.Topo; Aux > -1; Aux--)
    {
        printf("\n\t%d,", Pilha1.Item[Aux].chave);
    }
    printf("\n\n");
}

void Imprime_Pilha2(TipoPilha Pilha2)
{
    int Aux;

    for(Aux = Pilha2.Topo; Aux > -1; Aux--)
    {
        printf("\n\t%d,", Pilha2.Item[Aux].chave);
    }
    printf("\n\n");
}

