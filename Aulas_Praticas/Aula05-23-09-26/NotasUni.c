/* 
Introdução a Programação - Aula 5 
Rafael Andrade Câmara, 23/09/2026, 26.2.4022    
*/

#include <stdio.h>
#include <math.h>
// lembrar do -lm no final por causa da biblioteca math.h

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
    if (nota < 3) {
        printf("Matricula: %d\n", Matricula);
        printf("Conceito E\n");
    } else if (nota >= 3 && nota < 6) {
        printf("Matricula: %d\n", Matricula);
        printf("Conceito D\n");
    } else if (nota >= 6 && nota < 8) {
        printf("Matricula: %d\n", Matricula);
        printf("Conceito C\n");
    } else if (nota >= 8 && nota <= 9) {
        printf("Matricula: %d\n", Matricula);
        printf("Conceito B\n");
    } else if (nota > 9 && nota <= 10) {
        printf("Matricula: %d\n", Matricula);
        printf("Conceito A\n");
    } else {
        printf("Nota invalida!\n");
    }

    return 0;
}
    