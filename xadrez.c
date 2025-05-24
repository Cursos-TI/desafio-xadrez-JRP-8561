// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.


    // Nível Novato - Movimentação das Peças
    // Sugestão: Declare variáveis constantes para representar o número de casas que cada peça pode se mover.

    // Implementação de Movimentação do Bispo
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação do Bispo em diagonal.

    // Implementação de Movimentação da Torre
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Torre para a direita.

    // Implementação de Movimentação da Rainha
    // Sugestão: Utilize uma estrutura de repetição para simular a movimentação da Rainha para a esquerda.

    // Nível Aventureiro - Movimentação do Cavalo
    // Sugestão: Utilize loops aninhados para simular a movimentação do Cavalo em L.
    // Um loop pode representar a movimentação horizontal e outro vertical.

    // Nível Mestre - Funções Recursivas e Loops Aninhados
    // Sugestão: Substitua as movimentações das peças por funções recursivas.
    // Exemplo: Crie uma função recursiva para o movimento do Bispo.

    // Sugestão: Implemente a movimentação do Cavalo utilizando loops com variáveis múltiplas e condições avançadas.
    // Inclua o uso de continue e break dentro dos loops.


#include <stdio.h>

#define TAMANHO_TABULEIRO 8

// Movimentação da Torre usando um "for"
void moverTorre(int x, int y) {
    printf("Movimentos da Torre a partir de (%d, %d):\n", x, y);
    for (int i = 1; i < TAMANHO_TABULEIRO - y; i++) {
        printf("Direita: (%d, %d)\n", x, y + i);
    }
}

// Movimentação do Bispo com recursão
void moverBispo(int x, int y, int i) {
    if (i >= TAMANHO_TABULEIRO) return;

    if (x + i < TAMANHO_TABULEIRO && y + i < TAMANHO_TABULEIRO) printf("Cima, Direita: (%d, %d)\n", x + i, y + i);
    if (x - i >= 0 && y - i >= 0) printf("Baixo, Esquerda: (%d, %d)\n", x - i, y - i);
    if (x + i < TAMANHO_TABULEIRO && y - i >= 0) printf("Cima, Esquerda: (%d, %d)\n", x + i, y - i);
    if (x - i >= 0 && y + i < TAMANHO_TABULEIRO) printf("Baixo, Direita: (%d, %d)\n", x - i, y + i);

    moverBispo(x, y, i + 1);
}

// Movimentação da Rainha com "while"
void moverRainha(int x, int y) {
    printf("Movimentos da Rainha a partir de (%d, %d):\n", x, y);
    int i = 1;
    while (y - i >= 0) {
        printf("Esquerda: (%d, %d)\n", x, y - i);
        i++;
    }
}

// Movimentação do Cavalo com loops aninhados
void moverCavalo(int x, int y) {
    printf("Movimentos do Cavalo a partir de (%d, %d):\n", x, y);
    int movimentos[][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};

    for (int i = 0; i < 8; i++) {
        int novoX = x + movimentos[i][0];
        int novoY = y + movimentos[i][1];

        // Usando continue e break para validar posições no tabuleiro
        if (novoX < 0 || novoX >= TAMANHO_TABULEIRO || novoY < 0 || novoY >= TAMANHO_TABULEIRO) continue;
        printf("L em (%d, %d)\n", novoX, novoY);
    }
}

int main() {
    int posX = 4, posY = 4;

    moverTorre(posX, posY);
    moverBispo(posX, posY, 1);
    moverRainha(posX, posY);
    moverCavalo(posX, posY);

    return 0;
}