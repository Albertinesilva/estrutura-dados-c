#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

typedef struct
{
    char Nome[50];
    char Endereco[100];
    char Telefone[20];

} Agenda;


void main()
{
    setlocale(LC_ALL,"Portuguese");

    Agenda Contatos[500];

    int i = 0;
    while (i != 500)
    {
        printf("\n\t----------Cadastre o %d� Contato na Agenda----------\n",i+1);
        printf("\n\tInforme o Nome Para Contato: ");
        fflush(stdin);
        gets(Contatos[i].Nome);

        printf("\n\tInforme o Endereço de %s: ",Contatos[i].Nome);
        fflush(stdin);
        gets(Contatos[i].Endereco);

        printf("\n\tInforme o Telefone de %s: ",Contatos[i].Nome);
        fflush(stdin);
        gets(Contatos[i].Telefone);
        system("cls");

        i++;
    }

    printf("\n\t----------Contatos Salvos na Agenda----------\n");
    for(int i = 0; i < 500; i++)
    {
        printf("\n\tNome: %s",Contatos[i].Nome);
        printf("\n\tEndere�o: %s",Contatos[i].Endereco);
        printf("\n\tTelefone: %s",Contatos[i].Telefone);
        printf("\n");
    }
}
