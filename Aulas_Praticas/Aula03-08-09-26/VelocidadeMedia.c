/* 
Introdução a Programação - Aula 3 
Rafael Andrade Câmara, 08/09/2026, 26.2.4022    
*/

#include <stdio.h>
#include <math.h>
// gcc -o hipotenusa hipotenusa.c -lm
// lembrar do -lm no final por causa da biblioteca math.h

int main () {
    // declaracao de variaveis
    int a, b, c, d, x = 0;

    // entrada de dados
    //printf("Na seguinte conta: x = a³ x (b+c)/d\n");
    printf("Entre com os valores de a, b, c, d:\n");
    scanf("%d %d %d %d", &a, &b, &c, &d);
    
    // processamento
    x = pow(a, 3) * (b+c)/d;

    // exibicao do resultado
    //printf("a = %d, b = %d, c = %d, d = %d\n", a, b, c, d); 
    // tive que pesqusar como imprimia um float sem casa decimais e ta ai
    printf("x =%d\n", x);

    return 0;
}