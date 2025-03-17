#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

#define InicioVetor 1
#define MaxTam 3

typedef int Apontador;


typedef struct
{
    char Nome[50], Rg[15];
    char Nome_Mae[50];
    char Cpf[15], Endereco[30];

} TipoItem;

typedef struct
{
    TipoItem Item[MaxTam];
    Apontador Frente, Fundo;

} TipoFila;


int Menu_Lista(int Opcao);

void Iniciar_Fila(TipoFila *Fila);

int Fila_Vazia(TipoFila *Fila);

void Enfileirar_Fila(TipoItem x, TipoFila *Fila);

void Cadastro_de_Luiza(TipoItem x, TipoFila *Fila);

void Verificar_se_oPosto_EstaCheio(TipoFila *Fila);

void Desinfileirar_Fila(TipoFila *Fila, TipoItem *Item);

void Imprimir_Fila(TipoFila Fila);


int main()
{
    setlocale(LC_ALL,"portuguese");

    TipoFila Fila;
    TipoItem x, Item;

    int Opcao = 0, Verificador = 0;

    while(Opcao != 6)
    {
        Opcao = Menu_Lista(Opcao);

        switch(Opcao)
        {
        case 1:

            Iniciar_Fila(&Fila);
            Verificador = 1;

            printf("\n\tCadastro de Luiza Inicializado!...\n");

            break;

        case 2:

            if(Verificador == 1)
            {

                if(Fila_Vazia(&Fila) || Fila.Fundo < MaxTam)
                {
                    Cadastro_de_Luiza(x, &Fila);
                }
                else
                {
                    printf("\n\tLista do SUS Cheia!...\n");
                }
            }
            else
            {
                printf("\n\tA Lista para o cadastro de Luiza não foi Inicializada!...\n");
            }

            break;

        case 3:

            if(Verificador == 1)
            {

                if(Fila_Vazia(&Fila))
                {
                    printf("\n\tLista Vazia!...\n");
                }
                else
                {
                    Desinfileirar_Fila(&Fila, &Item);

                    printf("\n\tNome: %s\n\tNome da Mãe: %s\n\tCPF: %s\n\tRG: %s\n\tEndereço: %s\n\n", Item.Nome, Item.Nome_Mae,Item.Cpf, Item.Rg, Item.Endereco);
                    printf("\n\tRemovido com Sucesso!\n");
                }
            }
            else
            {
                printf("\n\tA Lista para o cadastro de Luiza não foi Inicializada!...\n");
            }

            break;

        case 4:

            if(Verificador == 1)
            {
                Verificar_se_oPosto_EstaCheio(&Fila);
            }
            else
            {
                printf("\n\tA Lista para o cadastro de Luiza não foi Inicializada!...\n");
            }

            break;

        case 5:

            if(Verificador == 1)
            {

                if(Fila_Vazia(&Fila))
                {
                    printf("\n\tFila Vazia!...\n");
                }
                else
                {
                    Imprimir_Fila(Fila);
                }
            }
            else
            {
                printf("\n\tA Lista para o cadastro de Luiza não foi Inicializada!...\n");
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
        printf("\n\t[4] - Verificar se o Posto esta cheio!");
        printf("\n\t[5] - Imprimir Cadastrados");
        printf("\n\t[6] - Sair");
        printf("\n\tEntrada:  ");
        fflush(stdin);
        scanf("%d",&Opcao);
        system("cls");
    }
    while(Opcao > 5 || Opcao < 1);

    return Opcao;
}


void Iniciar_Fila(TipoFila *Fila)
{
    Fila->Frente = InicioVetor;
    Fila->Fundo = Fila->Frente;
}

int Fila_Vazia(TipoFila *Fila)
{
    return (Fila->Frente == Fila->Fundo);
}

void Enfileirar_Fila(TipoItem x, TipoFila *Fila)
{
    if(Fila->Frente == (Fila->Fundo % MaxTam + 1))
    {
        printf("\n\tErro, Fila esta Cheia!...\n");
    }
    else
    {
        Fila->Item[Fila->Fundo - 1] = x;
        Fila->Fundo = (Fila->Fundo % MaxTam) + 1;
    }
}

void Cadastro_de_Luiza(TipoItem x, TipoFila *Fila)
{

    printf("\n\t---------------Informe os dados de Luiza---------------\n");

    bool Continuar_Cadastrando = true;
    int i = 0, Opcao = 0;

    while(Continuar_Cadastrando)
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

        Enfileirar_Fila(x, Fila);


        printf("\n\tContinuar cadastrando Usuários no SUS?\n\t[1] - Sim\n\t[0] - Não\n\tEntrada:  ");
        fflush(stdin);
        scanf("%d",&Opcao);
        system("cls");

        if(Opcao == 0)
        {
            Continuar_Cadastrando = false;
            printf("\n\tCadastro Finalizado!...\n\n");
        }
        else
        {
            if(Opcao == 1)
            {
                printf("\n\tPode continuar cadastrando Usuários!...\n\n");
            }
        }

    }

}

void Verificar_se_oPosto_EstaCheio(TipoFila *Fila)
{

    if(Fila_Vazia(Fila))
    {
        printf("\n\tO posto de Santo Antônio de Jesus esta Vazio!...\n\n");
    }
    else
    {
        if(Fila->Fundo < MaxTam)
        {
            printf("\n\tAinda tem vacina para aplicar!\n\n");
        }
        else
        {
            if(Fila->Fundo == MaxTam)
            {
                printf("\n\tO posto esta cheio!...\n\n");
            }
        }
    }

}


void Desinfileirar_Fila(TipoFila *Fila, TipoItem *Item)
{
    if(Fila_Vazia(Fila))
    {
        printf("\n\tErro, Fila esta Vazia!...\n");
    }
    else
    {
        *Item = Fila->Item[Fila->Frente - 1];
        Fila->Frente = (Fila->Frente % MaxTam) + 1;
    }
}

void Imprimir_Fila(TipoFila Fila)
{
    printf("\n\t---------------Cadastro de Usuarios do SUS---------------\n");

    int Aux = 0;

    for(Aux = Fila.Frente - 1; Aux < Fila.Fundo - 1; Aux++)
    {
        printf("\n\tNome: %s\n\tNome da Mãe: %s\n\tCPF: %s\n\tRG: %s\n\tEndereço: %s\n\n", Fila.Item[Aux].Nome, Fila.Item[Aux].Nome_Mae, Fila.Item[Aux].Cpf, Fila.Item[Aux].Rg, Fila.Item[Aux].Endereco);
    }
}
