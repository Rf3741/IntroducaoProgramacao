/* 
Introdução a Programação - Aula 8 
Rafael Andrade Câmara, 14/10/2026, 26.2.4022    
*/

#include <stdio.h>

int main () {
    // declaracao de variaveis
    float nota1, nota2, media;

    // entrada de dados
    printf("Digite as notas do aluno: ");
    scanf("%f %f", &nota1, &nota2);

    while (nota1 >= 0 && nota2 >= 0) {
        // processamento
        media = (nota1 + nota2) / 2;

        // exibicao do resultado
        printf("A média das notas é %.1f\n\n", media);

        // entrada de dados
        printf("Digite as notas do aluno: ");
        scanf("%f %f", &nota1, &nota2);
    }

    return 0;
}
