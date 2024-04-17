#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

void calcularNFatorial(int n, int *resultado);
void calcularNumeroHarmonico(int n, float *resultado);
void calcularValorDeS(float *resultado);
void calcularValorDeE(int n, float *resultado);
float calcularRaizQuadradaDeX(float x);
double fatorial(int n);
double potencia(double base, int expoente);
void cosseno(double x, int n, double *resultado);
double seno(double x, int *numeroTermos);
void printHelp();

int main(int argc, char *argv[]) {
    if (argc == 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0)) {
        printHelp();
        return 0;
    }

    int opcao, numero, fatorial, n;
    int numeroTermos = 25;
    float resultado, x, raiz;
    double y, result, z;

    do{

        printf("\nMENU\nInsira a opção desejada:\n1 - Calculo de N fatorial\n2 - Número harmônico\n");
        printf("3 - Calcular e escrever o valor de S\n4 - Calcular e escrever o valor de E\n");
        printf("5 - Calcular raíz quadrada de x\n6 - Calcular cosseno pelo polinômio de Mclaurin\n");
        printf("7 - Calcular o seno definida pela série pré determinada\n0 - Sair\n\nOpção: ");

        scanf("%d", &opcao);

        switch(opcao) {
            case 0:
                return 0;
            break;
            
            case 1:
                printf("\nOPCAO 1:\n");
                printf("Digite um número para calcular o fatorial: ");
                scanf("%d", &numero);

                calcularNFatorial(numero, &fatorial);

                printf("O fatorial de %d é: %d\n", numero, fatorial);
            break;

            case 2:
                printf("\nOPCAO 2:\n");
                printf("Digite o valor de n para calcular o número harmônico Hn: ");
                scanf("%d", &numero);

                // Chamada da função para calcular o número harmônico
                calcularNumeroHarmonico(numero, &resultado);

                printf("O número harmônico H%d é: %f\n", numero, resultado);
            break;

            case 3:
                printf("OPCAO 3:\n");
                calcularValorDeS(&resultado);
                printf("O valor de S é: %f\n", resultado);
            break;

            case 4:
                printf("OPCAO 4:\n");
                printf("Digite um valor inteiro e positivo para N: ");
                scanf("%d", &numero);

                // Verifica se o número é positivo
                if (numero < 0) {
                    printf("Erro: N deve ser um número inteiro e positivo.\n");
                    return 1; // Retorna 1 para indicar um erro
                }

                // Chamada da função para calcular e mostrar o valor de E
                calcularValorDeE(numero, &resultado);

                printf("O valor de E é: %.4f\n", resultado);
            break;

            case 5:
                printf("OPCAO 5:\n");
                // Solicita ao usuário que digite um número positivo
                do {
                    printf("Digite um número positivo para calcular a raiz quadrada: ");
                    scanf("%f", &x);
                } while (x < 0);

                // Chama a função para calcular a raiz quadrada
                raiz = calcularRaizQuadradaDeX(x);

                // Verifica se o valor retornado é válido
                if (raiz != -1) {
                    printf("A raiz quadrada de %.2f é aproximadamente %.4f\n", x, raiz);
                }
            break;

            case 6:
                printf("OPCAO 6:\n");
                printf("Digite o valor de x: ");
                scanf("%lf", &y);

                printf("Digite o numero de termos do somatorio: ");
                scanf("%d", &n);

                cosseno(y, n, &result);

                printf("O Cosseno (%.2f) = %.4f\n", y, result);
            break;

            case 7:
                printf("OPCAO 7:\n");
                printf("Digite o valor de x: ");
                scanf("%lf", &z);

                printf("Seno (%lf) = %.4f\n", z, seno(z, &numeroTermos));
            break;

            default:
                printf("Opção inválida.");
        }
    }while(opcao != 0);

    return 0;
}

void calcularNFatorial(int n, int *resultado){
    *resultado = 1; // Inicializa o resultado como 1
    for (int i = 1; i <= n; ++i) {
        *resultado *= i; // Multiplica o resultado pelo número atual do loop
    }
}

void calcularNumeroHarmonico(int n, float *resultado){
    *resultado = 0; // Inicializa o resultado como 0
    for (int i = 1; i <= n; ++i) {
        *resultado += 1.0 / i; // Adiciona o inverso do número atual à soma
    }    
}

void calcularValorDeS(float *resultado){
    *resultado = 0; // Inicializa o resultado como 0
    int numerador = 1;
    for (int i = 1; i <= 50; ++i) {
        *resultado += (float)numerador / i; // Adiciona o resultado da divisão ao valor de S
        numerador += 2; // Atualiza o numerador para o próximo termo
    }
}

void calcularValorDeE(int n, float *resultado){
    *resultado = 0; // Inicializa o resultado como 0
    float fatorial = 1; // Inicializa o fatorial como 1

    for (int i = 1; i <= n; ++i) {
        fatorial *= i; // Calcula o fatorial de i

        // Adiciona o resultado da divisão ao valor de E
        *resultado += 1.0 / fatorial;
    }
}

float calcularRaizQuadradaDeX(float x){
    if (x < 0) {
        printf("Valor inválido! Digite um número positivo.\n");
        return -1; // Retorna -1 para indicar um valor inválido
    }

    // Chute inicial para a raiz
    float raiz = x / 2.0;
    // Define o critério de parada
    float erro = 0.0001;

    // Loop até que a diferença entre raiz^2 e x seja menor que o erro
    while (raiz * raiz - x >= erro || x - raiz * raiz >= erro) {
        // Calcula a próxima aproximação da raiz usando a fórmula do método de Newton
        raiz = 0.5 * (raiz + x / raiz);
    }

    return raiz;
}

double fatorial(int n){
    if (n == 0) {
        return 1;
    }
    double result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

double potencia(double base, int expoente) {
    double resultado = 1.0;
    for (int i = 0; i < expoente; i++) {
        resultado *= base;
    }
    return resultado;
}

void cosseno(double x, int n, double *resultado){
    *resultado = 0;
    for (int i = 0; i <= n; i++) {
        double term = (potencia(-1, i) * potencia(x, 2 * i)) / fatorial(2 * i);
        *resultado += term;
    }
}

double seno(double x, int *numeroTermos) {
    double senoX = 0;
    double fatorial = 1;
    int i;
    int sinal = 1;

    for (i = 0; i < *numeroTermos; i++) {
        senoX += sinal * (potencia(x, 2 * i + 1) / fatorial);
        fatorial *= (2 * i + 1) * (2 * i + 2);
        sinal *= -1;
    }

    *numeroTermos = 25;
    return senoX;
}

void printHelp() {
    printf("Este programa realiza diversas operações matemáticas.\n");
    printf("Opções disponíveis:\n");
    printf("-fatorial <n>: Calcula o fatorial de n.\n");
    printf("-harmonico <n>: Calcula o número harmônico de n.\n");
    printf("-s: Calcula o valor de S.\n");
    printf("-e <n>: Calcula o valor de E para o número de termos n.\n");
    printf("-raiz <x>: Calcula a raiz quadrada de x.\n");
    printf("-seno <x>: Calcula o seno de x.\n");
}