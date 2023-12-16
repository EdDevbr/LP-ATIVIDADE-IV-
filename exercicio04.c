#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

#define armazenamentoContaTam 10


struct ContaBancaria {
    int numeroConta;
    char nomeTitular[100];
    float saldo;
    char tipoConta[20];
    char login[50];
    char senha[50];
};

void depositar(struct ContaBancaria *conta, float valor) {
    conta->saldo += valor;
    system("cls || clear");
    printf("Depósito de R$ %.2f realizado com sucesso.\n", valor);
}


void sacar(struct ContaBancaria *conta, float valor) {
    if (valor > 0 && valor <= conta->saldo) {
        conta->saldo -= valor;
        system("cls || clear");
        printf("Saque de R$ %.2f realizado com sucesso.\n", valor);
    } else {
        system("cls || clear");
        printf("Saldo insuficiente ou valor de saque inválido.\n");
    }
}


void imprimirSaldo(struct ContaBancaria conta) {
    system("cls || clear");
    printf("Saldo atual da conta: R$ %.2f\n", conta.saldo);
}


void criarConta(struct ContaBancaria *contas, int *quantidadeContas) {
    if (*quantidadeContas < armazenamentoContaTam) {
        printf("Digite o nome do titular: ");
         scanf("%s", contas[*quantidadeContas].nomeTitular);
        printf("Digite o número da conta: ");
         scanf("%s", contas[*quantidadeContas].tipoConta);
        printf("Digite o login: ");
         scanf("%s", contas[*quantidadeContas].login);
        printf("Digite a senha: ");
        scanf("%s", contas[*quantidadeContas].senha);

        contas[*quantidadeContas].numeroConta = 1000 + *quantidadeContas; 
        contas[*quantidadeContas].saldo = 0.0;

        (*quantidadeContas)++;
        system("cls || clear");
        printf("Conta criada com sucesso!\n");
    } else {
        system("cls || clear");
        printf("Número máximo de contas atingido.\n");
    }
}


int autenticar(struct ContaBancaria *contas, int quantidadeContas) {
    char login[50];
    char senha[50];

    printf("Digite o login: ");
    scanf("%s", login);
    printf("Digite a senha: ");
    scanf("%s", senha);

    for (int i = 0; i < quantidadeContas; i++) {
        if (strcmp(login, contas[i].login) == 0 && strcmp(senha, contas[i].senha) == 0) {
            system("cls || clear");
            printf("Autenticação bem-sucedida!\n");
            return i; 
        }
    }
    system("cls || clear");
    printf("Autenticação falhou. Login ou senha incorretos.\n");
    return -1; 
}



int main() {
    setlocale(LC_ALL,"");
    struct ContaBancaria contas[armazenamentoContaTam];
    int quantidadeContas = 0;
    int opcao;
    int contaAtual = -1;

    do {
        printf("\n=== ----------------------- ===\n");
        printf("\n=== BANCO SENAI DENDEZEIROS ===\n");
        printf("\n=== ----------------------- ===\n");
        printf("1 - Criar conta\n");
        printf("2 - Login\n");
        printf("3 - Depositar dinheiro\n");
        printf("4 - Sacar dinheiro\n");
        printf("5 - Consultar saldo\n");
        printf("6 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                criarConta(contas, &quantidadeContas);
                break;
            case 2:
                contaAtual = autenticar(contas, quantidadeContas);
                break;
            case 3:
                if (contaAtual != -1) {
                    float valor;
                    system("cls || clear");
                    printf("Digite o valor a ser depositado: ");
                    scanf("%f", &valor);
                    depositar(&contas[contaAtual], valor);
                } else {
                    system("cls || clear");
                    printf("Você precisa fazer o login primeiro.\n");
                }
                break;
            case 4:
                if (contaAtual != -1) {
                    float valor;
                    system("cls || clear");
                    printf("Digite o valor a ser sacado: ");
                    scanf("%f", &valor);
                    sacar(&contas[contaAtual], valor);
                } else {
                    system("cls || clear");
                    printf("Você precisa fazer o login primeiro.\n");
                }
                break;
            case 5:
                if (contaAtual != -1) {
                    imprimirSaldo(contas[contaAtual]);
                } else {
                    system("cls || clear");
                    printf("Você precisa fazer o login primeiro.\n");
                }
                break;
            case 6:
            system("cls || clear");
                printf("Saindo do programa.\n");
                break;
            default:
            system("cls || clear");
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 6);

    return 0;
}
