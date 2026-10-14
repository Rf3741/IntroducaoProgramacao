/* 
Introdução a Programação - Aula 8 
Rafael Andrade Câmara, 14/10/2026, 26.2.4022    
*/

#include <stdio.h>

void divisores(int n) {
    // processamento
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            printf("%d ", i);
        }
    }
}

int main () {
    // declaracao de variaveis
    int n;

    // entrada de dados
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    // exibicao do resultado
    printf("\nOs divisores de %d sao: ", n);
    divisores(n);
    printf("\n");

    return 0;
}
