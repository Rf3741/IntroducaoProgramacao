/* 
Introdução a Programação - Aula 10 
Rafael Andrade Câmara, 21/10/2026, 26.2.4022    
*/

#include <stdio.h>
#include <stdlib.h>

#define TAMANHO 100

void preencher_vetor(int vetor[], int tamanho) {
    // processamento
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 200;
    }
}

void imprimir_maiores(int vetor[], int tamanho, int limiar) {
    // exibicao do resultado
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] >= limiar) {
            printf("%d ", vetor[i]);
        }
    }
}

void imprimir_menores(int vetor[], int tamanho, int limiar) {
    // exibicao do resultado
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] < limiar) {
            printf("%d ", vetor[i]);
        }
    }
}

int main () {
    // declaracao de variaveis
    int amostra[TAMANHO];
    int limiar;

    // processamento
    srand(10);
    preencher_vetor(amostra, TAMANHO);

    // entrada de dados
    printf("Digite um número: ");
    scanf("%d", &limiar);

    // exibicao do resultado
    printf("\nMaiores: ");
    imprimir_maiores(amostra, TAMANHO, limiar);
    printf("\n");

    printf("Menores: ");
    imprimir_menores(amostra, TAMANHO, limiar);
    printf("\n");

    return 0;
}
