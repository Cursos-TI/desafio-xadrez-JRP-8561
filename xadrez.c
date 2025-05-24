#include <stdio.h>

#define TAMANHO_TABULEIRO 8

// Função para imprimir os índices das colunas com espaçamento adequado
void imprimirIndicesColunas() {
    printf("     "); // Espaço inicial para alinhar com os índices das linhas
    for (char letra = 'A'; letra < 'A' + TAMANHO_TABULEIRO; letra++) {
        printf(" %c   ", letra); // Espaços extras para alinhar ao tabuleiro
    }
    printf("\n");
}

// Função para imprimir uma linha do tabuleiro com posicionamento das peças
void imprimirLinha(int linha) {
    printf("%2d   ", linha + 1); // Índice da linha com espaço extra
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        // Adicionando as peças nas coordenadas solicitadas
        if (linha == 0 && j == 2) {
            printf("|B1| ");  // Bispo 1 em C1
        } else if (linha == 0 && j == 5) {
            printf("|B2| ");  // Bispo 2 em F1
        } else if (linha == 0 && j == 4) {
            printf("|RA| ");  // Rainha em E1
        } else if (linha == 0 && j == 0) {
            printf("|T1| ");  // Torre 1 em A1
        } else if (linha == 0 && j == 7) {
            printf("|T2| ");  // Torre 2 em H1
        } else if (linha == 0 && j == 1) {
            printf("|C1| ");  // Cavalo 1 em B1
        } else if (linha == 0 && j == 6) {
            printf("|C2| ");  // Cavalo 2 em G1
        } else if ((linha + j) % 2 == 0) {
            printf("|  | ");  // Casa branca
        } else {
            printf("|XX| ");  // Casa preta
        }
    }
    printf("\n");
}

// Função para imprimir o tabuleiro completo
void imprimirTabuleiro() {
    imprimirIndicesColunas();
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        imprimirLinha(i);
    }
}

int main() {
    printf("Tabuleiro de Xadrez Virtual:\n\n");
    imprimirTabuleiro();
    
    return 0;
}