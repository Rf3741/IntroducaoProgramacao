#include <stdio.h>
#include <math.h>
// gcc -o hipotenusa hipotenusa.c -lm
// lembrar do -lm no final por causa da biblioteca math.h

int main () {
    // declaracao de variaveis
    double h, g, c1, c2 = 0;

    // entrada de dados
    printf("Defina os valores dos catetos de um triangulo retangulo:\n");
    printf("Digite o valor do cateto 1: ");
    scanf("%lf", &c1); // cateto 1
    printf("Digite o valor do cateto 2: ");
    scanf("%lf", &c2); // cateto 2

    // processamento
    h = sqrt(pow(c1, 2) + pow(c2, 2)); 
    //sqrt = raiz quadrada (sem indicar o expoente, ela e quadrada), pow = potenciação

    // exibicao do resultado
    printf("O valor da hipotenusa é: %0.f\n", h); // 0.f = sem casas decimais

    return 0;
}