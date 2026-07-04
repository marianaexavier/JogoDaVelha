#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include "JogadorRemoto.h"
#include "Tabuleiro.h"

void aceitaConexao(JogadorRemoto *jr, int porta) {
    int servidor_fd, cliente_fd;
    struct sockaddr_in endereco;
    socklen_t endereco_len = sizeof(endereco);

    servidor_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (servidor_fd < 0) {
        perror("Erro ao criar socket");
        exit(EXIT_FAILURE);
    }

    endereco.sin_family = AF_INET;
    endereco.sin_addr.s_addr = INADDR_ANY;
    endereco.sin_port = htons(porta);

    if (bind(servidor_fd, (struct sockaddr *)&endereco, sizeof(endereco)) < 0) {
        perror("Erro no bind");
        close(servidor_fd);
        exit(EXIT_FAILURE);
    }

    if (listen(servidor_fd, 1) < 0) {
        perror("Erro no listen");
        close(servidor_fd);
        exit(EXIT_FAILURE);
    }

    printf("Servidor aguardando conexao na porta %d...\n", porta);

    cliente_fd = accept(servidor_fd, (struct sockaddr *)&endereco, &endereco_len);
    if (cliente_fd < 0) {
        perror("Erro no accept");
        close(servidor_fd);
        exit(EXIT_FAILURE);
    }

    printf("Cliente conectado!\n");

    jr->socketFd = cliente_fd;

    close(servidor_fd);
}

void conectaServidor(JogadorRemoto *jr, const char *ip, int porta) {
    struct sockaddr_in endereco;

    if ((jr->socketFd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Erro na criação do socket");
        exit(EXIT_FAILURE);
    }

    endereco.sin_family = AF_INET;
    endereco.sin_port = htons(porta);

    if (inet_pton(AF_INET, ip, &endereco.sin_addr) <= 0) {
        perror("Endereço de IP inválido ou não suportado");
        close(jr->socketFd);
        exit(EXIT_FAILURE);
    }

    printf("Tentando conectar ao servidor %s na porta %d...\n", ip, porta);

    if (connect(jr->socketFd, (struct sockaddr *)&endereco, sizeof(endereco)) < 0) {
        perror("Erro ao conectar no servidor. Ele está rodando?");
        close(jr->socketFd);
        exit(EXIT_FAILURE);
    }

    printf("Conectado ao servidor com sucesso!\n");
}