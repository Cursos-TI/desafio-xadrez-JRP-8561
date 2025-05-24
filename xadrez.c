#include <stdio.h>

#define TAMANHO_TABULEIRO 8
#define DIVISORIA "--------------------------------------"

// Recursividade para movimentação da Torre
void moverTorreRecursivo(int x, int y, int i) {
    if (i >= TAMANHO_TABULEIRO) return;

    printf("Direita: (%d, %d)\n", x, y + i);
    printf("Esquerda: (%d, %d)\n", x, y - i);
    printf("Baixo: (%d, %d)\n", x + i, y);
    printf("Cima: (%d, %d)\n", x - i, y);

    moverTorreRecursivo(x, y, i + 1);
}

// Recursividade otimizada para o Bispo
void moverBispoRecursivo(int x, int y, int i) {
    if (i >= TAMANHO_TABULEIRO) return;

    printf("Cima, Direita: (%d, %d)\n", x + i, y + i);
    printf("Baixo, Esquerda: (%d, %d)\n", x - i, y - i);
    printf("Cima, Esquerda: (%d, %d)\n", x + i, y - i);
    printf("Baixo, Direita: (%d, %d)\n", x - i, y + i);

    moverBispoRecursivo(x, y, i + 1);
}

// Recursividade para movimentação da Rainha
void moverRainhaRecursivo(int x, int y, int i) {
    if (i >= TAMANHO_TABULEIRO) return;

    moverTorreRecursivo(x, y, i);
    moverBispoRecursivo(x, y, i);
}

// Movimentação correta do Cavalo
void moverCavalo(int x, int y) {
    printf("%s\n", DIVISORIA);
    printf("Movimentos do Cavalo a partir de (%d, %d):\n", x, y);
    
    int movimentos[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
    
    for (int i = 0; i < 8; i++) {
        int novoX = x + movimentos[i][0];
        int novoY = y + movimentos[i][1];
        if (novoX >= 0 && novoX < TAMANHO_TABULEIRO && novoY >= 0 && novoY < TAMANHO_TABULEIRO) {
            printf("L em (%d, %d)\n", novoX, novoY);
        }
    }
}

int main() {
    int posX = 4, posY = 4;

    printf("%s\n", DIVISORIA);
    printf("Movimentos da Torre:\n");
    moverTorreRecursivo(posX, posY, 1);

    printf("%s\n", DIVISORIA);
    printf("Movimentos do Bispo:\n");
    moverBispoRecursivo(posX, posY, 1);

    printf("%s\n", DIVISORIA);
    printf("Movimentos da Rainha:\n");
    moverRainhaRecursivo(posX, posY, 1);

    moverCavalo(posX, posY);

    printf("%s\n", DIVISORIA);
    
    return 0;
}