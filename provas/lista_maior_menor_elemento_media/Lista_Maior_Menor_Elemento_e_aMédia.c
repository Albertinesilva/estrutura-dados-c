#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

#define InicioVetor 0
#define Maxtam 6

typedef int Tipochave;

typedef int Apontador;

typedef struct
{
    Tipochave chave;

} TipoItem;

typedef struct
{
    TipoItem itens[Maxtam];
    Apontador Primeiro, Ultimo;

} TipoLista;


int Menu_Lista(int Opcao);

void Iniciar_Lista(TipoLista *Lista);

int Lista_Vazia(TipoLista Lista);

int Insere_Lista(TipoItem x,TipoLista *Lista);

void Encontrar_Maior_e_Menor_Elemento_eMedia(TipoLista *Lista);

void ImprimeLista(TipoLista Lista);


void main()
{
    setlocale(LC_ALL,"portuguese");

    TipoLista Lista;
    TipoItem x;

    int Opcao = 0, Verificador = 0;

    while(Opcao != 5)
    {
        Opcao = Menu_Lista(Opcao);

        switch(Opcao)
        {
        case 1:

            Iniciar_Lista(&Lista);
            Verificador = 1;

            printf("\n\tLista Inicializada com Sucesso!...\n");

            break;

        case 2:

            if(Verificador == 1)
            {

                if(Lista_Vazia(Lista))
                {

                    while(Lista.Ultimo < Maxtam)
                    {
                        printf("\n\tInforme o Elemento para a Lista:  ");
                        fflush(stdin);
                        scanf("%d",&x);
                        system("cls");

                        Insere_Lista(x, &Lista);
                    }

                }
                else
                {
                    printf("\n\tLista Cheia!...\n");
                }
            }
            else
            {
                printf("\n\tA Lista não foi Inicializada!...\n");
            }

            break;

        case 3:

            if(Verificador == 1)
            {

                if(Lista_Vazia(Lista))
                {
                    printf("\n\tLista Vazia!...\n");
                }
                else
                {
                    Encontrar_Maior_e_Menor_Elemento_eMedia(&Lista);
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
                    printf("\n\tLista Vazia!...\n");
                }
                else
                {
                    ImprimeLista(Lista);
                }
            }
            else
            {
                printf("\n\tA Lista não foi Inicializada!...\n");
            }

            break;

        default:

            printf("\n\tPrograma Finalizado com Sucesso!...\n");
        }
    }

}


int Menu_Lista(int Opcao)
{

    printf("\n\n\t----------Lista: Maior Elemento, Menor e a Média----------\n");

    do
    {
        printf("\n\t[1] - Iniciar a Lista");
        printf("\n\t[2] - Inserir Elementos na Lista");
        printf("\n\t[3] - Encontrar o Maior e Menor Elemento e a Média");
        printf("\n\t[4] - Imprimir Lista");
        printf("\n\t[5] - Sair");
        printf("\n\tEntrada:  ");
        fflush(stdin);
        scanf("%d",&Opcao);
        system("cls");

    }
    while(Opcao > 5 || Opcao < 1);

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

int Insere_Lista(TipoItem x, TipoLista *Lista)
{
    if(Lista->Ultimo > Maxtam -1)
    {
        return (0);
    }
    else
    {
        Lista->itens[Lista->Ultimo] = x;
        Lista->Ultimo++;

        return(1);
    }
}

void Encontrar_Maior_e_Menor_Elemento_eMedia(TipoLista *Lista)
{
    int i = 0;
    float Media = 0, Soma = 0;

    int Maior = Lista->itens[0].chave;
    int Menor = Lista->itens[0].chave;


    while( i < Lista->Ultimo )
    {
        if(Lista->itens[i].chave > Maior)
        {
            Maior = Lista->itens[i].chave;
        }

        if(Lista->itens[i].chave < Menor)
        {
            Menor = Lista->itens[i].chave;
        }

        Soma += Lista->itens[i].chave;

        i++;
    }

    Media = Soma / Lista->Ultimo;

    printf("\n\n\tMaior Elemento da Lista: %d\n\tMenor Elemento da Lista: %d\n\tSoma dos Elementos da Lista: %.2f\n\tMédia dos Elementos da Lista: %.2f\n\n",Maior,Menor,Soma,Media);
}

void ImprimeLista(TipoLista Lista)
{

    printf("\n\n\t**************Lista************************\n\n");

    int Aux;
    for(Aux = Lista.Primeiro; Aux < Lista.Ultimo; Aux++)
    {
        printf("\t%d,", Lista.itens[Aux].chave);
    }
    printf("\n\n\t*******************************************\n");
}
