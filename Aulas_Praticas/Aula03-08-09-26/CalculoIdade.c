/* 
Introdução a Programação - Aula 3 
Rafael Andrade Câmara, 09/09/2026, 26.2.4022    
*/

#include <stdio.h>
#include <math.h>
// lembrar do -lm no final por causa da biblioteca math.h

int main () {
    // declaracao de variaveis
    int nascimento, ano_atual, idade = 0;

    // entrada de dados
    printf("Entre com o ano de nascimento:\n");
    scanf("%d", &nascimento);
    printf("Entre com o ano atual:\n");
    scanf("%d", &ano_atual);

    // processamento
    idade = ano_atual - nascimento;

    // exibicao do resultado
    printf("Voce tem = %d anos\n", idade);
    printf("Em %d voce tera = %d anos\n", ano_atual + 10, idade + 10);

    return 0;
}