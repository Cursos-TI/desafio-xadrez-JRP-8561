// Desafio de Xadrez - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de movimentação das peças de xadrez.
// O objetivo é utilizar estruturas de repetição e funções para determinar os limites de movimentação dentro do jogo.

int main() {
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

void moverBispo(int x, int y) {
    printf("Movimentos do Bispo a partir de (%d, %d):\n", x, y);
    for (int i = 1; i < TAMANHO_TABULEIRO; i++) {
        printf("(%d, %d) | (%d, %d) | (%d, %d) | (%d, %d)\n", 
               x + i, y + i, x - i, y - i, x + i, y - i, x - i, y + i);
    }
}

void moverTorre(int x, int y) {
    printf("Movimentos da Torre a partir de (%d, %d):\n", x, y);
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        if (i != x) printf("(%d, %d) ", i, y);
    }
    printf("\n");
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        if (j != y) printf("(%d, %d) ", x, j);
    }
    printf("\n");
}

void moverRainha(int x, int y) {
    printf("Movimentos da Rainha a partir de (%d, %d):\n", x, y);
    moverBispo(x, y);
    moverTorre(x, y);
}

int main() {
    int posicaoX = 4, posicaoY = 4;

    moverBispo(posicaoX, posicaoY);
    moverTorre(posicaoX, posicaoY);
    moverRainha(posicaoX, posicaoY);

    return 0;
}
