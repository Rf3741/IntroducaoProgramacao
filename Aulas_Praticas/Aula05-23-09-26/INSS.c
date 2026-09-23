/* 
Introdução a Programação - Aula 5 
Rafael Andrade Câmara, 23/09/2026, 26.2.4022    
*/

#include <stdio.h>
#include <math.h>
// lembrar do -lm no final por causa da biblioteca math.h

int main () {
    // declaracao de variaveis
    char Sexo;
    int Idade, Contribuicao = 0;

    // entrada de dados
    printf("Digite o sexo: \n");
    scanf("%c", &Sexo);
    printf("Digite a idade: \n");
    scanf("%d", &Idade);
    printf("Digite o tempo de contribuição para o INSS: \n");
    scanf("%d", &Contribuicao);

    // exibicao do resultado
    if (Sexo == 'M' && (Idade >= 65 || Contribuicao >= 35)) {
        printf("Você pode se aposentar com salário integral");
    } else if (Sexo == 'F' && (Idade >= 60 || Contribuicao >= 30)) {
        printf("Você pode se aposentar com salário integral");
    } else {
        printf("Você não pode se aposentar com salário integral");
    }

    return 0;
}
    