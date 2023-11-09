#include <stdio.h>
#include <string.h>

// Constantes
#define TAM 50
#define RECOMPENSA 0.10

// Variáveis globais
char login[TAM];
char senha[TAM];
float saldo;

// Funções
int loginCorreto();
void menu();
void deposito();
void saque();
void saldoAtual();
void calculadoraInvestimento();

 //Login e senha correta
int main() {
    strcpy(login, "pipoca");
    strcpy(senha, "1609");

    // Respota login/senha errado
    if (!loginCorreto()) {
        printf("Login ou senha incorreto! Obrigado por utilizar nosso sistema.\n");
        return 0;
    }

    //Chama função menu
    menu();

    return 0;
}

//Verifica se o login e senha esta certo
int loginCorreto() {
    char tentativaLogin[TAM];
    char tentativaSenha[TAM];

    printf("Digite seu login: ");
    fgets(tentativaLogin, TAM, stdin);
    strtok(tentativaLogin, "\n");

    printf("Digite sua senha: ");
    fgets(tentativaSenha, TAM, stdin);
    strtok(tentativaSenha, "\n");

    return strcmp(tentativaLogin, login) == 0 && strcmp(tentativaSenha, senha) == 0;
}

    // Coletando informações do usuário
    void cadastrar() {
    printf("Digite seu login: ");
    fgets(login, TAM, stdin);
    strtok(login, "\n");

    printf("Digite sua senha: ");
    fgets(senha, TAM, stdin);
    strtok(senha, "\n");

}

    //Aba de menu
    void menu() {
    int opcao;

    do {
        printf("\nEscolha uma op�ao:\n");
        printf("1 - Deposito\n");
        printf("2 - Saque\n");
        printf("3 - Saldo\n");
        printf("4 - Calculadora de investimento\n");
        printf("5 - Sair\n");
        scanf("%d", &opcao);
        getchar(); // Limpar o buffer do teclado

        switch (opcao) {
            case 1:
                deposito();
                break;
            case 2:
                saque();
                break;
            case 3:
                saldoAtual();
                break;
            case 4:
                calculadoraInvestimento();
                break;
            case 5:
                printf("Obrigado por utilizar nosso sistema!\n");
                break;
            default:
                printf("Op��o inv�lida. Tente novamente.\n");
        }
    } while (opcao != 5);
}

    //Opção de depósito
    void deposito() {
    float valor;

    printf("Digite o valor do deposito: ");
    scanf("%f", &valor);
    getchar(); // Limpar o buffer do teclado

    saldo += valor;
    printf("Deposito realizado com sucesso! Novo saldo: %.2f\n", saldo);
}

    //Opção de saque
    void saque() {
    float valor;

    printf("Digite o valor do saque: ");
    scanf("%f", &valor);
    getchar(); // Limpar o buffer do teclado

    if (valor <= saldo) {
        saldo -= valor;
        printf("Saque realizado com sucesso! Novo saldo: %.2f\n", saldo);
    } else {
        printf("Saldo insuficiente para saque! Tente novamente.\n");
    }
}

    //Opção de saldo
    void saldoAtual() {
    printf("Saldo atual: %.2f\n", saldo);
}

    //Caculadora de investimento
    void calculadoraInvestimento() {
    float investimento, rentabilidade, retornoMensal, retornoAnual;

    printf("Digite o valor do investimento: ");
    scanf("%f", &investimento);
    getchar(); // Limpar o buffer do teclado

    printf("Digite a rentabilidade mensal em %: ");
    scanf("%f", &rentabilidade);
    getchar(); // Limpar o buffer do teclado

    retornoMensal = investimento * (rentabilidade / 100);
    retornoAnual = retornoMensal * 12;

    printf("Retorno mensal do investimento: %.2f\n", retornoMensal);
    printf("Retorno anual do investimento: %.2f\n", retornoAnual);
}

