/* 
Introdução a Programação - Aula 5 
Rafael Andrade Câmara, 23/09/2026, 26.2.4022    
*/


#include <stdio.h>

int main() {
    // declaracao de variaveis
    int ano;

    // entrada de dados
    printf("Entre com o ano:\n");
    scanf("%d", &ano);

    // processamento de dados
    if (ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0)) {
        printf("O ano %d é bissexto\n", ano);
    } else {
        printf("O ano %d não é bissexto\n", ano);
    }

    return 0;
    
    // exibicao do resultado
    printf("O ano %d não é bissexto\n", ano);

    return 0;
}