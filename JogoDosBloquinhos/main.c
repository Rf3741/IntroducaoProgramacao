#include <stdio.h>
#include <locale.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int AnimacaoCarregamento(int segundos){
    int i = 0;
    while (i < segundos){
        system("clear");
        printf("Carregando");
        for(int j = 0; j < 3; j++){
            printf(".");
            fflush(stdout);
            usleep(333000); // Ajustado para usleep para funcionar a fração de segundo!
        }
        printf("\n");
        i++;
    }
    return 0;
}

//Desenhar os blocos na tela
int DesenharBlocos(int MapaBlocos[20][40], int Display[60][120], int i, int j){

    if (MapaBlocos[i][j] == 1){
        if (Display[i*3-1][j*3-1] == 1){ // Bloco esquedro cima
            printf("%s", "⣏⣉");
        } else if (Display[i*3-1][j*3] == 1){ // Bloco cima
            printf("%s", "⣏⣉");
        } else if (Display[i*3-1][j*3+1] == 1){ // bloco cima direito 
            printf("%s", "⣉⣹");
        } else if (Display[i][j-1] == 1){ // bloco esquerdo
            printf("%s", "⡧⠤");
        } else if (Display[i][j] == 2){ // bloco meio
            printf("%s", "⡤⠼");
        } else if (Display[i][j+1] == 1){ // bloco direito
            printf("%s", "⠤⢼");
        }else if (Display[i+1][j-1] == 1){ // bloco baixo esquerdo
            printf("%s", "⣗⣒");
        }else if (Display[i+1][j] == 1){ // bloco baixo
            printf("%s", "⣓⣲");
        }else if (Display[i+1][j+1] == 1){ // bloco baixo direito
            printf("%s", "⣒⣺");
        } else {
            printf("%s", "⣿⣿");
        }
    }
    return 0;
}

// Matriz alterada para 20x40
int GerarTela(int MapaBlocos[20][40], int Display[60][120]){
    int TelaGerada = 0;

    while (TelaGerada == 0){
        system("clear");
        //AnimacaoCarregamento(5); //testes
        system("clear");

        // Limite superior ajustado para 19 - mudado para 180
        for(int i = 59; i >= 0; i--){
            // Limite lateral ajustado para 40 - mudado para 360
            for(int j = 0; j < 119; j++){
                printf("%d", Display[i][j]);
                if(j == 0 || j == 118){
                    printf("%s", "⣗⣺");
                } 
                else if(i == 0 || i == 59){
                    printf("%s", "⣏⣏");
                }
                else if(MapaBlocos[i / 3][j / 3] == 1){
                    DesenharBlocos(MapaBlocos, Display, i / 3, j / 3);// Chama a função para desenhar os blocos
                } 
                else{
                    printf("  "); // Espaço vazio
                }
            }
            printf("\n");
        }

        TelaGerada = 1;
    }

    return 0;
}

// Matriz alterada para 20x40
int Preencher(int fase, int MapaBlocos[20][40], int Display[60][120]){
    if (fase == 1){
        for(int i = 0; i < 20; i++){
            for(int j = 0; j < 40; j++){
                if((i == 16 && j == 19) || (i == 16 && j == 20) || (i == 17 && j == 19) || (i == 17 && j == 20)){
                    MapaBlocos[i][j] = 1;
                    // 2. RENDERIZADOR 3x3
                    for (int k = 0; k < 3; k++){
                        for (int l = 0; l < 3; l++){
                            Display[(i * 3) + k][(j * 3) + l] = 1;
                        }
                    }
                    Display[(i * 3)][(j * 3)] = 2; // Bloco central em vermelho
                } else {
                    MapaBlocos[i][j] = 0;
                }
            }
        }
    }
    GerarTela(MapaBlocos, Display);
    return 0;
}

int GerarMenu(){
    int escolha = 0;
    system("clear");
    // Geração da tela do menu "bonitinha"
    printf("|==================================================================================================|\n");
    printf("|                                                                                                  |\n");
    printf("|                                           MENU PRINCIPAL                                         |\n");
    printf("|                                                                                                  |\n");
    printf("|                                                                                                  |\n");
    printf("|                                                                                                  |\n");
    printf("|                                       ======================                                     |\n");
    printf("|                                       |      1. Jogar      |                                     |\n");
    printf("|                                       ======================                                     |\n");
    printf("|                                                                                                  |\n");
    printf("|                                       ======================                                     |\n");
    printf("|                                       |  2. Configurações  |                                     |\n");
    printf("|                                       ======================                                     |\n");
    printf("|                                                                                                  |\n");
    printf("|                                       ======================                                     |\n");
    printf("|                                       |      3. Sair       |                                     |\n");
    printf("|                                       ======================                                     |\n");
    printf("|                                                                                                  |\n");
    printf("|                                                                                                  |\n");
    printf("|==================================================================================================|\n");

    scanf("%d", &escolha);
    if(escolha < 1 || escolha > 3){
        printf("Escolha inválida! Tente novamente.\n");
        sleep(3);
        system("clear");
        escolha = GerarMenu();
    } else {
        if(escolha == 2){
            printf("Você escolheu Configurações!\n");
            sleep(2);
            // implementar função de configurações depois
        } else if(escolha == 3){
            printf("Você escolheu Sair!\n");
            sleep(2);
            exit(0);
        }
    }
    return escolha;
}

int main() {
    // Configura a localidade para suportar caracteres especiais
    setlocale(LC_ALL, "");
    srand((unsigned) time(NULL));

    // Declarações de Variáveis:
    int escolha = 0;
    escolha = GerarMenu();
    
    int fase = 1;
    // Matriz declarada com 20x40
    int MapaBlocos[20][40] = {0}; // matriz de armazenamento das posições das entidades do jogo.
    int Display[60][120] = {0}; // matriz de estados para formar o display no terminal.

    if (escolha == 1){
        Preencher(fase, MapaBlocos, Display);
    }

    return 0;
}