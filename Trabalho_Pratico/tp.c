/*
Introdução a Programação - Aula 12
Rafael Andrade Câmara, 12/11/2026, 26.2.4022
*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void gerarGarrafas(int fase, int garrafas[][4]){    

    srand(time(NULL));
    int aleatorio = rand();

    int qGarrafas = fase*2 + 4; //fase 1: 6, fase 2: 8...

    for (int j = 0; j < qGarrafas; j++){
        for (int i = 0; i < 4; i++){
            int corValida = 0;
            do {
                int cor = ((aleatorio) % (qGarrafas - 1)); // 0-3 na fase 1
                int corAtual = 0;

                if (cor == 0){
                    for (int k = 0; k < qGarrafas; k++){
                        for (int l = 0; l < 4; l++){
                            if (garrafas[k][l] == cor){
                                corAtual++;
                            }
                        }
                    }
                    if (corAtual < 8){
                        garrafas[j][i] = cor;
                        aleatorio = rand();
                        corValida = 1;
                    } else {
                        aleatorio = rand();
                    }
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
        for (int i = 0; i < (fase * 2 + 4); i++){
            printf("   |[%d]|", garrafas[i][j]);
        }
        printf("\n");
    }
}

int topo(int garrafa[4]){
    int t = -1;
    for (int i = 0; i < 4; i++){
        if (garrafa[i] != 0){
            t = i;
        }
    }
    return t;
}

void jogada(int garrafas[][4], int fase){

    int escolha1 = 0, escolha2 = 0;
    do {
        if (escolha1 < 0 || escolha1 >= (fase * 2 + 4)) {
            printf("Escolha Invalida! Escolha outra garrafa!\n");
        }
        printf("qual garrafa deseja virar?\n");
        scanf("%d", &escolha1);
    } while (escolha1 < 0 || escolha1 >= (fase * 2 + 4));
    
    do {
        if (escolha2 < 0 || escolha2 >= (fase * 2 + 4) || escolha2 == escolha1) {
            printf("Escolha Invalida! Escolha outra garrafa!\n");
        }
        printf("deseja virar a garrafa %d em qual garrafa?\n", escolha1);
        scanf("%d", &escolha2);
    } while (escolha2 < 0 || escolha2 >= (fase * 2 + 4) || escolha2 == 2);
    
    int t1 = topo(garrafas[escolha1]);
    int t2 = topo(garrafas[escolha2]);

    if (escolha1 == escolha2 || t1 == -1){
        printf("Jogada invalida\n");
    } else if (t2 == 3){
        printf("Essa garrafa esta cheia\n");
    } else if (t2 != -1 && garrafas[escolha2][t2] != garrafas[escolha1][t1]){
        printf("As cores nao combinam\n");
    } else {
        int cor = garrafas[escolha1][t1];
        while (t1 >= 0 && garrafas[escolha1][t1] == cor && t2 < 3){
            t2++;
            garrafas[escolha2][t2] = cor;
            garrafas[escolha1][t1] = 0;
            t1--;
        }
    }
}

int jogar(int fase, int garrafas[][4]){
    int jogando = 0;

    do {
        printInterface(fase, garrafas);
        jogada(garrafas, fase);
    } while (jogando == 0);
}

int main() {

    int garrafas [10][4] = {0}; 

    for (int i = 0; i < 10; i++){
        for (int j = 0; j < 4; j++){
            garrafas[i][j] = -1;
        }
    }

    int fase = 1;
    int jogando = 0;
    int opcao = 0;

    do {
        opcao = 1;
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
