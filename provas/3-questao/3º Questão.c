#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

#define MaxTam 5

typedef int Apontador;

typedef struct
{
    char Nome[50], Marca_Carro[30];
    char Nome_Carro[30];
    int Placa;

} TipoItem;

typedef struct
{
    TipoItem Item[MaxTam];
    Apontador Topo;

} TipoPilha;


int Menu_Pilha(int Opcao);

void Inicia_Pilha(TipoPilha *Pilha);

int Pilha_Vazia(TipoPilha Pilha);

void Empilhar_aPilha(TipoItem x, TipoPilha *Pilha);

void Cadastro_de_Luiza(TipoItem x, TipoPilha *Pilha);

void Desempilhar_aPilha(TipoPilha *Pilha, TipoItem *Item);

void Retirar_o_Carro_de_Luiza(TipoPilha *Pilha, TipoItem *Item);

void Imprime_Pilha(TipoPilha Pilha);


void main()
{
    setlocale(LC_ALL,"portuguese");

    TipoPilha Pilha;
    TipoItem x, Item;

    int Opcao = 0, Iniciou = 0;

    while(Opcao != 5)
    {
        Opcao = Menu_Pilha(Opcao);

        switch(Opcao)
        {

        case 1:

            Inicia_Pilha(&Pilha);
            Iniciou = Opcao;

            printf("\n\tPilha Inicializada com Sucesso!...\n\n");

            break;

        case 2:

            if(Iniciou == 1)
            {
                if(Pilha_Vazia(Pilha))
                {
                    Cadastro_de_Luiza(x, &Pilha);
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
                if(Pilha_Vazia(Pilha))
                {
                    printf("\n\tPilha Vazia!...\n\n");
                }
                else
                {
                    Retirar_o_Carro_de_Luiza(&Pilha, &Item);

                }
            }
            else
            {
                printf("\n\tA Pilha não foi Inicializada!...\n\n");
            }

            break;

        case 4:

            if(Iniciou == 1)
            {
                if(Pilha_Vazia(Pilha))
                {
                    printf("\n\tPilha Vazia!...\n\n");
                }
                else
                {
                    Imprime_Pilha(Pilha);
                }
            }
            else
            {
                printf("\n\tA Pilha não foi Inicializada!...\n\n");
            }

            break;

        default:

            printf("\n\tPrograma Finalizado!...\n\n");
        }
    }

}

int Menu_Pilha(int Opcao)
{
    printf("\n\n\t---------------Fila de Carros---------------\n\n");

    do
    {
        printf("\n\t1 - Inicializar a Pilha");
        printf("\n\t2 - Empilhar a Pilha");
        printf("\n\t3 - Desempilhar os Carros");
        printf("\n\t4 - Imprimir Pilha");
        printf("\n\t5 - Sair");
        printf("\n\tEntrada: ");
        scanf("%d",&Opcao);
        system("cls");

    }
    while(Opcao > 5 || Opcao < 1);

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

void Cadastro_de_Luiza(TipoItem x, TipoPilha *Pilha)
{
    printf("\n\t---------------Informe os dados do Carro---------------\n");

    bool Continuar_Cadastrando = true;
    int  Opcao = 0;

    while(Continuar_Cadastrando)
    {

        printf("\n\tInforme o Nome Completo:  ");
        fflush(stdin);
        gets(x.Nome);
        system("cls");

        printf("\n\tInforme o nome do carro de %s: ",x.Nome);
        fflush(stdin);
        gets(x.Nome_Carro);
        system("cls");

        printf("\n\tInforme o a Marca  do carro de:  ",x.Nome);
        fflush(stdin);
        gets(x.Marca_Carro);


        printf("\n\t Informe a placa do carro de %s:  ",x.Nome);
        fflush(stdin);
        scanf("%d",&x.Placa);
        system("cls");

        Empilhar_aPilha(x, Pilha);


        printf("\n\tContinuar cadastrando Usuários no SUS?\n\t[1] - Sim\n\t[0] - Não\n\tEntrada:  ");
        fflush(stdin);
        scanf("%d",&Opcao);
        system("cls");

        if(Opcao == 0)
        {
            Continuar_Cadastrando = false;
            printf("\n\tCadastro Finalizado!...\n");
        }
        else
        {
            printf("\n\tPode continuar cadastrando Usuários!...\n");
        }

    }

}

void Retirar_o_Carro_de_Luiza(TipoPilha *Pilha, TipoItem *Item)
{
    int Placa;
    TipoPilha Aux;
    TipoItem x;

    Inicia_Pilha(&Aux);

    printf("\n\tInforme a placa do carro de Luiza:  ");
    fflush(stdin);
    scanf("%d",&Placa);

    while(!Pilha_Vazia(*Pilha))
    {
        Desempilhar_aPilha(Pilha, Item);

        if(Placa == Item->Placa)
        {
            printf("\n\t-------------O CARRO DE LUIZA FOI REMOVIDO COM SUCESSO---------------\n");

            printf("\n\tNome: %s\n\tNome do Carro: %s\n\tMarca do Carro: %s\n\tPlaca do Carro: %d\n\n", Item->Nome, Item->Nome_Carro, Item->Marca_Carro, Item->Placa);
        }
        else
        {
            Empilhar_aPilha(*Item, &Aux);
        }

    }

    while(!Pilha_Vazia(Aux))
    {
        Desempilhar_aPilha(&Aux, Item);

        Empilhar_aPilha(*Item, Pilha);
    }

    printf("\n\t----------Carros que continuar no estacionamento----------\n");

    Imprime_Pilha(*Pilha);

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
        printf("\n\tNome: %s\n\tNome do Carro: %s\n\tMarca do Carro: %s\n\tPlaca do Carro: %d\n\n", Pilha.Item[Aux].Nome, Pilha.Item[Aux].Nome_Carro, Pilha.Item[Aux].Marca_Carro, Pilha.Item[Aux].Placa);
    }
    printf("\n\n");
}
