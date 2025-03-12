#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define InicioVetor 0
#define MaxTam 5
#define MaxTam2 10

typedef int Apontador;
typedef int TipoChave;

typedef struct
{
    TipoChave chave;

} TipoItem;

typedef struct
{
    TipoItem Item[MaxTam], Item2[MaxTam2];
    Apontador Topo, Primeiro, Ultimo;

} TipoPilha, TipoLista;


int Menu_Pilha(int Opcao);

void Inicia_Pilha1_e_Pilha2(TipoPilha *Pilha1, TipoPilha *Pilha2, TipoPilha *Pilha3);
void Iniciar_Lista(TipoLista *Lista);

int Pilha1_Vazia(TipoPilha Pilha1);
int Pilha2_Vazia(TipoPilha Pilha2);
int Pilha3_Vazia(TipoPilha Pilha3);
int Lista_Vazia(TipoLista Lista);

void Empilhar_aPilha1(TipoItem Item, TipoPilha *Pilha1);
void Empilhar_aPilha2(TipoItem x, TipoPilha *Pilha2);
void Empilhar_aPilha3(TipoItem x, TipoPilha *Pilha3);
int Insere_Lista(TipoItem x,TipoLista *Lista);

void Desempilhar_aPilha1(TipoPilha *Pilha1, TipoItem *Item);
void Desempilhar_aPilha2(TipoPilha *Pilha2, TipoItem *Item);
void Retira_Lista(Apontador p, TipoLista *Lista, TipoItem *Item);

void Imprimir_Pilha1_e_Pilha2(TipoPilha Pilha1, TipoPilha Pilha2);
void ImprimeLista(TipoLista Lista);
void Imprimir_Pilha3(TipoPilha Pilha3);

void Transferir_Elementos_Para_Pilha3(TipoPilha *Pilha3, TipoPilha *Pilha1, TipoPilha *Pilha2);


void main()
{
    setlocale(LC_ALL,"portuguese");

    TipoPilha Pilha1, Pilha2, Pilha3;
    TipoLista Lista;
    TipoItem x, Item;
    TipoChave chave;
    Apontador p = 1;

    int Opcao = 0, Verificador = 0, i = 0;
    int Quant_Elementos = 0;

    while(Opcao != 7)
    {
        Opcao = Menu_Pilha(Opcao);

        switch (Opcao)
        {

        case 1:

            Inicia_Pilha1_e_Pilha2(&Pilha1, &Pilha2, &Pilha3);
            printf("\n\tPilha 1 e Pilha 2 Inicializada com Sucesso!...\n\n");

            Iniciar_Lista(&Lista);
            printf("\n\tA Lista Também foi Inicializada com Sucesso!...\n\n");
            Verificador = 1;

            break;

        case 2:

            if(Verificador == 1)
            {
                if(Pilha1_Vazia(Pilha1))
                {
                    printf("\n\tA Pilha 1 está Vazia, pode Empilhar!...\n\n");

                    while(i != 5)
                    {
                        printf("\n\tInforme o %d° Elemento da Pilha 1: ",i + 1);
                        fflush(stdin);
                        scanf("%d",&x.chave);

                        Insere_Lista(x, &Lista);
                        i++;
                    }

                    i = 0;
                    while(i != 5)
                    {
                        Retira_Lista(p, &Lista, &Item);

                        Empilhar_aPilha1(Item, &Pilha1);

                        i++;
                    }

                }
                else
                {
                    printf("\n\tA Pilha 1 está Cheia!...\n\n");
                }

                printf("\n\tGostaria de Empilhar a Pilha 2?\n\t1 - Sim\n\t0 - Não\n\tEntrada: ");
                fflush(stdin);
                scanf("%d",&Opcao);
                system("cls");

                if(Opcao == 1)
                {
                    i = 0;
                    if(Pilha2_Vazia(Pilha2))
                    {
                        printf("\n\n\tA Pilha 2 está Vazia, pode Empilhar!...\n\n");

                        while(i != 5)
                        {
                            printf("\n\tInforme o %d° Elemento da Pilha 2: ",i + 1);
                            fflush(stdin);
                            scanf("%d",&x.chave);

                            Insere_Lista(x, &Lista);
                            i++;
                        }
                        system("cls");

                        i = 0;
                        while(i != 5)
                        {
                            Retira_Lista(p, &Lista, &Item);

                            Empilhar_aPilha2(Item, &Pilha2);

                            i++;
                        }

                    }
                    else
                    {
                        printf("\n\tA Pilha 2 está Cheia!...\n\n");
                    }
                }
            }
            else
            {
                printf("\n\tA Pilha 1 e a Pilha 2 não foram Inicializadaz!...\n");
            }

            break;

        case 3:

            if(Verificador == 1)
            {
                if(Pilha1_Vazia(Pilha1))
                {
                    printf("\n\tA Pilha 1 está Vazia, não tem Elementos para Desempilhar!...\n\n");
                }
                else
                {
                    printf("\n\tDeseja Desempilhar Quantos Elementos da Pilha 1: ");
                    fflush(stdin);
                    scanf("%d",Quant_Elementos);

                    for(int y = 0; y < Quant_Elementos; y++)
                    {
                        Desempilhar_aPilha1(&Pilha1, &Item);
                    }
                }
                if(Pilha2_Vazia(Pilha2))
                {
                    printf("\n\tA Pilha 2 está Vazia, não tem Elementos para Desempilhar!...\n\n");
                }
                else
                {
                    printf("\n\tDeseja Desempilhar Quantos Elementos da Pilha 2: ");
                    fflush(stdin);
                    scanf("%d",Quant_Elementos);

                    for(int y = 0; y < Quant_Elementos; y++)
                    {
                        Desempilhar_aPilha2(&Pilha2, &Item);
                    }
                }
            }
            else
            {
                printf("\n\tA Pilha 1 e a Pilha 2 não foram Inicializadas!...\n");
            }

            break;

        case 4:

            if(Verificador == 1)
            {
                Transferir_Elementos_Para_Pilha3(&Pilha3, &Pilha1, &Pilha2);
            }
            else
            {
                printf("\n\tAs Pilhas não foram Inicializadas!...\n");
            }


            break;

        case 5:

            if(Pilha1_Vazia(Pilha1) && Pilha2_Vazia(Pilha2))
            {
                printf("\n\tPilha 1 e Pilha 2 Vazias!...\n");
            }
            else
            {
                Imprimir_Pilha1_e_Pilha2(Pilha1, Pilha2);
            }

            break;

        case 6:

            if(Pilha3_Vazia(Pilha3))
            {
                printf("\n\tPilha 3 Vazia!...\n");
            }
            else
            {
                printf("\n\n\t---------------Lista 3 Ordenada Decrescentemente---------------\n\n");

                Imprimir_Pilha3(Pilha3);
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
    printf("\n\n\n\t-------------Pilhas Ordenadas/Transfere Elementos para a Terceira Pilha-------------\n\n");

    do
    {
        printf("\n\t1 - Iniciar a Pilha");
        printf("\n\t2 - Empilhar a Pilha");
        printf("\n\t3 - Desempilhar a Pilha");
        printf("\n\t4 - Transferir os Elementos das Pilhas 1 e 2, ordenada para a Terceira Pilha");
        printf("\n\t5 - Imprimir Pilha 1 e Imprimir Pilha 2");
        printf("\n\t6 - Imprimir Pilha 3 Ordenada Decrescentemente");
        printf("\n\t7 - Sair");
        printf("\n\tEntrada: ");
        fflush(stdin);
        scanf("%d",&Opcao);
        system("cls");

    }
    while(Opcao > 7 || Opcao < 1);

    return Opcao;

}

void Inicia_Pilha1_e_Pilha2(TipoPilha *Pilha1, TipoPilha *Pilha2, TipoPilha *Pilha3)
{
    Pilha1->Topo = - 1;

    Pilha2->Topo = - 1;

    Pilha3->Topo = - 1;
}

void Iniciar_Lista(TipoLista *Lista)
{
    Lista->Primeiro = InicioVetor;
    Lista->Ultimo = Lista->Primeiro;
}

int Pilha1_Vazia(TipoPilha Pilha1)
{
    return (Pilha1.Topo == - 1);
}

int Pilha2_Vazia(TipoPilha Pilha2)
{
    return (Pilha2.Topo == - 1);
}

int Pilha3_Vazia(TipoPilha Pilha3)
{
    return (Pilha3.Topo == - 1);
}

int Lista_Vazia(TipoLista Lista)
{
    return Lista.Primeiro == Lista.Ultimo;
}

void Empilhar_aPilha1(TipoItem Item, TipoPilha *Pilha1)
{

    if(Pilha1->Topo == MaxTam - 1)
    {
        printf("\n\tErro pilha cheia!...\n");
    }
    else
    {
        Pilha1->Topo++;
        Pilha1->Item[Pilha1->Topo] = Item;
    }

}

void Empilhar_aPilha2(TipoItem x, TipoPilha *Pilha2)
{
    if(Pilha2->Topo == MaxTam - 1)
    {
        printf("\n\tErro pilha cheia!...\n");
    }
    else
    {
        Pilha2->Topo++;
        Pilha2->Item[Pilha2->Topo] = x;
    }
}

void Empilhar_aPilha3(TipoItem x, TipoPilha *Pilha3)
{
    if(Pilha3->Topo == MaxTam2 - 1)
    {
        printf("\n\tErro pilha cheia!...\n");
    }
    else
    {
        Pilha3->Topo++;
        Pilha3->Item2[Pilha3->Topo] = x;
    }
}

int Insere_Lista(TipoItem x, TipoLista *Lista)
{

    int y = Lista->Ultimo;

    if(Lista->Ultimo > MaxTam2 - 1)
    {
        return (0);
    }
    else
    {
        while(y > 0 && x.chave < Lista->Item2[y - 1].chave)
        {
            Lista->Item2[y] = Lista->Item2[y - 1];
            y--;
        }

        Lista->Item2[y] = x;
        Lista->Ultimo++;

        return(1);
    }

}

void Desempilhar_aPilha1(TipoPilha *Pilha1, TipoItem *Item)
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

void Desempilhar_aPilha2(TipoPilha *Pilha2, TipoItem *Item)
{
    if(Pilha1_Vazia(*Pilha2))
    {
        printf("\n\tErro pilha esta vazia\n");
    }
    else
    {
        *Item = Pilha2->Item[Pilha2->Topo];
        Pilha2->Topo--;
    }
}

void Retira_Lista(Apontador p, TipoLista *Lista, TipoItem *Item)
{
    int Aux;
    if(Lista_Vazia(*Lista) || p-1 >= Lista->Ultimo)
    {
        return;
    }

    *Item = Lista->Item2[p - 1];

    for(Aux = p; Aux < Lista->Ultimo; Aux++)
    {
        Lista->Item2[Aux -1] = Lista->Item2[Aux];
    }
    Lista->Ultimo--;
}

void Imprimir_Pilha1_e_Pilha2(TipoPilha Pilha1, TipoPilha Pilha2)
{

    printf("\n\n\t********************Pilha 1********************\n\n");

    int i = 0;

    for(i = 0; i <= Pilha1.Topo; i++)
    {
        printf("\n\t%d,",Pilha1.Item[i].chave);
    }

    printf("\n\n\t********************Pilha 2********************\n\n");

    int y = 0;

    for(y = 0; y <= Pilha2.Topo; y++)
    {
        printf("\n\t%d,",Pilha2.Item[y].chave);
    }
    printf("\n\n");
}

void ImprimeLista(TipoLista Lista)
{
    int Aux;
    printf("\n\t*******************Lista*******************\n\n");

    for(Aux = Lista.Primeiro; Aux < Lista.Ultimo; Aux++)
    {
        printf("\t");
        printf("%d,", Lista.Item2[Aux].chave);
    }
}

void Imprimir_Pilha3(TipoPilha Pilha3)
{
    int y = 0;

    for(y = 0; y <= Pilha3.Topo; y++)
    {
        printf("\n\t%d,",Pilha3.Item2[y].chave);
    }
    printf("\n\n");
}



void Transferir_Elementos_Para_Pilha3(TipoPilha *Pilha3, TipoPilha *Pilha1, TipoPilha *Pilha2)
{

    TipoItem Item;

    if(Pilha3_Vazia(*Pilha3))
    {
        printf("\n\tPilha 3 Vazia!...\n");
    }
    else
    {

        while(Pilha3->Topo != 9)
        {
            if(Pilha1->Item[Pilha1->Topo].chave > Pilha2->Item[Pilha2->Topo].chave)
            {
                Desempilhar_aPilha1(Pilha1, &Item);
                Empilhar_aPilha3(Item, Pilha3);
            }
            else
            {
                Desempilhar_aPilha2(Pilha2, &Item);
                Empilhar_aPilha3(Item, Pilha3);
            }

        }
        printf("\n\n\t---------------Lista 3 Ordenada Decrescentemente---------------\n\n");

        Imprimir_Pilha3(*Pilha3);
    }

}
