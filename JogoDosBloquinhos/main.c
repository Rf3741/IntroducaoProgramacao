#include <stdio.h>
#include <locale.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

char LerTecla(void);
int MoverBarra(int direcao, int Display[60][120]);
int MoverBola(int Display[60][120], int *bolaI, int *bolaJ, int *velocidadeI, int *velocidadeJ);
// para o compilador nao implicar com a funcao de mover a barra, que esta declarada depois do main

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

    if (Display[i-1][j+1] == 20){ // Bloco esquedro cima
        printf("%s", "⣏⣉");
    } else if (Display[i-1][j] == 20){ // Bloco cima
        printf("%s", "⣏⣉");
    } else if (Display[i-1][j-1] == 20){ // bloco cima direito 
        printf("%s", "⣉⣹");
    } else if (Display[i][j+1] == 20){ // bloco esquerdo
        printf("%s", "⡧⠤");
    } else if (Display[i][j] == 20){ // bloco meio
        printf("%s", "⡤⠼");
    } else if (Display[i][j-1] == 20){ // bloco direito
        printf("%s", "⠤⢼");
    }else if (Display[i+1][j+1] == 20){ // bloco baixo esquerdo
        printf("%s", "⣗⣒");
    }else if (Display[i+1][j] == 20){ // bloco baixo
        printf("%s", "⣓⣲");
    }else if (Display[i+1][j-1] == 20){ // bloco baixo direito
        printf("%s", "⣒⣺");
    } else {
        printf("%s", "⣿⣿");
    }
    return 0;
}

int DesenharBarra(int Display[60][120], int i, int j){
    int esquerda = (j == 0 || Display[i][j - 1] != 3);
    int direita = (j == 119 || Display[i][j + 1] != 3);

    if (esquerda && direita){
        printf("%s", "⣏⣹");
    } else if (esquerda){
        printf("%s", "⣏⣉");
    } else if (direita){
        printf("%s", "⣉⣹");
    } else {
        printf("%s", "⣉⣉");
    }
    return 0;
}

int DesenharBola(void){
    printf("%s", "⣿⣿");
    return 0;
}

// Matriz alterada para 20x40
int GerarTela(int MapaBlocos[20][40], int Display[60][120], int *bolaI, int *bolaJ, int *velocidadeI, int *velocidadeJ){
    int TelaGerada = 0;

    while (TelaGerada == 0){
        printf("\033[H");

        // Limite superior ajustado para 19 - mudado para 180
        for(int i = 59; i >= 0; i--){
            printf("\033[2K"); // Limpa a linha atual
            // Limite lateral ajustado para 40 - mudado para 360
            for(int j = 0; j < 119; j++){
                //printf("%d", Display[i][j]);
                if(j == 0 || j == 118){
                    printf("%s", "⣗⣺");
                } 
                else if(i == 0 || i == 59){
                    printf("%s", "⣏⣏");
                }
                else if(Display[i][j] != 0 && Display[i][j] != 3 && Display[i][j] != 4){
                    DesenharBlocos(MapaBlocos, Display, i, j);// Chama a função para desenhar os blocos
                } 
                else if(Display[i][j] == 3){
                    DesenharBarra(Display, i, j);
                }
                else if(Display[i][j] == 4){
                    DesenharBola();
                }
                else{
                    printf("  "); // Espaço vazio
                }
            }
            printf("\n");
        }
         // Lê a tecla pressionada
        char tecla = LerTecla();
        int direcao = 0;

        if (tecla == 'a') {
            // Move barra para esquerda
            direcao = -1;
            MoverBarra(direcao, Display);
        } else if (tecla == 'd') {
            // Move barra para direita
            direcao = 1;
            MoverBarra(direcao, Display);
        } else if (tecla == 'p') {
            // Sai do jogo
            printf("Saindo do jogo...\n");
            sleep(2);
            system("clear");
            exit(0);
            TelaGerada = 1;
        }

        MoverBola(Display, bolaI, bolaJ, velocidadeI, velocidadeJ);

        fflush(stdout);
        usleep(60000);
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
                    Display[(i * 3 + 1)][(j * 3 + 1)] = 20; // Centro do bloco
                } else if (i == 2 && (j == 19 || j == 20)){
                    MapaBlocos[i][j] = 3;
                    // Barra com duas linhas de altura
                    for (int k = 0; k < 2; k++){
                        for (int l = 0; l < 3; l++){
                            Display[(i * 3) + k][(j * 3) + l] = 3;
                        }
                    }
                } else {
                    MapaBlocos[i][j] = 0;
                }
            }
        }

        // Aumenta a barra em um caractere visual de cada lado.
        for (int k = 0; k < 2; k++){
            Display[(2 * 3) + k][(19 * 3) - 1] = 3;
            Display[(2 * 3) + k][(20 * 3) + 3] = 3;
        }
    }

    int bolaI = 14 * 3 + 1;
    int bolaJ = 19 * 3 + 1;
    int velocidadeI = -1;
    int velocidadeJ = 0;
    Display[bolaI][bolaJ] = 4;
    GerarTela(MapaBlocos, Display, &bolaI, &bolaJ, &velocidadeI, &velocidadeJ);
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

// Função que lê o teclado sem pausar o jogo
char LerTecla() {
    struct termios oldt, newt;
    char ch = 0;
    int oldf;

    // 1. Salva as configurações atuais do terminal
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    
    // 2. Desativa a espera pelo 'Enter' (ICANON) e o visual da tecla (ECHO)
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    
    // 3. Torna a leitura "não-bloqueante" (se não tiver tecla, ele passa direto)
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    // 4. Tenta capturar a tecla
    ch = getchar();

    // 5. Restaura o terminal ao normal imediatamente para não bugar o Linux
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch == EOF) {
        return '\0'; // Retorna vazio se nenhuma tecla foi apertada
    }
    return ch;
}

int QuebrarBloco(int Display[60][120], int i, int j){
    int inicioI = (i / 3) * 3;
    int inicioJ = (j / 3) * 3;

    for(int blocoI = inicioI; blocoI < inicioI + 3; blocoI++){
        for(int blocoJ = inicioJ; blocoJ < inicioJ + 3; blocoJ++){
            if(Display[blocoI][blocoJ] != 3 && Display[blocoI][blocoJ] != 4){
                Display[blocoI][blocoJ] = 0;
            }
        }
    }
    return 0;
}

int MoverBola(int Display[60][120], int *bolaI, int *bolaJ, int *velocidadeI, int *velocidadeJ){
    int proximaI = *bolaI + *velocidadeI;
    int proximaJ = *bolaJ + *velocidadeJ;

    if(proximaI <= 1 || proximaI >= 58){
        *velocidadeI *= -1;
        proximaI = *bolaI + *velocidadeI;
    }

    if(proximaJ <= 1 || proximaJ >= 118){
        *velocidadeJ *= -1;
        proximaJ = *bolaJ + *velocidadeJ;
    }

    if(Display[proximaI][proximaJ] == 3 && *velocidadeI < 0){
        int menorColuna = 120;
        int maiorColuna = -1;

        for(int i = 0; i < 60; i++){
            for(int j = 0; j < 120; j++){
                if(Display[i][j] == 3){
                    if(j < menorColuna) menorColuna = j;
                    if(j > maiorColuna) maiorColuna = j;
                }
            }
        }

        int centroBarra = (menorColuna + maiorColuna) / 2;
        int distanciaDoCentro = proximaJ - centroBarra;

        *velocidadeI = 1;
        if(distanciaDoCentro <= -2){
            *velocidadeJ = -1;
        } else if(distanciaDoCentro >= 2){
            *velocidadeJ = 1;
        } else {
            *velocidadeJ = 0;
        }

        proximaI = *bolaI + *velocidadeI;
        proximaJ = *bolaJ + *velocidadeJ;
    } else if(Display[proximaI][proximaJ] != 0 &&
              Display[proximaI][proximaJ] != 3 &&
              Display[proximaI][proximaJ] != 4){
        QuebrarBloco(Display, proximaI, proximaJ);
        *velocidadeI *= -1;
        proximaI = *bolaI + *velocidadeI;
    }

    if(Display[proximaI][proximaJ] != 0){
        return 0;
    }

    Display[*bolaI][*bolaJ] = 0;
    *bolaI = proximaI;
    *bolaJ = proximaJ;
    Display[*bolaI][*bolaJ] = 4;
    return 0;
}

int MoverBarra(int direcao, int Display[60][120]){
    int menorLinha = 60;
    int maiorLinha = -1;
    int menorColuna = 120;
    int maiorColuna = -1;

    for(int i = 0; i < 60; i++){
        for(int j = 0; j < 120; j++){
            if(Display[i][j] == 3){
                if(i < menorLinha) menorLinha = i;
                if(i > maiorLinha) maiorLinha = i;
                if(j < menorColuna) menorColuna = j;
                if(j > maiorColuna) maiorColuna = j;
            }
        }
    }

    if(maiorLinha == -1 || direcao == 0){
        return 0;
    }

    int deslocamento = direcao * 3;
    if(menorColuna + deslocamento < 1 || maiorColuna + deslocamento > 117){
        return 0;
    }

    for(int i = menorLinha; i <= maiorLinha; i++){
        for(int j = menorColuna; j <= maiorColuna; j++){
            if(Display[i][j] == 3){
                Display[i][j] = 0;
            }
        }
    }

    for(int i = menorLinha; i <= maiorLinha; i++){
        for(int j = menorColuna; j <= maiorColuna; j++){
            Display[i][j + deslocamento] = 3;
        }
    }
    return 0;
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