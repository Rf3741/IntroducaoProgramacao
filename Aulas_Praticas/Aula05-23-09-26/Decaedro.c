/* 
Introdução a Programação - Aula 5 
Rafael Andrade Câmara, 23/09/2026, 26.2.4022    
*/

#include <stdio.h>
#include <math.h>
// lembrar do -lm no final por causa da biblioteca math.h

float calculaArea(float Lado) {
    float Resultado = 0;
    Resultado = 3* pow(Lado, 2) * sqrt(25 + 10 * sqrt(5));
    return Resultado;
}

int main () {
    // declaracao de variaveis
    float Lado = 0;
    float Resultado = 0;

    // entrada de dados
    printf("Digite o lado do dodecaedro regular: \n");
    scanf("%f", &Lado);

    //processamento de dados
    Resultado = calculaArea(Lado);

    // exibicao do resultado
    printf("A area e: %.2f\n", Resultado);

    return 0;
}
    