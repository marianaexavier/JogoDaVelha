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

    printf("Jogador %c, digite a linha e a coluna (1 a 3): ", distinguirJogador(tipo));
    scanf("%d %d", &linha, &coluna);
    linha--;
    coluna--;

    marcaJogada(linha, coluna, tipo);
}