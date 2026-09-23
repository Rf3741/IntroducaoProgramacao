/* 
Introdução a Programação - Aula 5 
Rafael Andrade Câmara, 23/09/2026, 26.2.4022    
*/


#include <stdio.h>

int main() {
    // declaracao de variaveis
    float preco;
    float valorFinal;
    int condicao;

    // entrada de dados
    printf("Digite o preco do produto: ");
    scanf("%f", &preco);

    printf("Digite a condicao de pagamento: ");
    scanf("%d", &condicao);

    // processamento de dados
    switch (condicao) {
        case 1:
            valorFinal = preco * 0.90;
            break;
        case 2:
            valorFinal = preco * 0.95;
            break;
        case 3:
            valorFinal = preco;
            break;
        case 4:
            valorFinal = preco * 1.10;
            break;
        default:
            printf("Condicao de pagamento invalida\n");
            return 0;
    }

    // exibicao do resultado
    printf("O valor final do seu produto sera: R$ %.2f\n", valorFinal);

    return 0;
}
