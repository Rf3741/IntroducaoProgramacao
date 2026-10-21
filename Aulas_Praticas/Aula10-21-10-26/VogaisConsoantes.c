/* 
Introdução a Programação - Aula 10 
Rafael Andrade Câmara, 21/10/2026, 26.2.4022    
*/

#include <stdio.h>

void limpar_buffer() {
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

int eh_vogal(char c) {
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
        return 1;
    }

    return 0;
}

int main () {
    // declaracao de variaveis
    char letras[10];
    char vogais[10];
    char consoantes[10];
    int qtd_vogais = 0;
    int qtd_consoantes = 0;

    // entrada de dados
    for (int i = 0; i < 10; i++) {
        printf("Digite o %d caractere: ", i + 1);
        scanf("%c", &letras[i]);
        limpar_buffer();
    }

    // processamento
    for (int i = 0; i < 10; i++) {
        if (eh_vogal(letras[i])) {
            vogais[qtd_vogais] = letras[i];
            qtd_vogais++;
        } else {
            consoantes[qtd_consoantes] = letras[i];
            qtd_consoantes++;
        }
    }

    // exibicao do resultado
    printf("\n%d vogais: ", qtd_vogais);
    for (int i = 0; i < qtd_vogais; i++) {
        printf("%c ", vogais[i]);
    }
    printf("\n");

    printf("\n%d consoantes: ", qtd_consoantes);
    for (int i = 0; i < qtd_consoantes; i++) {
        printf("%c ", consoantes[i]);
    }
    printf("\n");

    return 0;
}
