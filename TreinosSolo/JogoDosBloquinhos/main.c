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
void RestaurarTeclado(void);
int MoverBarra(int direcao, int Display[60][240]);
int MoverBola(int Display[60][240], int *iBola, int *jBola, int *iVelocidade, int *jVelocidade);
int TemBlocos(int Display[60][240]);
struct termios TerminalOriginal;
int TecladoConfigurado = 0;
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
int DesenharBlocos(int Display[60][240], int i, int j){
    int linha = i % 3;
    int coluna = j % 6;

    if (linha == 0){
        if (coluna == 0){
            printf("⣏");
        } else if (coluna == 5){
            printf("⣹");
        } else {
            printf("⣉");
        }
    } else if (linha == 1){
        if (coluna == 0){
            printf("⡧");
        } else if (coluna == 1){
            printf("⠤");
        } else if (coluna == 2){
            printf("⡤");
        } else if (coluna == 3){
            printf("⠼");
        } else if (coluna == 4){
            printf("⠤");
        } else {
            printf("⢼");
        }
    } else {
        if (coluna == 0){
            printf("⣗");
        } else if (coluna == 1){
            printf("⣒");
        } else if (coluna == 2){
            printf("⣓");
        } else if (coluna == 3){
            printf("⣲");
        } else if (coluna == 4){
            printf("⣒");
        } else {
            printf("⣺");
        }
    }
    return 0;
}

int DesenharBarra(int Display[60][240], int i, int j){
    int esquerda = (j == 0 || Display[i][j - 1] != 3);
    int direita = (j == 239 || Display[i][j + 1] != 3);

    if (esquerda && direita){
        printf("⣏");
    } else if (esquerda){
        printf("⣏");
    } else if (direita){
        printf("⣹");
    } else {
        printf("⣉");
    }
    return 0;
}

int DesenharBola(void){
    printf("⣿");
    return 0;
}

// Matriz alterada para 20x40
int GerarTela(int MapaBlocos[20][40], int Display[60][240], int *iBola, int *jBola, int *iVelocidade, int *jVelocidade){
    int TelaGerada = 0;

    printf("\033[?7l");

    while (TelaGerada == 0){
        printf("\033[H");

        // Limite superior ajustado para 19 - mudado para 180
        for(int i = 59; i >= 0; i--){
            printf("\033[2K"); // Limpa a linha atual
            // Limite lateral ajustado para 40 - mudado para 360
            for(int j = 0; j < 240; j++){
                if(j == 0 || j == 239){
                    printf("⣗");
                } 
                else if(i == 0 || i == 59){
                    printf("⣏");
                }
                else if(Display[i][j] != 0 && Display[i][j] != 3 && Display[i][j] != 4){
                    DesenharBlocos(Display, i, j);
                } 
                else if(Display[i][j] == 3){
                    DesenharBarra(Display, i, j);
                }
                else if(Display[i][j] == 4){
                    DesenharBola();
                }
                else{
                    printf(" "); // Espaço vazio
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
            RestaurarTeclado();
            printf("\033[?7h");
            printf("Saindo do jogo...\n");
            sleep(2);
            system("clear");
            exit(0);
            TelaGerada = 1;
        }

        MoverBola(Display, iBola, jBola, iVelocidade, jVelocidade);

        if(!TemBlocos(Display)){
            RestaurarTeclado();
            printf("\033[?7h");
            printf("\033[2J\033[H");
            printf("VOCE GANHOU!\n");
            fflush(stdout);
            sleep(3);
            printf("\033[2J\033[H");
            return 1;
        }

        fflush(stdout);
        usleep(30000);
    }

    return 0;
}

// Matriz alterada para 20x40
int Preencher(int fase, int MapaBlocos[20][40], int Display[60][240]){
    if (fase == 1){
        for(int i = 0; i < 20; i++){
            for(int j = 0; j < 40; j++){
                if((i == 16 && j == 19) || (i == 16 && j == 20) || (i == 17 && j == 19) || (i == 17 && j == 20)){
                    MapaBlocos[i][j] = 1;
                    // Cada bloco ocupa 3x6 caracteres Braille.
                    for (int k = 0; k < 3; k++){
                        for (int l = 0; l < 6; l++){
                            Display[(i * 3) + k][(j * 6) + l] = 1;
                        }
                    }
                    Display[(i * 3 + 1)][(j * 6 + 3)] = 20; // Centro do bloco
                } else if (i == 2 && (j == 19 || j == 20)){
                    MapaBlocos[i][j] = 3;
                    // Barra com duas linhas de altura
                    for (int k = 0; k < 2; k++){
                        for (int l = 0; l < 6; l++){
                            Display[(i * 3) + k][(j * 6) + l] = 3;
                        }
                    }
                } else {
                    MapaBlocos[i][j] = 0;
                }
            }
        }

        // Aumenta a barra em um caractere visual de cada lado.
        for (int k = 0; k < 2; k++){
            Display[(2 * 3) + k][(19 * 6) - 1] = 3;
            Display[(2 * 3) + k][(20 * 6) + 6] = 3;
        }
    }

    int iBola = 12 * 3 + 1;
    int jBola = 19 * 6 + 3;
    int iVelocidade = -1;
    int jVelocidade = 0;
    Display[iBola][jBola] = 4;
    Display[iBola][jBola + 1] = 4;
    return GerarTela(MapaBlocos, Display, &iBola, &jBola, &iVelocidade, &jVelocidade);
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
    char ch = 0;
    if (!TecladoConfigurado){
        struct termios novoTerminal;
        tcgetattr(STDIN_FILENO, &TerminalOriginal);
        novoTerminal = TerminalOriginal;
        novoTerminal.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &novoTerminal);
        fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
        TecladoConfigurado = 1;
    }

    if (read(STDIN_FILENO, &ch, 1) != 1){
        return '\0';
    }
    return ch;
}

void RestaurarTeclado(void){
    if (TecladoConfigurado){
        tcsetattr(STDIN_FILENO, TCSANOW, &TerminalOriginal);
        TecladoConfigurado = 0;
    }
}

int TemBlocos(int Display[60][240]){
    for(int i = 0; i < 60; i++){
        for(int j = 0; j < 240; j++){
            if(Display[i][j] != 0 && Display[i][j] != 3 && Display[i][j] != 4){
                return 1;
            }
        }
    }
    return 0;
}

int QuebrarBloco(int Display[60][240], int i, int j){
    int inicioI = (i / 3) * 3;
    int inicioJ = (j / 6) * 6;

    for(int blocoI = inicioI; blocoI < inicioI + 3; blocoI++){
        for(int blocoJ = inicioJ; blocoJ < inicioJ + 6; blocoJ++){
            if(Display[blocoI][blocoJ] != 3 && Display[blocoI][blocoJ] != 4){
                Display[blocoI][blocoJ] = 0;
            }
        }
    }
    return 0;
}

int MoverBola(int Display[60][240], int *iBola, int *jBola, int *iVelocidade, int *jVelocidade){
    static int contador = 0;
    contador++;
    if(contador < 3){
        return 0;
    }
    contador = 0;

    int iProximo = *iBola + *iVelocidade;
    int jProximo = *jBola + *jVelocidade;

    if(iProximo <= 1 || iProximo >= 58){
        *iVelocidade *= -1;
        iProximo = *iBola + *iVelocidade;
    }

    if(jProximo <= 1 || jProximo >= 237){
        *jVelocidade *= -1;
        jProximo = *jBola + *jVelocidade;
    }

    int bateuBarra = 0;
    for(int j = jProximo; j <= jProximo + 1; j++){
        if(Display[iProximo][j] == 3){
            bateuBarra = 1;
        }
    }

    if(bateuBarra && *iVelocidade < 0){
        int menorColuna = 240;
        int maiorColuna = -1;

        for(int i = 0; i < 60; i++){
            for(int j = 0; j < 240; j++){
                if(Display[i][j] == 3){
                    if(j < menorColuna) menorColuna = j;
                    if(j > maiorColuna) maiorColuna = j;
                }
            }
        }

        int centroBarra = (menorColuna + maiorColuna) / 2;
        int pontoDeContato = jProximo;
        int distanciaDoCentro = pontoDeContato - centroBarra;

        *iVelocidade = 1;
        if(distanciaDoCentro <= -4){
            *jVelocidade = -1;
        } else if(distanciaDoCentro >= 4){
            *jVelocidade = 1;
        }

        iProximo = *iBola + *iVelocidade;
        jProximo = *jBola + *jVelocidade;
    } else {
        int bateuBloco = 0;
        for(int j = jProximo; j <= jProximo + 1; j++){
            if(Display[iProximo][j] != 0 && Display[iProximo][j] != 3 && Display[iProximo][j] != 4){
                bateuBloco = 1;
            }
        }

        if(bateuBloco){
            QuebrarBloco(Display, iProximo, jProximo);
            *iVelocidade *= -1;
            iProximo = *iBola + *iVelocidade;
        }
    }

    if(iProximo < 1) iProximo = 1;
    if(iProximo > 58) iProximo = 58;
    if(jProximo < 1) jProximo = 1;
    if(jProximo > 237) jProximo = 237;

    for(int j = jProximo; j <= jProximo + 1; j++){
        if(Display[iProximo][j] != 0 && Display[iProximo][j] != 4){
            return 0;
        }
    }

    for(int j = *jBola; j <= *jBola + 1; j++){
        Display[*iBola][j] = 0;
    }

    *iBola = iProximo;
    *jBola = jProximo;
    for(int j = *jBola; j <= *jBola + 1; j++){
        Display[*iBola][j] = 4;
    }
    return 0;
}

int MoverBarra(int direcao, int Display[60][240]){
    int menorLinha = 60;
    int maiorLinha = -1;
    int menorColuna = 240;
    int maiorColuna = -1;

    for(int i = 0; i < 60; i++){
        for(int j = 0; j < 240; j++){
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

    int deslocamento = direcao * 6;
    if(menorColuna + deslocamento < 1 || maiorColuna + deslocamento > 238){
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
    int fase = 1;
    int escolha;

    do {
        escolha = GerarMenu();
        if (escolha == 1){
            int MapaBlocos[20][40] = {0};
            int Display[60][240] = {0};
            Preencher(fase, MapaBlocos, Display);
        }
    } while (escolha != 3);

    return 0;
}