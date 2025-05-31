#include <stdio.h>
#include <string.h>

#define TAMANHO_TABULEIRO 8
#define MOV_BISPO 5
#define MOV_TORRE 5
#define MOV_RAINHA 8

char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO][4];

// Estrutura para definir a posição das peças
typedef struct {
    char nome[4];
    int linha;
    int coluna;
} Peca;

// Lista de peças e suas posições iniciais
Peca pecas[] = {
    {"T1", 7, 0}, {"C1", 7, 1}, {"B1", 7, 2}, {"RE", 7, 3},
    {"RA", 7, 4}, {"B2", 7, 5}, {"C2", 7, 6}, {"T2", 7, 7}
};

// Função para inicializar o tabuleiro
void inicializarTabuleiro() {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            strcpy(tabuleiro[i][j], ((i + j) % 2 == 0) ? "  " : "--");
        }
    }
}

// Função para posicionar as peças
void posicionarPecas() {
    for (int i = 0; i < sizeof(pecas) / sizeof(pecas[0]); i++) {
        strcpy(tabuleiro[pecas[i].linha][pecas[i].coluna], pecas[i].nome);
    }
}

// Função para imprimir o tabuleiro
void imprimirTabuleiro() {
    printf("     ");
    for (char letra = 'A'; letra < 'A' + TAMANHO_TABULEIRO; letra++) {
        printf(" %c  ", letra);
    }
    printf("\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%2d   ", i + 1);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("|%s|", tabuleiro[i][j]);  
        }
        printf("\n");
    }
}

// Função recursiva para mover Bispo
void moverBispoRec(int *linha, int *coluna, int movimentos) {
    if (movimentos == 0 || *linha <= 0 || *coluna >= TAMANHO_TABULEIRO - 1) return;
    (*linha)--;
    (*coluna)++;
    moverBispoRec(linha, coluna, movimentos - 1);
}

// Função para mover Cavalo com loops aninhados
void moverCavalo(int *linha, int *coluna) {
    for (int i = 0; i < 2; i++) { 
        if (*linha + 2 < TAMANHO_TABULEIRO) *linha += 2;
        while (*coluna - 1 >= 0) *coluna -= 1;
    }
}

// Função para reposicionar peça
void reposicionarPeca(int indice) {
    int novaLinha = pecas[indice].linha;
    int novaColuna = pecas[indice].coluna;

    if (strcmp(pecas[indice].nome, "B1") == 0 || strcmp(pecas[indice].nome, "B2") == 0) {
        moverBispoRec(&novaLinha, &novaColuna, MOV_BISPO);
    } else if (strcmp(pecas[indice].nome, "T1") == 0 || strcmp(pecas[indice].nome, "T2") == 0) {
        if (novaColuna + MOV_TORRE < TAMANHO_TABULEIRO) novaColuna += MOV_TORRE;
    } else if (strcmp(pecas[indice].nome, "RA") == 0) {
        if (novaColuna - MOV_RAINHA >= 0) novaColuna -= MOV_RAINHA;
    } else if (strcmp(pecas[indice].nome, "C1") == 0 || strcmp(pecas[indice].nome, "C2") == 0) {
        moverCavalo(&novaLinha, &novaColuna);
    } else {
        printf("\nEssa peça não pode ser movida automaticamente!\n");
        return;
    }

    strcpy(tabuleiro[pecas[indice].linha][pecas[indice].coluna], ((pecas[indice].linha + pecas[indice].coluna) % 2 == 0) ? "  " : "--");
    pecas[indice].linha = novaLinha;
    pecas[indice].coluna = novaColuna;
    strcpy(tabuleiro[pecas[indice].linha][pecas[indice].coluna], pecas[indice].nome);

    imprimirTabuleiro();
}

int main() {
    char pecaEscolhida[4];
    char continuar = 'Y';

    inicializarTabuleiro();
    posicionarPecas();

    printf("\nTabuleiro de Xadrez Virtual:\n\n");
    imprimirTabuleiro();

    while (continuar == 'Y' || continuar == 'y') {
        printf("\nQual peça você deseja mover? (Exemplo: B1, T2, RA, C1): ");
        scanf("%s", pecaEscolhida);

        int indicePeca = -1;
        for (int i = 0; i < sizeof(pecas) / sizeof(pecas[0]); i++) {
            if (strcmp(pecas[i].nome, pecaEscolhida) == 0) {
                indicePeca = i;
                break;
            }
        }

        if (indicePeca != -1) {
            reposicionarPeca(indicePeca);
        } else {
            printf("\nPeça inválida! Escolha uma peça existente.\n");
        }

        printf("\nDeseja mover outra peça? (Y/N): ");
        scanf(" %c", &continuar);
    }

    printf("\nObrigado por jogar! Até a próxima.\n");
    return 0;
}