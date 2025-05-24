#include <stdio.h>
#include <string.h>

#define TAMANHO_TABULEIRO 8
#define MOV_BISPO 5
#define MOV_TORRE 5
#define MOV_RAINHA 8

char tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO][4];

// Estrutura para definir a posição inicial das peças
typedef struct {
    char nome[4];
    int linha;
    int coluna;
} Peca;

// Lista de peças e suas posições iniciais na linha 8
Peca pecas[] = {
    {"T1", 7, 0}, {"C1", 7, 1}, {"B1", 7, 2}, {"RE", 7, 3},
    {"RA", 7, 4}, {"B2", 7, 5}, {"C2", 7, 6}, {"T2", 7, 7}
};

// Função para inicializar o tabuleiro com casas brancas e pretas corretamente
void inicializarTabuleiro() {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            if ((i + j) % 2 == 0) {
                strcpy(tabuleiro[i][j], "  ");  // Casa branca
            } else {
                strcpy(tabuleiro[i][j], "--"); // Casa preta
            }
        }
    }
}

// Função para posicionar as peças no tabuleiro
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

// Função para reposicionar uma peça automaticamente
void reposicionarPeca(int indice) {
    int novaLinha = pecas[indice].linha;
    int novaColuna = pecas[indice].coluna;

    if (strcmp(pecas[indice].nome, "B1") == 0 || strcmp(pecas[indice].nome, "B2") == 0) {
        // Bispo: Move-se 5 casas na diagonal superior direita
        if (novaLinha - MOV_BISPO >= 0 && novaColuna + MOV_BISPO < TAMANHO_TABULEIRO) {
            novaLinha -= MOV_BISPO;
            novaColuna += MOV_BISPO;
        }
    } else if (strcmp(pecas[indice].nome, "T1") == 0 || strcmp(pecas[indice].nome, "T2") == 0) {
        // Torre: Move-se 5 casas para a direita
        if (novaColuna + MOV_TORRE < TAMANHO_TABULEIRO) {
            novaColuna += MOV_TORRE;
        }
    } else if (strcmp(pecas[indice].nome, "RA") == 0) {
        // Rainha: Move-se 8 casas para a esquerda
        if (novaColuna - MOV_RAINHA >= 0) {
            novaColuna -= MOV_RAINHA;
        }
    } else {
        printf("\nEssa peça não pode ser movida automaticamente!\n");
        return;
    }

    // Limpa posição antiga e preserva cor original da casa
    strcpy(tabuleiro[pecas[indice].linha][pecas[indice].coluna], ((pecas[indice].linha + pecas[indice].coluna) % 2 == 0) ? "  " : "--");

    // Atualiza a nova posição da peça
    pecas[indice].linha = novaLinha;
    pecas[indice].coluna = novaColuna;
    strcpy(tabuleiro[pecas[indice].linha][pecas[indice].coluna], pecas[indice].nome);

    // Exibir tabuleiro atualizado
    imprimirTabuleiro();
}

int main() {
    char pecaEscolhida[4];
    char continuar = 'Y';

    // Inicializando tabuleiro e posicionando as peças
    inicializarTabuleiro();
    posicionarPecas();

    // Exibir tabuleiro inicial
    printf("\nTabuleiro de Xadrez Virtual - Todas as Peças na Linha 8:\n\n");
    imprimirTabuleiro();

    // Loop contínuo para movimentação de múltiplas peças
    while (continuar == 'Y' || continuar == 'y') {
        printf("\nQual peça você deseja mover? (Exemplo: B1, T2, RA): ");
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

        // Pergunta ao usuário se deseja mover outra peça
        printf("\nDeseja mover outra peça? (Y/N): ");
        scanf(" %c", &continuar);
    }

    printf("\nObrigado por jogar! Até a próxima.\n");
    return 0;
}