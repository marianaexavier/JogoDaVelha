#ifndef TABULEIRO_H
#define TABULEIRO_H

#define VAZIO 0
#define O     1
#define X     4

void inicializaTabuleiro();
void desenha();
int posicaoLivre (int linha, int coluna);
int  marcaJogada(int linha, int coluna, int tipo);
int  temVencedor();

#endif