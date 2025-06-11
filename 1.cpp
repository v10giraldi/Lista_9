#include <stdio.h>
#include <stdlib.h>

#define LINHAS 3
#define COLUNAS 3

int **alocarMatriz(int linhas, int colunas) {
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    if (matriz == NULL) {
        printf("Erro de alocacao!\n");
        return NULL;
    }
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
        if (matriz[i] == NULL) {
            printf("Erro de alocacao!\n");
            return NULL;
        }
    }
    return matriz;
}

void liberarMatriz(int **matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void preencherMatriz(int **matriz, int dados[3][3]) {
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            matriz[i][j] = dados[i][j];
        }
    }
}

void somarMatrizes(int **A, int **B, int **resultado, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            resultado[i][j] = A[i][j] + B[i][j];
        }
    }
}

void imprimirMatriz(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int dadosA[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    int dadosB[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int **matriz1 = alocarMatriz(LINHAS, COLUNAS);
    int **matriz2 = alocarMatriz(LINHAS, COLUNAS);
    int **resultado = alocarMatriz(LINHAS, COLUNAS);

    preencherMatriz(matriz1, dadosA);
    preencherMatriz(matriz2, dadosB);

    printf("Matriz A:\n");
    imprimirMatriz(matriz1, LINHAS, COLUNAS);

    printf("\nMatriz B:\n");
    imprimirMatriz(matriz2, LINHAS, COLUNAS);

    somarMatrizes(matriz1, matriz2, resultado, LINHAS, COLUNAS);

    printf("\nSoma das Matrizes:\n");
    imprimirMatriz(resultado, LINHAS, COLUNAS);

    liberarMatriz(matriz1, LINHAS);
    liberarMatriz(matriz2, LINHAS);
    liberarMatriz(resultado, LINHAS);

    printf("\nMemoria liberada com sucesso.\n");

    return 0;
}
