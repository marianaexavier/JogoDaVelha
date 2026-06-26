#include <stdio.h>
#include "JogadorTeclado.h"
#include "Tabuleiro.h"

static char distinguirJogador(int tipo) {
    if (tipo == X) {
        return 'X';
    } else {
        return 'O';
    }
}

void joga(int tipo) {
    int linha, coluna;
    int sucesso;

    do {
    printf("Jogador %c, digite a linha e a coluna (1 a 3): ", distinguirJogador(tipo));
    scanf("%d %d", &linha, &coluna);
    linha--;
    coluna--;

    if (!posicaoLivre(linha, coluna)) {
        printf("Posição já ocupada. Tente novamente.\n");
    }
    } while (!posicaoLivre(linha, coluna));
    
    marcaJogada(linha, coluna, tipo);
}