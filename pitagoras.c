#include <stdio.h>
#include <math.h>

int main() {
    // declaracao de variaveis
    float a, b, c;

    // entrada de dados
    printf("Digite o valor do cateto a: \n");
    scanf("%f", &a);
    printf("Digite o valor do cateto b: \n");
    scanf("%f", &b);

    // calculo da hipotenusa
    c = sqrt(pow(a, 2) + pow(b, 2));

    // exibicao do resultado
    printf("O valor da hipotenusa é: %.2f\n", c);

    return 0;
}