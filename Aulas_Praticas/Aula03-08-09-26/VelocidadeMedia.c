/* 
Introdução a Programação - Aula 3 
Rafael Andrade Câmara, 08/09/2026, 26.2.4022    
*/

#include <stdio.h> // biblioteca padrão de entrada e saída
#include <stdlib.h> // biblioteca padrão de funções utilitárias

int main() {

    // declaracão de variáveis
    float distancia, tempo, velocidadeMedia;

    // coleta de dados
    printf("Digite a distância percorrida (em kilometros): "); // solicita distancia percorrida
    scanf("%f", &distancia); // le a distancia informada
    printf("Digite o tempo gasto (em horas): "); // solicita tempo gasto
    scanf("%f", &tempo); // le o tempo informado

    // calculo da velocidade média
    velocidadeMedia = distancia / tempo; // calcula a velocidade média

    // exibição do resultado
    printf("A velocidade média é: %.2f km/h\n", velocidadeMedia); // exibe a velocidade média calculada

    return 0; // finaliza o programa
}