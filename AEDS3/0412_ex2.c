// Copiar uma string para outra:

#include <stdio.h>

void copiar(char *inicio, char *fim);

int main() {
    char inicio[101], fim[101];

    printf("Digite uma frase: (Com limite de 100 caracteres)");
    scanf("%s", inicio);

    copiar(inicio, fim);

    print("A string copiada é: %s", fim);

    return 0;
}

void copiar(char *inicio, char *fim) {
    int i = 0;

    while((*(fim + i) = *(inicio + i)) != '\0') {
        i++
    }
}