#include <stdio.h>
#include <math.h>
// gcc -o hipotenusa hipotenusa.c -lm
// lembrar do -lm no final por causa da biblioteca math.h

int main () {
    // declaracao de variaveis
    double x, a, b, c, d, e = 0;

    // entrada de dados
    printf("Na seguinte conta: x = a³ x ((b+c/d)+e)\n");
    printf("Digite o valor de a: ");
    scanf("%lf", &a);
    printf("Digite o valor de b: ");
    scanf("%lf", &b);
    printf("Digite o valor de c: ");
    scanf("%lf", &c);
    printf("Digite o valor de d: ");
    scanf("%lf", &d);
    printf("Digite o valor de e: ");
    scanf("%lf", &e);
    
    // processamento
    x = pow(a, 3) * ((b+c)/d + e);

    // exibicao do resultado
    printf("a = %0.f, b = %0.f, c = %0.f, d = %0.f, e = %0.f\n", a, b, c, d, e); 
    // tive que pesqusar como imprimia um float sem casa decimais e ta ai
    printf("x = %0.f\n", x);

    return 0;
}