/* 
Introdução a Programação - Aula 5 
Rafael Andrade Câmara, 23/09/2026, 26.2.4022    
*/

#include <stdio.h>

int main () {
    // declaracao de variaveis
    int Matricula = 0;
    float nota = 0;

    // entrada de dados
    printf("Digite a matricula: ");
    scanf("%d", &Matricula);
    printf("Digite a nota: ");
    scanf("%f", &nota);

    // exibicao do resultado
    if (nota < 0 || nota > 10) {
        printf("Nota invalida!\n");
    } else {
        printf("Matricula: %d\n", Matricula);
        if (nota < 3) {
            printf("Conceito E\n");
        } else if (nota < 6) {
            printf("Conceito D\n");
        } else if (nota < 8) {
            printf("Conceito C\n");
        } else if (nota <= 9) {
            printf("Conceito B\n");
        } else {
            printf("Conceito A\n");
        }
    }

    return 0;
}
