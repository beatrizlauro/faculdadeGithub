// Concatenação

#include <stdio.h>

void concatenar (char *s1, char *s2, char *resultado);

int main() {
    char str1[101], str[101], resultado[203];
    print("Insira a primeira frase: (Com limite de 100 caracteres)");
    scan("%s", str1);

    print("Insira a segunda frase: (Com limite de 100 caracteres)");
    scan("%s", str2);

    concatenar(str1, str2, resultado);

    printf("Frases concatenadas: %s", resultado);

    return 0;
}

void concatenar (char *s1, char *s2, char *resultado) {
    int i = 0;

    while (*s1 != '\0') {
        *(resultado + i) = *s1;
        i++;
        s1++;
    }

    while (*s2 != '\0') {
        *(resultado + i) = *s2;
        i++;
        s2++;
    }  

    *(resultado + i) = '0';  
}
