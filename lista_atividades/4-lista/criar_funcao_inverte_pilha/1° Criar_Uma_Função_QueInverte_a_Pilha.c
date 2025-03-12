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
    Apontador Topo,Primeiro, Ultimo;

} TipoPilha, TipoLista;



int Menu_Pilha(int Opcao);

void Inicia_Pilha(TipoPilha *Pilha);

int Pilha_Vazia(TipoPilha Pilha);

void Iniciar_Lista(TipoLista *Lista);

int Lista_Vazia(TipoLista Lista);

int Insere_Lista(TipoLista *Lista, TipoItem x);

void Empilhar_aPilha(TipoItem x, TipoPilha *Pilha);

void Inverter_Pilha(TipoPilha *Pilha, TipoLista *Lista);

void Retira_Lista(Apontador p, TipoLista *Lista, TipoItem *Itens);

void Desempilhar_aPilha(TipoPilha *Pilha, TipoItem *Item);

void Imprime_Pilha(TipoPilha Pilha);

void Imprime_Lista(TipoLista Lista);


void main()
{
    setlocale(LC_ALL,"portuguese");

    TipoPilha Pilha;
    TipoLista Lista;
    TipoItem x, Item;
    TipoChave chave;

    int Opcao = 0, Verificador = 0;
    int Quant_Elementos = 0;

    while(Opcao != 7)
    {
        Opcao = Menu_Pilha(Opcao);

        switch (Opcao)
        {
        case 1:

            Inicia_Pilha(&Pilha);
            Iniciar_Lista(&Lista);

            printf("\n\tPilha e Lista Inicializadas!...\n");
            Verificador = 1;

            break;

        case 2:

            if(Verificador == 1)
            {
                if(Pilha_Vazia(Pilha))
                {
                    printf("\n\tA Pilha está Vazia, Pode Empilhar!...\n\n\n");

                    for(int i = 0; i < MaxTam; i++)
                    {
                        printf("\n\tDigite o %d° Elemento da Pilha: ",i + 1);
                        fflush(stdin);
                        scanf("%d",&x);

                        Empilhar_aPilha(x, &Pilha);
                    }
                    system("cls");
                }
            }
            break;

        case 3:

            if(Verificador == 1)
            {
                if(Pilha_Vazia(Pilha))
                {
                    printf("\n\tA Pilha está Vazia, não tem como inverter!...\n\n\n");

                }
                else
                {
                    Inverter_Pilha(&Pilha, &Lista);
                }
            }
            else
            {
                printf("\n\tA Pilha não foi Inicializada!...\n");
            }

            break;

        case 4:

            if(Verificador == 1)
            {
                if(Pilha_Vazia(Pilha))
                {
                    printf("\n\tA Pilha está Vazia, não tem como Desempilhar!...\n\n\n");

                }
                else
                {
                    printf("\n\tInforme quantos elementos, gostaria de desempilhar da Pilha: ");
                    fflush(stdin);
                    scanf("%d",&Quant_Elementos);

                    for(int i = 0; i < Quant_Elementos; i++)
                    {
                      Desempilhar_aPilha(&Pilha, &Item);
                    }
                }
            }
            else
            {
                printf("\n\tA Pilha não foi Inicializada!...\n");
            }

            break;

        case 5:

            if(Verificador == 1)
            {
                if(Pilha_Vazia(Pilha))
                {
                    printf("\n\tA Pilha está Vazia, não tem Elementos!...\n\n\n");

                }
                else
                {
                    printf("\n\t--------------------Pilha--------------------\n\n");

                    Imprime_Pilha(Pilha);
                }
            }
            else
            {
                printf("\n\tA Pilha não foi Inicializada!...\n");
            }

            break;

        case 6:

            if(Verificador == 1)
            {
                if(Lista_Vazia(Lista))
                {
                    printf("\n\tA Lista está Vazia, não tem Elementos!...\n\n\n");

                }
                else
                {
                    printf("\n\t--------------------Lista--------------------\n\n");
                    Imprime_Lista(Lista);
                }
            }
            else
            {
                printf("\n\tA Lista não foi Inicializada!...\n");
            }

            break;

        default:

            printf("\n\tPrograma Finalizado!...\n");

            break;
        }
    }

}

int Menu_Pilha(int Opcao)
{
    printf("\n\n\t------------Inverter Pilha------------\n\n");

    do
    {
        printf("\n\t1 - Iniciar Pilha");
        printf("\n\t2 - Empilhar a Pilha");
        printf("\n\t3 - Inverter a Pilha");
        printf("\n\t4 - Desenpilhar a Pilha");
        printf("\n\t5 - Imprimir Pilha");
        printf("\n\t6 - Imprimir Lista");
        printf("\n\t7 - Sair");
        printf("\n\tEntrada: ");
        fflush(stdin);
        scanf("%d",&Opcao);
        system("cls");

    }
    while(Opcao > 7 || Opcao < 1);

    return Opcao;
}

void Inicia_Pilha(TipoPilha *Pilha)
{
    Pilha->Topo = - 1;
}

int Pilha_Vazia(TipoPilha Pilha)
{
    return (Pilha.Topo == - 1);
}

void Iniciar_Lista(TipoLista *Lista)
{
    Lista->Primeiro = InicioVetor;
    Lista->Ultimo = Lista->Primeiro;
}

int Lista_Vazia(TipoLista Lista)
{
    return Lista.Primeiro == Lista.Ultimo;
}

int Insere_Lista(TipoLista *Lista, TipoItem x)
{
    if(Lista->Ultimo > MaxTam - 1)
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

void Inverter_Pilha(TipoPilha *Pilha, TipoLista *Lista)
{
    TipoItem x;
    Apontador p = 1;

    printf("\n\n\t*******************Elementos da Pilha*********************\n\n");

    Imprime_Pilha(*Pilha);

    while(!Pilha_Vazia(*Pilha))
    {
        Desempilhar_aPilha(Pilha, &x);

        Insere_Lista(Lista, x);
    }

    printf("\n\t************Lista com os Elementos da Pilha**************\n\n");

    Imprime_Lista(*Lista);

    while(!Lista_Vazia(*Lista))
    {
        Retira_Lista(p, Lista, &x);

        Empilhar_aPilha(x, Pilha);
    }

    printf("\n\n\t********************Pilha Invertida**********************\n\n");

    Imprime_Pilha(*Pilha);
}

void Retira_Lista(Apontador p, TipoLista *Lista, TipoItem *Itens)
{
    int Aux;

    if(Lista_Vazia(*Lista) || p - 1 >= Lista->Ultimo)
    {
        printf("\n\tLista Cheia!");
        return;
    }

    *Itens = Lista->Item[p - 1];

    for(Aux = p; Aux < Lista->Ultimo; Aux++)
    {
        Lista->Item[Aux -1] = Lista->Item[Aux];
    }
    Lista->Ultimo--;

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

    while(Pilha.Topo != -1)
    {
        printf("\n\t%d,", Pilha.Item[Pilha.Topo].chave);
        Pilha.Topo--;
    }
    printf("\n\n");
}

void Imprime_Lista(TipoLista Lista)
{
    int Aux;

    for(Aux = Lista.Primeiro; Aux < Lista.Ultimo; Aux++)
    {
        printf("\t");
        printf("%d,", Lista.Item[Aux].chave);
    }
    printf("\n\n");
}
