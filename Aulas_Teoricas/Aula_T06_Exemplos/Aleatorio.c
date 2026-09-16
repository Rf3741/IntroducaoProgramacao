#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h> // serve para pegar a hora atual do sistema e usar como semente
// gcc -o aleatorio aleatorio.c -lm
// lembrar do -lm no final por causa da biblioteca math.h

int main () {
    // declaracao de variaveis
    int a, b, aleatorio = 0;

    // entrada de dados
    printf("Defina os valores dos limites que vao ser usados para gerar o numero aleatorio:\n");
    printf("Digite o valor do limite inferior: ");
    scanf("%d", &a); // limite inferior
    printf("Digite o valor do limite superior: ");
    scanf("%d", &b); // limite superior

    // processamento
    srand(time(NULL)); // inicializa o gerador de numeros aleatorios com base no tempo atual
    aleatorio = a + rand() % (b - a + 1);

    // exibicao do resultado
    printf("O numero aleatorio gerado é: %d\n", aleatorio);

    return 0;
}