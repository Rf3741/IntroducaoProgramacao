/* 
Introdução a Programação - Aula 3 
Rafael Andrade Câmara, 08/09/2026, 26.2.4022    
*/

#include <stdio.h>
#include <math.h>
// lembrar do -lm no final por causa da biblioteca math.h

int main () {
    // declaracao de variaveis
    int h, m, s, total = 0;

    // entrada de dados
    printf("Digite a hora, minutos e segundos:\n");
    scanf("%d %d %d", &h, &m, &s);
    
    // processamento
    total = (h * 3600) + (m * 60) + s;

    // exibicao do resultado
    printf("Total = %d\n", total);

    return 0;
}