#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#define InicioVetor 0
#define MaxTam 30

typedef int Apontador;
typedef char TipoChave;

typedef struct
{
    TipoChave chave[30];

} TipoItem;

typedef struct
{
    TipoItem Item[MaxTam];
    Apontador Topo, Primeiro, Ultimo;

} TipoPilha, TipoLista;

int Menu_Pilha(int Opcao);

void Inicia_Pilha(TipoPilha *Pilha);
void Iniciar_Lista(TipoLista *Lista);

int Pilha_Vazia(TipoPilha Pilha);
int Lista_Vazia(TipoLista Lista);

void Empilhar_aPilha(TipoItem x, TipoPilha *Pilha);
int Insere_Lista(TipoItem x,TipoLista *Lista);

void Desempilhar_aPilha(TipoPilha *Pilha, TipoItem *Item);
void Retira_Lista(Apontador p, TipoLista *Lista, TipoItem *Item);

void Imprime_Pilha(TipoPilha Pilha);
void ImprimeLista(TipoLista Lista);


void main()
{
    setlocale(LC_ALL,"portuguese");

    TipoPilha Pilha, Pilha1, Pilha2;
    TipoLista Lista;
    TipoItem x, y, Item;
    Apontador p = 1;

    int Opcao = 0, Iniciou = 0, j = 0;

    while(Opcao != 4)
    {
        Opcao = Menu_Pilha(Opcao);

        switch(Opcao)
        {

        case 1:

            Inicia_Pilha(&Pilha);
            Inicia_Pilha(&Pilha1);
            Inicia_Pilha(&Pilha2);
            Iniciar_Lista(&Lista);
            Iniciou = Opcao;

            printf("\n\tPilha Inicializada com Sucesso!...\n\n");

            break;

        case 2:

            if(Iniciou == 1)
            {
                if(Pilha_Vazia(Pilha))
                {
                    printf("\n\tDigite uma Frase para a Pilha: ");
                    fflush(stdin);
                    gets(x.chave);

                    int tam = strlen(x.chave);

                    for(int i = tam; i >= 0; i--)
                    {
                        y.chave[j] = x.chave[i];
                        j++;
                        Empilhar_aPilha(x, &Pilha);
                        Insere_Lista(x, &Lista);
                    }
                     j = 0;
                    while(j != 7)
                    {
                        Desempilhar_aPilha(&Pilha, &Item);
                        Empilhar_aPilha(Item, &Pilha1);

                        j++;
                        printf("\n\tPilha topo %d",Pilha.Topo);
                    }

                    while(!Pilha_Vazia(Pilha1))
                    {
                        Desempilhar_aPilha(&Pilha1, &Item);
                        Empilhar_aPilha(Item, &Pilha2);

                        j++;
                        printf("\n\tPilha topo %d",Pilha.Topo);
                    }

                    while(!Pilha_Vazia(Pilha))
                    {
                        Desempilhar_aPilha(&Pilha, &Item);
                    }

                    while(!Lista_Vazia(Lista))
                    {
                        Retira_Lista(p, &Lista, &Item);
                        Empilhar_aPilha(Item, &Pilha);

                    }

                }
                else
                {
                    printf("\n\tPilha Cheia!...\n\n");
                }
            }
            else
            {
                printf("\n\tA Pilha não foi Inicializada!...\n\n");
            }

            break;

        case 3:

            if(Iniciou == 1)
            {
                /*if(Pilha_Vazia(Pilha1))
                {
                    printf("\n\tPilha Vazia!...\n\n");
                }
                else
                {
                    printf("\n\t----------Pilha, com a Frase Invertida----------\n\n");

                    Imprime_Pilha(Pilha);

                    printf("\n\tPilha 1\n");
                    Imprime_Pilha(Pilha1);
                }*/

                Imprime_Pilha(Pilha);

                printf("\n\tPilha 1\n");
                Imprime_Pilha(Pilha1);

                printf("\n\tPilha 2\n");
                Imprime_Pilha(Pilha2);
            }
            else
            {
                printf("\n\tA Pilha não foi Inicializada!...\n\n");
            }
            ImprimeLista(Lista);

            break;

        default:

            printf("\n\tPrograma Finalizado!...\n\n");

            break;

        }

    }

}

int Menu_Pilha(int Opcao)
{
    printf("\n\n\t----------Pilha/ Frase Invertida----------\n\n");

    do
    {
        printf("\n\t1 - Inicializar a Pilha");
        printf("\n\t2 - Empilhar a Pilha/ Frase Invertida");
        printf("\n\t3 - Imprimir Pilha");
        printf("\n\t4 - Sair");
        printf("\n\tEntrada: ");
        scanf("%d",&Opcao);
        system("cls");

    }
    while(Opcao > 4 || Opcao < 1);

    return Opcao;
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

int Pilha_Vazia(TipoPilha Pilha)
{
    return (Pilha.Topo == - 1);
}

int Lista_Vazia(TipoLista Lista)
{
    return Lista.Primeiro == Lista.Ultimo;
}

void Empilhar_aPilha(TipoItem x, TipoPilha *Pilha)
{
    if(Pilha->Topo == MaxTam - 1)
    {
        printf("\n\tErro pilha cheia!...\n");
    }
    else
    {
        Pilha->Topo++;
        Pilha->Item[Pilha->Topo] = x;
    }
}

void Desempilhar_aPilha(TipoPilha *Pilha, TipoItem *Item)
{
    if(Pilha_Vazia(*Pilha))
    {
        printf("\n\tErro pilha esta vazia\n");
    }
    else
    {
        *Item = Pilha->Item[Pilha->Topo];
        Pilha->Topo--;
    }
}

void Imprime_Pilha(TipoPilha Pilha)
{

    int Aux;

    for(Aux = Pilha.Topo; Aux > -1; Aux--)
    {
        printf("%c", Pilha.Item[Aux].chave[Aux]);
    }
    printf("\n\n");
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

void ImprimeLista(TipoLista Lista)
{
    int Aux;
    printf("\n\t**************Lista**************\n\n");
    for(Aux = Lista.Primeiro; Aux < Lista.Ultimo; Aux++)
    {
        printf("%c", Lista.Item[Aux].chave[Aux]);
    }
}

