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
    float y, x1, x2, x3 = 0;

    // entrada de dados
    /*printf("Na seguinte conta: y = (x1 + x2² + x3²)² - (x1 x2 x3)²\n");
    printf("Digite o valor de x1: ");
    scanf("%f", &x1);
    printf("Digite o valor de x2: ");
    scanf("%f", &x2);
    printf("Digite o valor de x3: ");
    scanf("%f", &x3);
    */

    printf("Entre com os valores de x1, x2 e x3:\n");
    scanf("%f %f %f", &x1, &x2, &x3);
    // processamento
    y = pow(x1 + pow(x2, 2) + pow(x3, 2), 2) - pow((x1 * x2 * x3), 2);

    // exibicao do resultado
    printf("y = %0.2f\n", y);

    return 0;
}
    