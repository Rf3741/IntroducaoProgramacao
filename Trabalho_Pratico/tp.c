/*
Introdução a Programação - Aula 12
Rafael Andrade Câmara, 12/11/2026, 26.2.4022
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int menu() {
    int opcao;

    // 267
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿                                                                                                                                                                                                                                                                       ⣿⣿\n");
    printf("⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿\n");

    return scanf("%d", &opcao);
}

int jogar(int fase){    
    int garrafas [10][4] = {0}; 
    //matriz 10 linhas e 5 colunas, cada coluna representa uma fileira da garrafa

    srand(time(NULL));
    long long int aleatorio = rand();

    int qGarrafas = fase*2 + 2; //fase 1: 4, fase 2: 6...
    // 4 garrafas, 3 cores/ 6 garrafas, 5 cores...

    for (int j = 0; j < qGarrafas; j++){
        for (int i = 0; i < 4; i++){
            int corValida = 0;
            do {
                int cor = (aleatorio % (qGarrafas - 1)) + 1; // 1-3 na fase 1
                int corAtual = 0;

                for (int k = 0; k < 40; k++){
                    if (garrafas[j][i] == cor){
                        corAtual++;
                    }
                }
                if (corAtual < 4) {
                    corValida = 1;
                }
            } while (corValida == 0);
            // pega o ultimo digito do numero aleatorio descobre uma possivel por para ele de 1 aou numero de fase - 1
            // e verifica se ja nao existe o limita daquela cor
        }
    }

    printf("%d\n", aleatorio);
    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 4; j++){
            printf("%d\n", garrafas[i][j]);
        }
        printf("\n");
    }
}

int main() {

    int fase = 1;
    int jogando = 0;
    int opcao = 0;

    do {
        opcao = menu();
    } while (opcao < 0 || opcao > 4);

    switch (opcao){
        case 1:
            jogar(fase);
            break;
        case 2: 
            //selectFases();
            break;
        case 3:
            jogando = 1;
            break;
    }

    return 0;
}
