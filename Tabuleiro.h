#ifndef TABULEIRO_H
#define TABULEIRO_H

typedef enum {
    VAZIO  = 0,
    O      = 1,
    X      = 4,
    EMPATE = 2
} Representacao;

void inicializaTabuleiro();
void desenha();
int posicaoDisponivel(int linha, int coluna);
void marcaJogada(int linha, int coluna, int tipo);
int temVencedor();

#endif
