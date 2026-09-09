#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// lembrar do -lm no final por causa da biblioteca math.h

int main () {
    // declaracao de variaveis
    double x1, y1, x2, y2, dist = 0;

    // entrada de dados
    printf("Defina os valores X e Y dos pontos 1 e 2:\n");
    printf("Digite o valor de X do ponto 1: ");
    scanf("%lf", &x1);
    printf("Digite o valor de Y do ponto 1: ");
    scanf("%lf", &y1);
    printf("Digite o valor de X do ponto 2: ");
    scanf("%lf", &x2);
    printf("Digite o valor de Y do ponto 2: ");
    scanf("%lf", &y2);

    // processamento
    dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    // exibicao do resultado
    printf("A distancia entre os pontos é: %.2f\n", dist);

    return 0;
}