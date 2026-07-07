# Jogo da Velha
Projeto da disciplina de Programação Estruturada, do curso de Ciência de Dados e Inteligência Artificial da Universidade Federal da Paraíba.

## Objetivo
Este projeto tem como objetivo principal a implementação do jogo da velha com três
modos de jogo: jogador pelo teclado, jogador IA e jogador remoto. 

##  Integrantes
- Helena Couto dos Santos
- Mariana Esthefany Xavier dos Santos

## Compilação
`Compilação Jogo1`:
gcc main.c Partida.c JogadorTeclado.c Tabuleiro.c -o Jogo1

`Compilação Jogo2`:
gcc main.c JogadorIA.c JogadorTeclado.c Partida.c Regra.c Tabuleiro.c -o jogo_ia

`Compilação Jogo3`:
- Servidor:
gcc JogadorRemoto.c JogadorTeclado.c Partida.c Tabuleiro.c main_servidor.c -o jogo_serv 
- Cliente:
gcc JogadorRemoto.c JogadorTeclado.c Partida.c Tabuleiro.c main_cliente.c -o jogo_cliente