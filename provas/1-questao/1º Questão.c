#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

#define InicioVetor 0
#define Maxtam 3

typedef int Apontador;

typedef struct
{
    char Nome[50], Rg[15];
    char Nome_Mae[50];
    char Cpf[15], Endereco[30];

} TipoItem;


typedef struct
{
    TipoItem itens[Maxtam];
    Apontador Primeiro, Ultimo;

} TipoLista;


int Menu_Lista(int Opcao);

void Iniciar_Lista(TipoLista *Lista);

int Lista_Vazia(TipoLista Lista);

int Insere_Lista(TipoItem x, TipoLista *Lista);

void Cadastro_de_Luiza(TipoItem x, TipoLista *Lista);

void Retira_Lista(Apontador p, TipoLista *Lista, TipoItem *Item);

void ImprimeLista(TipoLista Lista);


int main()
{
    setlocale(LC_ALL,"portuguese");

    TipoLista Lista;
    TipoItem x, Item;
    Apontador p;


    int Opcao = 0, Verificador = 0;

    while(Opcao != 5)
    {
        Opcao = Menu_Lista(Opcao);

        switch(Opcao)
        {
        case 1:

            Iniciar_Lista(&Lista);
            Verificador = 1;

            printf("\n\tCadastro de Luiza Inicializado!...\n");

            break;

        case 2:

            if(Verificador == 1)
            {

                if(Lista_Vazia(Lista) || Lista.Ultimo < Maxtam - 1)
                {
                    Cadastro_de_Luiza(x, &Lista);
                }
                else
                {
                    printf("\n\tLista do SUS Cheia!...\n");
                }
            }
            else
            {
                printf("\n\tA Lista para o cadasytro de Luiza não foi Inicializada!...\n");
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
                    printf("\n\tInforme um elemento da lista de cadastro que deseja remover:  ");
                    fflush(stdin);
                    scanf("%d",&p);
                    Retira_Lista(p, &Lista, &Item);

                     printf("\n\tNome: %s\n\tNome da Mãe: %s\n\tCPF: %s\n\tRG: %s\n\tEndereço: %s\n\n", Item.Nome, Item.Nome_Mae,Item.Cpf, Item.Rg, Item.Endereco);
                     printf("\n\tRemovido com Sucesso!\n");
                }
            }
            else
            {
                printf("\n\tA Lista para o cadasytro de Luiza não foi Inicializada!...\n");
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
                printf("\n\tA Lista para o cadasytro de Luiza não foi Inicializada!...\n");
            }

            break;

        default:

            printf("\n\tProgama Finalizado!...\n");
        }
    }

    return 0;
}

int Menu_Lista(int Opcao)
{
    printf("\n\t---------------CADASTRO PARA O SUS---------------\n");

    do
    {
        printf("\n\t[1] - Inicializar o Cadastro");
        printf("\n\t[2] - Cadastrar Luiza");
        printf("\n\t[3] - Remover quem já esta cadastrado");
        printf("\n\t[4] - Imprimir Cadastrados");
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

void Cadastro_de_Luiza(TipoItem x, TipoLista *Lista)
{
    printf("\n\t---------------Informe os dados de Luiza---------------\n");

    bool Continuar_Cadastrando = true;
    int i = 0, Opcao = 0;

    while(Continuar_Cadastrando && Maxtam != Lista->Ultimo)
    {

        printf("\n\tInforme o Nome Completo:  ");
        fflush(stdin);
        gets(x.Nome);
        system("cls");

        printf("\n\tInforme o nome da Mãe de %s: ",x.Nome);
        fflush(stdin);
        gets(x.Nome_Mae);
        system("cls");

        printf("\n\tInforme o CPF de %s:  ",x.Nome);
        fflush(stdin);
        gets(x.Cpf);

        printf("\n\tInforme o RG de %s:  ",x.Nome);
        fflush(stdin);
        gets(x.Rg);
        system("cls");

        printf("\n\t Informe o Endereço de %s:  ",x.Nome);
        fflush(stdin);
        gets(x.Endereco);
        system("cls");

         Insere_Lista(x, Lista);


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

void Retira_Lista(Apontador p, TipoLista *Lista, TipoItem *Item)
{
    int Aux;
    if(Lista_Vazia(*Lista) || p-1 >= Lista->Ultimo)
    {
        return;
    }

    *Item = Lista->itens[p - 1];

    for(Aux = p; Aux < Lista->Ultimo; Aux++)
    {
        Lista->itens[Aux -1] = Lista->itens[Aux];
    }
    Lista->Ultimo--;
}

void ImprimeLista(TipoLista Lista)
{
    printf("\n\t---------------Cadastro de Usuarios do SUS---------------\n");

    int Aux;

    for(Aux = Lista.Primeiro; Aux < Lista.Ultimo; Aux++)
    {
        printf("\n\tNome: %s\n\tNome da Mãe: %s\n\tCPF: %s\n\tRG: %s\n\tEndereço: %s\n\n", Lista.itens[Aux].Nome, Lista.itens[Aux].Nome_Mae,Lista.itens[Aux].Cpf,Lista.itens[Aux].Rg,Lista.itens[Aux].Endereco);
    }
}
