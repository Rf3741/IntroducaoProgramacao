/* 
Introdução a Programação - Aula 10 
Rafael Andrade Câmara, 21/10/2026, 26.2.4022    
*/

#include <stdio.h>

float calcular_media(float consumo[15]) {
    float soma = 0;

    // processamento
    for (int i = 0; i < 15; i++) {
        soma += consumo[i];
    }

    return soma / 15.0;
}

float maior_valor(float consumo[15]) {
    float maior = consumo[0];

    // processamento
    for (int i = 1; i < 15; i++) {
        if (consumo[i] > maior) {
            maior = consumo[i];
        }
    }

    return maior;
}

float menor_valor(float consumo[15]) {
    float menor = consumo[0];

    // processamento
    for (int i = 1; i < 15; i++) {
        if (consumo[i] < menor) {
            menor = consumo[i];
        }
    }

    return menor;
}

int main () {
    // declaracao de variaveis
    float consumo[15];
    float media;
    float maior;
    float menor;

    // entrada de dados
    for (int i = 0; i < 15; i++) {
        printf("Digite o consumo da %d residência: ", i + 1);
        scanf("%f", &consumo[i]);
    }

    // processamento
    media = calcular_media(consumo);
    maior = maior_valor(consumo);
    menor = menor_valor(consumo);

    // exibicao do resultado
    printf("\nConsumo médio: %.2f Kwh\n", media);
    printf("Maior consumo: %.2f Kwh\n", maior);
    printf("Menor consumo: %.2f Kwh\n", menor);

    return 0;
}
