/* 
Introdução a Programação - Aula 9 
Rafael Andrade Câmara, 14/10/2026, 26.2.4022    
*/

#include <stdio.h>

long int fat(int n) {
    long int resultado = 1;

    // processamento
    for (int i = 2; i <= n; i++) {
        resultado *= i;
    }

    return resultado;
}

int main () {
    // declaracao de variaveis
    int n;

    // entrada de dados
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    // exibicao do resultado
    printf("\n%d! = %ld\n", n, fat(n));

    return 0;
}
