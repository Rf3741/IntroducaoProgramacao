/* 
Introdução a Programação - Aula 12
Rafael Andrade Câmara, 12/11/2026, 26.2.4022    
*/

#include <stdio.h>

#define MAX_ALUNOS 100

// retorna 1 se o aluno esta em recuperacao, 0 caso contrario
int esta_em_recuperacao (int nota, int nota_minima) {
    return nota < nota_minima;
}

// conta quantos alunos estao em recuperacao
int contar_recuperacao (int notas[], int quantidade, int nota_minima) {
    int i;
    int total;

    total = 0;
    for (i = 0; i < quantidade; i++) {
        if (esta_em_recuperacao(notas[i], nota_minima)) {
            total++;
        }
    }
    return total;
}

int main () {
    // declaracao de variaveis
    int notas[MAX_ALUNOS];
    int quantidade;
    int nota_minima;
    int total_recuperacao;
    int i;
    char separador;

    // entrada de dados
    quantidade = 0;
    printf("Digite as notas: ");
    do {
        scanf("%d%c", &notas[quantidade], &separador);
        quantidade++;
    } while (separador != '\n' && quantidade < MAX_ALUNOS);

    printf("Digite a nota mínima: ");
    scanf("%d", &nota_minima);

    // processamento
    total_recuperacao = contar_recuperacao(notas, quantidade, nota_minima);

    // exibicao do resultado
    printf("\nResultados dos alunos:\n");
    for (i = 0; i < quantidade; i++) {
        if (esta_em_recuperacao(notas[i], nota_minima)) {
            printf(". Aluno %d, nota %d: Recuperação\n", i + 1, notas[i]);
        } else {
            printf(". Aluno %d, nota %d: Férias\n", i + 1, notas[i]);
        }
    }

    printf("\nTotal de alunos em recuperação: %d\n", total_recuperacao);

    return 0;
}
