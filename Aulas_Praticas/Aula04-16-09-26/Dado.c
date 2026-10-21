/* 
Introdução a Programação - Aula 4 
Rafael Andrade Câmara, 16/09/2026, 26.2.4022    
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {
    // declaracao de variaveis
    int faces, resultado;

    // entrada de dados
    printf("--- Simulador de Dados RPG ---\n");
    printf("Quantas faces tem o dado que voce quer rolar? ");
    scanf("%d", &faces);

    // processamento
    if (faces <= 0) {
        printf("Numero de faces invalido!\n");
        return 0;
    }

    srand(time(NULL)); // Inicializa o gerador de numeros aleatorios
    resultado = rand() % faces + 1;

    // exibicao do resultado
    printf("\nResultado do dado: %d\n", resultado);

    return 0;
}
