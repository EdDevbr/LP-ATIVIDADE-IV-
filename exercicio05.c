#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define tam 2


struct Funcionario {
    char nome[100];
    char cargo[50];
    float salario;
};


float calcularMediaSalarial(struct Funcionario *funcionarios, int tamanho, const char *cargoAlvo) {
    int contador = 0;
    float somaSalarial = 0.0;

    for (int i = 0; i < tam; i++) {
        if (strcmp(funcionarios[i].cargo, cargoAlvo) == 0) {
            somaSalarial += funcionarios[i].salario;
            contador++;
        }
    }

    if (contador > 0) {
        return somaSalarial / contador;
    } else {
        return 0.0; 
    }
}


void preencherFuncionario(struct Funcionario *funcionario) {
    for (int i = 0; i < tam; i++) {

    printf(" ==================================== ");
    printf("Digite o nome do %d� funcion�rio: ", i+1);
    scanf("%s", funcionario[i].nome);
    printf("Digite o cargo do funcion�rio: ");
    scanf("%s", funcionario[i].cargo);
    printf("Digite o sal�rio do funcion�rio: ");
    scanf("%f", &funcionario[i].salario);



    }
    
}

int main() {
    setlocale(LC_ALL,"");
    
    struct Funcionario funcionarios[tam];

    preencherFuncionario(funcionarios);
    

    const char cargoAlvo[] = "programador";

    
    float mediaSalarialProgramadores = calcularMediaSalarial(funcionarios, tam, cargoAlvo);

    
    if (mediaSalarialProgramadores > 0) {
        printf("\nA m�dia salarial dos programadores �: %.2f\n", mediaSalarialProgramadores);
    } else {
        printf("\nN�o h� programadores na empresa.\n");
    }

    return 0;
}
