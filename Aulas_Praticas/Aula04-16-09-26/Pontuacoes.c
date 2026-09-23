/* 
Introdução a Programação - Aula 4 
Rafael Andrade Câmara, 16/09/2026, 26.2.4022    
*/

#include <stdio.h>
#include <math.h>
// lembrar do -lm no final por causa da biblioteca math.h

int main () {
    // declaracao de variaveis
    int valor1, valor2 = 0;

    // entrada de dados
    printf("Digite as duas pontuações:\n");
    scanf("%i %i", &valor1, &valor2);

    // processamento e exibição de resultados
    if (valor1 > valor2) {
        printf("A pontuação %i é maior e %i a menor.\n", valor1, valor2);
    } else if (valor2 > valor1) {
        printf("A pontuação %i é maior e %i a menor.\n", valor2, valor1);
    } else {
        printf("As duas pontuações são iguais: %i\n", valor1);
    }

    return 0;
}