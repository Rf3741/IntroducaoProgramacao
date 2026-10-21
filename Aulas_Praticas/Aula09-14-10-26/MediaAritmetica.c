/* 
Introdução a Programação - Aula 9 
Rafael Andrade Câmara, 14/10/2026, 26.2.4022    
*/

#include <stdio.h>

int main () {
    // declaracao de variaveis
    float valor, soma = 0;
    int n = 0;

    // entrada de dados
    printf("Digite um valor: ");
    scanf("%f", &valor);

    while (valor != 0) {
        // processamento
        soma += valor;
        n++;

        // entrada de dados
        printf("Digite um valor: ");
        scanf("%f", &valor);
    }

    // exibicao do resultado
    if (n == 0) {
        printf("\nNão foi possível calcular MA!\n");
    } else {
        printf("\nMA = %.2f\n", soma / n);
    }

    return 0;
}
