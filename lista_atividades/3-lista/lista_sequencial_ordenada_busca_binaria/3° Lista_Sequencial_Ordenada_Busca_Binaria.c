#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define InicioVetor 0
#define TamMax 10


typedef int TipoChave;

typedef int Apontador;


typedef struct
{
    TipoChave chave;

} TipoItem;

typedef struct
{
    TipoItem Itens[TamMax];
    Apontador Primeiro, Ultimo;

} TipoLista;


int Menu_Lista(int Opcao);

void Iniciar_Lista(TipoLista *Lista);

int Ordenar_Lista(TipoLista *Lista);

int Insere_Lista(TipoItem x, TipoLista *Lista);

int Lista_Vazia(TipoLista Lista);

void Retira_Lista(int Remove, TipoLista *Lista, TipoItem *Item);

int Busca_Lista(TipoLista *Lista, TipoChave chave);

void Imprime_Lista(TipoLista Lista);


void main()
{
    setlocale(LC_ALL,"portuguese");

    TipoLista Lista;
    TipoItem x, Item;
    TipoChave chave;

    int Opcao = 0, Verificador = 0;
    int i = 0, Busca_Result = 0;

    while(Opcao != 6)
    {
        Opcao = Menu_Lista(Opcao);

        switch (Opcao)
        {
        case 1:

            if(Verificador == 1)
            {
                printf("\n\tA Lista já foi Inicializada!...\n\n");
            }
            else
            {
                Iniciar_Lista(&Lista);
                Verificador = 1;
                printf("\n\tLista Inicializada com sucesso!...\n");
            }

            break;

        case 2:

            if(Verificador == 1)
            {
                if(Lista_Vazia(Lista))
                {
                    printf("\n\tA Lista está Vazia, pode inserir Elementos!...\n\n");

                    do
                    {

                        printf("\n\tInforme o %d° Elemento para a Lista: ",i + 1);
                        fflush(stdin);
                        scanf("%d",&x.chave);

                        Insere_Lista(x, &Lista);
                        i++;

                    }
                    while(i < TamMax);
                    system("cls");

                }
                else
                {
                    if(Lista.Ultimo < TamMax)
                    {
                        printf("\n\tA Lista está com %d elementos, já está Cheia!...",Lista.Ultimo);
                    }

                }
            }
            else
            {
                printf("\n\tFavor Inicializar a Lista!\n");
            }
            break;

        case 3:

            if(Verificador == 1)
            {
                if(Lista_Vazia(Lista))
                {
                    printf("\n\tA Lista está Vazia!...\n");
                }
                else
                {
                    Imprime_Lista(Lista);

                    printf("\n\t--------------------------------------------------------------------------\n\n\n");
                    printf("\n\tInforme um Elemento para a Busca: ");
                    fflush(stdin);
                    scanf("%d",&chave);
                    system("cls");

                    Busca_Result =  Busca_Lista(&Lista, chave);

                    if(Busca_Result == - 1)
                    {
                        printf("\n\tElemento %d não existe!\n",chave);
                    }
                    else
                    {
                        printf("\n\tElemento %d encontrado na posição %d com sucesso!\n",Lista.Itens[Busca_Result - 1].chave,Busca_Result);
                    }
                }
            }
            else
            {
                printf("\n\tA Lista não foi Inicializada!...\n");
            }


            break;

        case 4:

            if(Verificador == 1)
            {
                if(Lista_Vazia(Lista))
                {
                    printf("\n\tA Lista está Vazia!...\n");
                }
                else
                {
                    Imprime_Lista(Lista);

                    printf("\n\tGostaria de Eliminar o mesmo Elemento da Busca?\n\t1 - Sim\n\t2 - Não\n\tEntrada: ");
                    fflush(stdin);
                    scanf("%d",&Opcao);
                    system("cls");

                    if(Opcao == 1)
                    {
                        Retira_Lista(Busca_Result, &Lista, &Item);
                    }
                    else
                    {
                        printf("\n\tDigite o Elemento desejado: ");
                        fflush(stdin);
                        scanf("%d",&Busca_Result);
                        system("cls");

                        Retira_Lista(Busca_Result, &Lista, &Item);
                    }

                    Imprime_Lista(Lista);

                    printf("\n\tElemento %d Removido com sucesso!...\n",Item);
                    printf("\n\t--------------------------------------------------------------------------\n\n\n");
                }
            }
            else
            {
                printf("\n\tA Lista não foi Inicializada!...\n");
            }

            break;

        case 5:

            Imprime_Lista(Lista);

            break;

        default:

            printf("\n\tPrograma Finalizado!...\n");

            break;

        }
    }
}

int Menu_Lista(int Opcao)
{
    printf("\n\n\t---------------Busca Binária---------------\n\n");

    do
    {
        printf("\n\t1 - Iniciar Lista");
        printf("\n\t2 - Inserir Elementos na Lista");
        printf("\n\t3 - Realizar Buca na Lista");
        printf("\n\t4 - Remover itens da Lista");
        printf("\n\t5 - Imprimir Lista");
        printf("\n\t6 - Sair");
        printf("\n\tEntrada:  ");
        fflush(stdin);
        scanf("%d",&Opcao);
        system("cls");

    }
    while(Opcao > 6  || Opcao < 1);

    return Opcao;
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

int Ordenar_Lista(TipoLista *Lista)
{
    int i, j;
    TipoItem Temp;

    for(i = 0; i < Lista->Ultimo; i++)
    {
        for(j = 0; j < Lista->Ultimo - 1; j++)
        {
            if(Lista->Itens[j].chave > Lista->Itens[j + 1].chave)
            {
                Temp = Lista->Itens[j];
                Lista->Itens[j] = Lista->Itens[j + 1];
                Lista->Itens[j + 1] = Temp;
            }
        }
    }

}

int Insere_Lista(TipoItem x, TipoLista *Lista)
{

    if(Lista->Ultimo > TamMax - 1)
    {
        printf("\n\tLista Cheia!...\n\n");

        return 0;
    }

    else
    {
        Lista->Itens[Lista->Ultimo] = x;
        Lista->Ultimo++;
        Ordenar_Lista(Lista);
    }
}

int Busca_Lista(TipoLista *Lista, TipoChave chave)
{
    int Inicio, Meio, Final, i, Comparacoes;

    Inicio = Lista->Primeiro;
    Final = Lista->Ultimo - 1;


    while(Inicio <= Final)
    {
        Meio = (Inicio + Final)/2;

        if(chave == Lista->Itens[Meio].chave)
        {
            return  Meio + 1;
        }
        if(chave < Lista->Itens[Meio].chave)
        {
            Final = Meio - 1; //Busca na metade da esquerda
        }
        else
        {
            Inicio = Meio + 1; //Busca na metade da direita
        }

    }

    return - 1; // Elemento não encontrado

}

void Retira_Lista(int Remove, TipoLista *Lista, TipoItem *Item)
{
    int Aux;

    if(Lista_Vazia(*Lista) || Remove - 1 >= Lista->Ultimo)
    {
        return;
    }

    *Item = Lista->Itens[Remove - 1];

    for(Aux = Remove; Aux < Lista->Ultimo; Aux++)
    {
        Lista->Itens[Aux - 1] = Lista->Itens[Aux];
    }
    Lista->Ultimo--;
}

void Imprime_Lista(TipoLista Lista)
{
    int Aux;

    printf("\n\t------------------------------Lista Ordenada------------------------------\n\n\n");

    for(Aux = Lista.Primeiro; Aux < Lista.Ultimo; Aux++)
    {
        printf("\t%d,",Lista.Itens[Aux].chave);
    }
    printf("\n\n");

}
