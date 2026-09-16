#include <stdio.h>
#include <math.h>
// gcc -o hipotenusa hipotenusa.c -lm
// lembrar do -lm no final por causa da biblioteca math.h

#define PI 3.14159265 // declara valor de PI fixo

int main () {
    // declaracao de variaveis
    double h, g, c1, c2 = 0;

    // entrada de dados
    printf("Defina o valor da hipotenusa e da angulação de um triangulo retangulo:\n");
    printf("Digite o valor da hipotenusa: ");
    scanf("%lf", &h); // hipotenusa
    printf("Digite o valor do angulo: ");
    scanf("%lf", &g); // angulo

    // processamento
    c1 = h * cos(g * PI / 180); // cateto 1
    c2 = h * sin(g * PI / 180); // cateto 2

    // exibicao do resultado
    printf("O valor da hipotenusa é: %.2f, e o angulo é: %.2f\n", h, g);
    printf("O valor do cateto 1 é: %.2f\n", c1);
    printf("O valor do cateto 2 é: %.2f\n", c2);

    return 0;
}