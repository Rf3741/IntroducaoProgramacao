/* 
Introdução a Programação - Aula 4 
Rafael Andrade Câmara, 16/09/2026, 26.2.4022    
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int faces, resultado;
    /*
    printf("--- Simulador de Dados RPG ---\n");
    printf("Quantas faces tem o dado que voce quer rolar? ");
    */
    scanf("%d", &faces);

    srand(time(NULL)); // Inicializa o gerador de números aleatórios
    resultado = rand() % faces + 1;

    printf("\nResultado do dado: %d\n", resultado);

    return 0;
}