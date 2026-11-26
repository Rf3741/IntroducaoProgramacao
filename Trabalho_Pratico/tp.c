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

void gerarGarrafas(int fase, int garrafas[][4]){    

    srand(time(NULL));
    int aleatorio = rand();

    int qGarrafas = fase*2 + 2; //fase 1: 4, fase 2: 6...
    // 4 garrafas, 3 cores/ 6 garrafas, 5 cores...

    for (int j = 0; j < qGarrafas; j++){
        for (int i = 0; i < 4; i++){
            int corValida = 0;
            do {
                int cor = ((aleatorio) % qGarrafas); // 0-3 na fase 1
                int corAtual = 0;

                if (cor == 0){
                    garrafas[j][i] = cor;
                    aleatorio = rand();
                    corValida = 1;
                } else {
                    for (int k = 0; k < qGarrafas; k++){
                        for (int l = 0; l < 4; l++){
                            if (garrafas[k][l] == cor){
                                corAtual++;
                            }
                        }
                    }

                    if (corAtual < 4) {
                        aleatorio = rand();
                        garrafas[j][i] = cor;
                        corValida = 1;
                    } else {
                        aleatorio = rand();
                    }
                }
                
            } while (corValida == 0);
            // pega o ultimo digito do numero aleatorio descobre uma possivel por para ele de 1 aou numero de fase - 1
            // e verifica se ja nao existe o limita daquela cor
        }
    }

    system("clear");
    for (int i = 0; i < qGarrafas; i++){
        for (int j = 0; j < 4; j++){
            printf("%d\n", garrafas[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < qGarrafas; i++){
        for (int p = 0; p < 3; p++){           // repete a passada 3 vezes
            for (int j = 0; j < 3; j++){       // até 2, por causa do j+1
                if (garrafas[i][j] == 0 && garrafas[i][j+1] != 0){
                    garrafas[i][j] = garrafas[i][j+1];
                    garrafas[i][j+1] = 0;
                }
            }
        }
    }

    for (int i = 0; i < qGarrafas; i++){
        for (int j = 0; j < 4; j++){
            printf("%d\n", garrafas[i][j]);
        }
        printf("\n");
    }
}

int printInterface(int fase, int garrafas[][4]){
    for (int j = 3; j >= 0; j--){
        for (int i = 0; i < (fase * 2 + 2); i++){
            printf("   |[%d]|", garrafas[i][j]);
        }
        printf("\n");
    }
}

void jogada(int garrafas[][4]){
    int escolha1, escolha2;
    printf("qual garrafa deseja virar?\n");
    scanf("%d", &escolha1);
    printf("deseja virar a garrafa %d em qual garrafa?\n", escolha1);
    scanf("%d", &escolha2);

    
}

int jogar(int fase, int garrafas[][4]){

    printInterface(fase, garrafas);
    jogada(garrafas);
}

int main() {

    int garrafas [10][4] = {0}; 
    int fase = 1;
    int jogando = 0;
    int opcao = 0;

    do {
        opcao = menu();
    } while (opcao < 0 || opcao > 4);

    switch (opcao){
        case 1:
            gerarGarrafas(fase, garrafas);
            jogar(fase, garrafas);
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
