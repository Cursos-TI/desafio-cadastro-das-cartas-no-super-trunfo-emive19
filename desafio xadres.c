#include <stdio.h>

// ------------------ FUNÇÕES RECURSIVAS ------------------

// Função recursiva para mover a Torre (para a Direita)
void moverTorre(int casasRestantes) {
    if (casasRestantes <= 0) return;
    printf("Direita\n");
    moverTorre(casasRestantes - 1);
}

// Função recursiva para mover a Rainha (para a Esquerda)
void moverRainha(int casasRestantes) {
    if (casasRestantes <= 0) return;
    printf("Esquerda\n");
    moverRainha(casasRestantes - 1);
}

// Função recursiva para iniciar movimento do Bispo com loops aninhados
void moverBispo(int linhas, int colunas) {
    if (linhas <= 0 || colunas <= 0) return;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Cima Direita\n");
        }
    }

    // Reduzimos o movimento e chamamos novamente (simula novas diagonais)
    moverBispo(linhas - 1, colunas - 1);
}

// ------------------ CAVALO COM LOOPS COMPLEXOS ------------------

void moverCavalo() {
    // O Cavalo move em "L": 2 para cima, 1 para a direita
    // Simular uma vez com loops complexos

    printf("Movimento do Cavalo:\n");

    for (int i = 2; i >= 1; i--) {  // i controla o número de passos verticais (para cima)
        for (int j = 1; j <= 1; j++) {  // j controla o passo horizontal (direita)
            if (i == 2) {
                printf("Cima\n");
                continue;  // volta para próxima iteração para imprimir o segundo "Cima"
            }
            if (i == 1) {
                printf("Cima\n");
                printf("Direita\n");
                break;  // termina o loop após o movimento em L
            }
        }
    }
}

// ------------------ MAIN ------------------

int main() {
    // Movimento da Torre: 5 casas para Direita
    printf("Movimento da Torre:\n");
    moverTorre(5);

    // Movimento do Bispo: 3 linhas e 3 colunas (simula várias diagonais)
    printf("\nMovimento do Bispo:\n");
    moverBispo(3, 3);

    // Movimento da Rainha: 8 casas para Esquerda
    printf("\nMovimento da Rainha:\n");
    moverRainha(8);

    // Movimento do Cavalo: 2 para cima e 1 para direita (em "L")
    printf("\n");
    moverCavalo();

    return 0;
}
