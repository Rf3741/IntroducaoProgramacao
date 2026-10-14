/* 
Introdução a Programação - Aula 8 
Rafael Andrade Câmara, 14/10/2026, 26.2.4022    
*/

#include <stdio.h>

int quadrado_por_soma(int n) {
    int soma = 0;
    int impar = 1;

    // processamento
    for (int i = 1; i <= n; i++) {
        soma += impar;
        impar += 2;
    }

    return soma;
}

int main () {
    // declaracao de variaveis
    int n;
    int quadrado;

    // entrada de dados
    printf("Digite um numero: ");
    scanf("%d", &n);

    // processamento
    quadrado = quadrado_por_soma(n);

    // exibicao do resultado
    printf("O quadrado de %d e %d\n", n, quadrado);

    return 0;
}
