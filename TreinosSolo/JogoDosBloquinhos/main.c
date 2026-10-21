#include <stdio.h>
#include <locale.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <termios.h>
#include <fcntl.h>

#define ALTURA 60
#define LARGURA 240
#define MAPA_LINHAS 20
#define MAPA_COLUNAS 40
#define BLOCO_ALTURA 3
#define BLOCO_LARGURA 6

#define VAZIO 0
#define BLOCO 1
#define BARRA 3
#define BOLA 4
#define BLOCO_CENTRO 20

char LerTecla(void);
void RestaurarTeclado(void);
void MoverBarra(int direcao, int Display[ALTURA][LARGURA]);
void MoverBola(int Display[ALTURA][LARGURA], int *iBola, int *jBola, int *iVelocidade, int *jVelocidade);
int TemBlocos(int Display[ALTURA][LARGURA]);
struct termios TerminalOriginal;
int TecladoConfigurado = 0;
// para o compilador nao implicar com a funcao de mover a barra, que esta declarada depois do main

void AnimacaoCarregamento(int segundos){
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
}

//Desenhar os blocos na tela
void DesenharBlocos(int Display[ALTURA][LARGURA], int i, int j){
    int linha = i % BLOCO_ALTURA;
    int coluna = j % BLOCO_LARGURA;

    if (linha == 0){
        if (coluna == 0){
            printf("⣏");
        } else if (coluna == BLOCO_LARGURA - 1){
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
}

void DesenharBarra(int Display[ALTURA][LARGURA], int i, int j){
    int esquerda = (j == 0 || Display[i][j - 1] != BARRA);
    int direita = (j == LARGURA - 1 || Display[i][j + 1] != BARRA);

    if (esquerda){
        printf("⣏");
    } else if (direita){
        printf("⣹");
    } else {
        printf("⣉");
    }
}

void DesenharBola(void){
    printf("⣿");
}

int GerarTela(int MapaBlocos[MAPA_LINHAS][MAPA_COLUNAS], int Display[ALTURA][LARGURA], int *iBola, int *jBola, int *iVelocidade, int *jVelocidade){
    int TelaGerada = 0;

    printf("\033[?7l");

    while (TelaGerada == 0){
        printf("\033[H");

        for(int i = ALTURA - 1; i >= 0; i--){
            printf("\033[2K"); // Limpa a linha atual
            for(int j = 0; j < LARGURA; j++){
                if(j == 0 || j == LARGURA - 1){
                    printf("⣗");
                } 
                else if(i == 0 || i == ALTURA - 1){
                    printf("⣏");
                }
                else if(Display[i][j] != VAZIO && Display[i][j] != BARRA && Display[i][j] != BOLA){
                    DesenharBlocos(Display, i, j);
                } 
                else if(Display[i][j] == BARRA){
                    DesenharBarra(Display, i, j);
                }
                else if(Display[i][j] == BOLA){
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

int Preencher(int fase, int MapaBlocos[MAPA_LINHAS][MAPA_COLUNAS], int Display[ALTURA][LARGURA]){
    if (fase == 1){
        for(int i = 0; i < MAPA_LINHAS; i++){
            for(int j = 0; j < MAPA_COLUNAS; j++){
                if((i == 16 && j == 19) || (i == 16 && j == 20) || (i == 17 && j == 19) || (i == 17 && j == 20)){
                    MapaBlocos[i][j] = BLOCO;
                    // Cada bloco ocupa 3x6 caracteres Braille.
                    for (int k = 0; k < BLOCO_ALTURA; k++){
                        for (int l = 0; l < BLOCO_LARGURA; l++){
                            Display[(i * BLOCO_ALTURA) + k][(j * BLOCO_LARGURA) + l] = BLOCO;
                        }
                    }
                    Display[(i * BLOCO_ALTURA + 1)][(j * BLOCO_LARGURA + 3)] = BLOCO_CENTRO; // Centro do bloco
                } else if (i == 2 && (j == 19 || j == 20)){
                    MapaBlocos[i][j] = BARRA;
                    // Barra com duas linhas de altura
                    for (int k = 0; k < 2; k++){
                        for (int l = 0; l < BLOCO_LARGURA; l++){
                            Display[(i * BLOCO_ALTURA) + k][(j * BLOCO_LARGURA) + l] = BARRA;
                        }
                    }
                } else {
                    MapaBlocos[i][j] = VAZIO;
                }
            }
        }

        // Aumenta a barra em um caractere visual de cada lado.
        for (int k = 0; k < 2; k++){
            Display[(2 * BLOCO_ALTURA) + k][(19 * BLOCO_LARGURA) - 1] = BARRA;
            Display[(2 * BLOCO_ALTURA) + k][(20 * BLOCO_LARGURA) + BLOCO_LARGURA] = BARRA;
        }
    }

    int iBola = 12 * BLOCO_ALTURA + 1;
    int jBola = 19 * BLOCO_LARGURA + 3;
    int iVelocidade = -1;
    int jVelocidade = 0;
    Display[iBola][jBola] = BOLA;
    Display[iBola][jBola + 1] = BOLA;
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

int TemBlocos(int Display[ALTURA][LARGURA]){
    for(int i = 0; i < ALTURA; i++){
        for(int j = 0; j < LARGURA; j++){
            if(Display[i][j] != VAZIO && Display[i][j] != BARRA && Display[i][j] != BOLA){
                return 1;
            }
        }
    }
    return 0;
}

void QuebrarBloco(int Display[ALTURA][LARGURA], int i, int j){
    int inicioI = (i / BLOCO_ALTURA) * BLOCO_ALTURA;
    int inicioJ = (j / BLOCO_LARGURA) * BLOCO_LARGURA;

    for(int blocoI = inicioI; blocoI < inicioI + BLOCO_ALTURA; blocoI++){
        for(int blocoJ = inicioJ; blocoJ < inicioJ + BLOCO_LARGURA; blocoJ++){
            if(Display[blocoI][blocoJ] != BARRA && Display[blocoI][blocoJ] != BOLA){
                Display[blocoI][blocoJ] = VAZIO;
            }
        }
    }
}

void MoverBola(int Display[ALTURA][LARGURA], int *iBola, int *jBola, int *iVelocidade, int *jVelocidade){
    static int contador = 0;
    contador++;
    if(contador < 3){
        return;
    }
    contador = 0;

    int iProximo = *iBola + *iVelocidade;
    int jProximo = *jBola + *jVelocidade;

    if(iProximo <= 1 || iProximo >= ALTURA - 2){
        *iVelocidade *= -1;
        iProximo = *iBola + *iVelocidade;
    }

    if(jProximo <= 1 || jProximo >= LARGURA - 3){
        *jVelocidade *= -1;
        jProximo = *jBola + *jVelocidade;
    }

    int bateuBarra = 0;
    for(int j = jProximo; j <= jProximo + 1; j++){
        if(Display[iProximo][j] == BARRA){
            bateuBarra = 1;
        }
    }

    if(bateuBarra && *iVelocidade < 0){
        int menorColuna = LARGURA;
        int maiorColuna = -1;

        for(int i = 0; i < ALTURA; i++){
            for(int j = 0; j < LARGURA; j++){
                if(Display[i][j] == BARRA){
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
            if(Display[iProximo][j] != VAZIO && Display[iProximo][j] != BARRA && Display[iProximo][j] != BOLA){
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
    if(iProximo > ALTURA - 2) iProximo = ALTURA - 2;
    if(jProximo < 1) jProximo = 1;
    if(jProximo > LARGURA - 3) jProximo = LARGURA - 3;

    for(int j = jProximo; j <= jProximo + 1; j++){
        if(Display[iProximo][j] != VAZIO && Display[iProximo][j] != BOLA){
            return;
        }
    }

    for(int j = *jBola; j <= *jBola + 1; j++){
        Display[*iBola][j] = VAZIO;
    }

    *iBola = iProximo;
    *jBola = jProximo;
    for(int j = *jBola; j <= *jBola + 1; j++){
        Display[*iBola][j] = BOLA;
    }
}

void MoverBarra(int direcao, int Display[ALTURA][LARGURA]){
    int menorLinha = ALTURA;
    int maiorLinha = -1;
    int menorColuna = LARGURA;
    int maiorColuna = -1;

    for(int i = 0; i < ALTURA; i++){
        for(int j = 0; j < LARGURA; j++){
            if(Display[i][j] == BARRA){
                if(i < menorLinha) menorLinha = i;
                if(i > maiorLinha) maiorLinha = i;
                if(j < menorColuna) menorColuna = j;
                if(j > maiorColuna) maiorColuna = j;
            }
        }
    }

    if(maiorLinha == -1 || direcao == 0){
        return;
    }

    int deslocamento = direcao * BLOCO_LARGURA;
    if(menorColuna + deslocamento < 1 || maiorColuna + deslocamento > LARGURA - 2){
        return;
    }

    for(int i = menorLinha; i <= maiorLinha; i++){
        for(int j = menorColuna; j <= maiorColuna; j++){
            if(Display[i][j] == BARRA){
                Display[i][j] = VAZIO;
            }
        }
    }

    for(int i = menorLinha; i <= maiorLinha; i++){
        for(int j = menorColuna; j <= maiorColuna; j++){
            Display[i][j + deslocamento] = BARRA;
        }
    }
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
            int MapaBlocos[MAPA_LINHAS][MAPA_COLUNAS] = {0};
            int Display[ALTURA][LARGURA] = {0};
            Preencher(fase, MapaBlocos, Display);
        }
    } while (escolha != 3);

    return 0;
}
