// Contagem de caracteres de uma string

#include <stdio.h>

int contarCaracteres(char *s);

int main () {
    char string[101];

    printf("Insira uma string: (De no máximo 100 caracteres)");
    scanf("%s", string);

    int numeroCaracteres = contarCaracteres(string);
    
    printf("A string inserida tem %d caracteres", numeroCaracteres);

    return 0;
}

int contarCaracteres(char *s) {
    int i = 0;

    while(*s != '\0') {
        i++;
        s++;
    }
    return i;
}
