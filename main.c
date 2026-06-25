#include <stdio.h>

char alternaJogador(char jogadorAtual) {
    if (jogadorAtual =='X') {
        return 'O';
    } else {
        return 'X';
    }
}

int validaJogada(char tabuleiro[][3], int linha, int coluna) {
    if ((linha>=0 && linha<=2) && (coluna>=0 && coluna<=2)) {
        if(tabuleiro[linha][coluna]== ' '){
            return 1;
        }
    }
    return 0;
}

void imprimeTabuleiro(char tabuleiro[][3]) {
    int i, j;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++){
            if (j<2) {
                printf(" %c |", tabuleiro[i][j]);
            } else {
                printf(" %c ", tabuleiro[i][j]);
            }
        }
        printf("\n");
        if(i<2) {
            printf("-----------\n");
        }
    }
}

void inicializaTabuleiro(char tabuleiro[][3]) {
    int i, j;
    for(i=0; i<3; i++) {
        for(j=0; j<3; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
    }

int main() {
    char tabuleiro[3][3];
    char jogadorAtual = 'X';
    int linha, coluna;
    int jogadas = 0;

    printf("Jogo da Velha\n");
    inicializaTabuleiro(tabuleiro);

    while (jogadas < 9) {
        imprimeTabuleiro(tabuleiro);
        printf("Jogador %c, digite a linha e a coluna (de 1 a 3) que voce deseja: ", jogadorAtual);
        scanf("%d %d", &linha, &coluna);
        linha--;
        coluna--;

        if (validaJogada(tabuleiro, linha, coluna)) {
            tabuleiro[linha][coluna] = jogadorAtual;

            jogadas++;

            jogadorAtual = alternaJogador(jogadorAtual);
        } else {
            printf("Jogada invalida. Tente novamente.\n");
        }

    }
    return 0;
}