/* 
Introdução a Programação - Aula 6 
Rafael Andrade Câmara, 06/10/2026, 26.2.4022    
*/

#include <stdio.h>

#define PI 3.14159265359

int temp(int opcao) {
    // declaracao de variaveis
    float temp;
    float result;

    switch (opcao) {
        case 1:
            // entrada de dados
            printf("Digite o valor em Celsius: ");
            scanf("%f", &temp);

            // processamento
            result = temp * (9.0 / 5.0) + 32;
            // exibicao do resultado
            printf("Valor em Fahrenheit: %.2f\n", result);

            // processamento
            result = temp + 273.15;
            // exibicao do resultado
            printf("Valor em Kelvin: %.2f\n", result);
            break;
        case 2:
            // entrada de dados
            printf("Digite o valor em Fahrenheit: ");
            scanf("%f", &temp);

            // processamento
            result = (temp - 32) * (5.0 / 9.0);
            // exibicao do resultado
            printf("Valor em Celsius: %.2f\n", result);

            // processamento
            result = (temp - 32) * (5.0 / 9.0) + 273.15;
            // exibicao do resultado
            printf("Valor em Kelvin: %.2f\n", result);
            break;
        case 3:
            // entrada de dados
            printf("Digite o valor em Kelvin: ");
            scanf("%f", &temp);

            // processamento
            result = temp - 273.15;
            // exibicao do resultado
            printf("Valor em Celsius: %.2f\n", result);

            // processamento
            result = (temp - 273.15) * (9.0 / 5.0) + 32;
            // exibicao do resultado
            printf("Valor em Fahrenheit: %.2f\n", result);
            break;
        default:
            printf("Opcao invalida\n");
            break;
    }

    return 0;
}

int grau(int opcao) {
    // declaracao de variaveis
    float grau;
    float result;

    if (opcao == 1) {
        // entrada de dados
        printf("Digite o valor em Graus: \n");
        scanf("%f", &grau);

        // processamento
        result = PI * grau / 180;

        // exibicao do resultado
        printf("Valor em Radianos: %.2f\n", result);
    } else if (opcao == 2) {
        // entrada de dados
        printf("Digite o valor em radiano: \n");
        scanf("%f", &grau);

        // processamento
        result = grau * (180 / PI);

        // exibicao do resultado
        printf("Valor em Graus: %.2f\n", result);
    } else {
        printf("Opcao invalida\n");
    }

    return 0;
}

int main () {
    // declaracao de variaveis
    int opcao;

    // entrada de dados
    printf("### CONVERSOR DE UNIDADES ###\n");
    printf("\n");
    printf("1) Angulo\n");
    printf("2) Temperatura\n");
    printf("\n");
    printf("Digite uma opcao: ");
    scanf("%d", &opcao);

    // processamento
    switch (opcao) {
        case 1:
            printf("Qual a unidade de origem?\n\n");
            printf("1) Graus\n");
            printf("2) Radianos\n");
            printf("Selecione uma opcao: \n");
            scanf("%d", &opcao);
            grau(opcao);
            break;
        case 2:
            printf("Qual a unidade de origem?\n\n");
            printf("1) Celsius\n");
            printf("2) Fahrenheit\n");
            printf("3) Kelvin\n");
            printf("Selecione uma opcao: \n");
            scanf("%d", &opcao);
            temp(opcao);
            break;
        default:
            printf("Opcao invalida\n");
            break;
    }

    return 0;
}
