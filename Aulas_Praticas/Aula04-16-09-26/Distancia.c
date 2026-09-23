/* 
Introdução a Programação - Aula 4 
Rafael Andrade Câmara, 16/09/2026, 26.2.4022    
*/

#include <stdio.h>
#include <math.h>
// lembrar do -lm no final por causa da biblioteca math.h

int main () {
    // declaracao de variaveis
    float horizontal, altitude, distancia = 0;

    // entrada de dados
    printf("Digite a distancia horizontal do drone (em metros):\n");
    scanf("%f", &horizontal);
    printf("Digite a altitude do drone (em metros):\n");
    scanf("%f", &altitude);

    // processamento
    distancia = sqrtf(horizontal * horizontal + altitude * altitude);

    // exibicao do resultado
    printf("A distância em linha reta do drone até a base é: %.2f m\n", distancia);

    return 0;
}