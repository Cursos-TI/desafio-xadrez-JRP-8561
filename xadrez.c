#include <stdio.h>

#define TAMANHO_TABULEIRO 8

// Função para imprimir os índices das colunas
void imprimirIndicesColunas() {
    printf("     ");
    for (char letra = 'A'; letra < 'A' + TAMANHO_TABULEIRO; letra++) {
        printf(" %c   ", letra);
    }
    printf("\n");
}

// Função para imprimir uma linha do tabuleiro, com ou sem peças
void imprimirLinha(int linha, int mostrarPecas) {
    printf("%2d   ", linha + 1);
    for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
        if (mostrarPecas) {
            // Adicionando peças nas posições corretas
            if (linha == 0 && j == 2) {
                printf("|B1| ");  // Bispo 1 em C1
            } else if (linha == 0 && j == 5) {
                printf("|B2| ");  // Bispo 2 em F1
            } else if (linha == 0 && j == 4) {
                printf("|RA| ");  // Rainha em E1
            } else if (linha == 0 && j == 3) {
                printf("|RE| ");  // Rei em D1
            } else if (linha == 0 && j == 0) {
                printf("|T1| ");  // Torre 1 em A1
            } else if (linha == 0 && j == 7) {
                printf("|T2| ");  // Torre 2 em H1
            } else if (linha == 0 && j == 1) {
                printf("|C1| ");  // Cavalo 1 em B1
            } else if (linha == 0 && j == 6) {
                printf("|C2| ");  // Cavalo 2 em G1
            } else if ((linha + j) % 2 == 0) {
                printf("|  | ");
            } else {
                printf("|XX| ");
            }
        } else {
            // Tabuleiro vazio (apenas casas brancas e pretas)
            if ((linha + j) % 2 == 0) {
                printf("|  | ");
            } else {
                printf("|XX| ");
            }
        }
    }
    printf("\n");
}

// Função para imprimir o tabuleiro completo
void imprimirTabuleiro(int mostrarPecas) {
    imprimirIndicesColunas();
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        imprimirLinha(i, mostrarPecas);
    }
}

int main() {
    char resposta, peca[3];

    // Explicação das peças usadas no jogo
    printf("Neste tabuleiro de xadrez virtual, usaremos apenas as seguintes peças:\n");
    printf("- Torre (T1, T2): Move-se em linhas retas horizontal ou verticalmente.\n");
    printf("- Cavalo (C1, C2): Move-se em formato de 'L', pulando sobre outras peças.\n");
    printf("- Bispo (B1, B2): Move-se diagonalmente.\n");
    printf("- Rainha (RA): Pode se mover em qualquer direção, horizontal, vertical ou diagonal.\n");
    printf("- Rei (RE): Move-se uma casa em qualquer direção.\n");
    
    printf("\nTabuleiro de Xadrez Virtual - Vazio:\n\n");
    imprimirTabuleiro(0); // Exibe o tabuleiro vazio

    // Pergunta ao usuário se deseja jogar
    printf("\nVocê quer jogar xadrez? (Y/N): ");
    scanf(" %c", &resposta);

    // Verifica a resposta do usuário
    if (resposta == 'Y' || resposta == 'y') {
        printf("\nTabuleiro de Xadrez Virtual - Com Peças:\n\n");
        imprimirTabuleiro(1); // Exibe o tabuleiro com peças posicionadas

        // Pergunta ao usuário qual peça deseja mover
        printf("\nQual peça você deseja mover? (Exemplo: B1, RE, T2): ");
        scanf("%s", peca);

        // Exibe a escolha do usuário
        printf("\nVocê escolheu mover a peça: %s\n", peca);
    } else {
        printf("\nAh, que pena!\n");
    }

    return 0;
}