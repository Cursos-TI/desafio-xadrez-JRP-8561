#include <stdio.h>

#define TAMANHO_TABULEIRO 8

// Função para imprimir os índices das colunas
void imprimirIndicesColunas() {
    printf("   ");
    for (char letra = 'A'; letra < 'A' + TAMANHO_TABULEIRO; letra++) {
        printf(" %c  ", letra);
    }
    printf("\n");
}

// Função para imprimir uma linha do tabuleiro com índice de linha
void imprimirLinha(int linha) {
    printf("%2d ", linha + 1);  // Índice da linha
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        if ((linha + j) % 2 == 0) {
            printf("| | ");
        } else {
            printf("|X| ");
        }
    }
    printf("\n");
}

// Função para imprimir o tabuleiro completo
void imprimirTabuleiro() {
    imprimirIndicesColunas();  // Imprime os índices das colunas

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        imprimirLinha(i);  // Imprime cada linha do tabuleiro
    }
}

int main() {
    printf("Tabuleiro de Xadrez Virtual:\n\n");
    imprimirTabuleiro();
    
    return 0;
}