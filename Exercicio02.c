/*
Crie uma fun��o chamada "calcularMedia" que recebe como par�metro uma struct "Aluno",
esta struct ter� informa��es como: nome, data de nascimento, duas notas e m�dia e
retorna a m�dia das notas. Em seguida, crie um programa que declare um array de
5 alunos e utilize a fun��o "calcularMedia" para imprimir a m�dia de cada aluno.
Tamb�m crie uma fun��o para verificar se um aluno est� aprovado ou reprovado
sendo necess�rio m�dia maior ou igual a 7,0 para aprova��o.

*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#define qtdNotas 2
#define qtdAlunos 2

struct dados_aluno
{
    char nome[300];
    char dataNascimento[100];
    float nota[qtdNotas];
    float media;
};

void calcularMedia(struct dados_aluno aluno[])
{
    float soma = 0;
    int i, j;
    for (i = 0; i < qtdAlunos; i++)
    {
        soma=0;
        for (j = 0; j < qtdNotas; j++)
        {
            soma += aluno[i].nota[j];
        }
    
    }
    aluno[i].media=soma/qtdNotas;
    
    
    
}

char* resultado(struct dados_aluno aluno[])
{

    char result[300];
    int i;
    for (i = 0; i < qtdAlunos; i++)
    {
        if (aluno[i].media >= 7)
        {
            strcpy(result, "ALUNO APROVADO!");
        }
        else
        {
            strcpy(result, "ALUNO REPROVADO!");
        }
    }

    return result;
}

int main()
{
    setlocale(LC_ALL, "");
    int i, j;

    struct dados_aluno aluno[qtdAlunos];
    for (i = 0; i < qtdAlunos; i++)
    {
        printf("\nDigite o nome do %d� aluno:", i + 1);
        gets(aluno[i].nome);
        printf("\nDigite a data de nascimento:");
        gets(aluno[i].dataNascimento);
        for (j = 0; j < qtdNotas; j++)
        {
            printf("\nDigite a %d� nota:", j + 1);
            scanf("%f", &aluno[i].nota[j]);
        }
        fflush(stdin);
    }

    for (i = 0; i < qtdAlunos; i++)

    {
       
        printf("\nNome: %s", aluno[i].nome);
        printf("\nData de Nascimento: %s", aluno[i].dataNascimento);
        for (j = 0; j < qtdNotas; j++)
        {
            printf("\n %d� Nota: %.2f", j + 1, aluno[i].nota[j]);
        }

        printf("\nM�dia: %.2f", aluno[i].media);
        printf("\n%s", resultado(aluno));
    }

    return 0;
}
