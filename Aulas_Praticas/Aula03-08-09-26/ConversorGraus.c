#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main () {
    // declaracao de variaveis
    float celsius, fahrenheit, kelvin = 0;

    // entrada de dados
    printf("Defina o valor em graus Celsius que deseja converter:\n");
    printf("Digite o valor em graus Celsius: ");
    scanf("%f", &celsius);

    // processamento
    fahrenheit = (celsius * 9/5) + 32;
    kelvin = celsius + 273.15;

    // exibicao do resultado
    printf("O valor em graus Fahrenheit é: %.2f\n", fahrenheit);
    printf("O valor em Kelvin é: %.2f\n", kelvin);

    return 0;
}