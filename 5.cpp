#include <stdio.h>
#include <stdlib.h>

int **alocarMatriz(int linhas, int colunas) {
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int *)malloc(colunas * sizeof(int));
    }
    return matriz;
}

void liberarMatriz(int **matriz, int linhas) {
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void imprimirMatriz(int **matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }
}

void multiplicarMatrizes(int **matrizA, int **matrizB, int **matrizResultado, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            int soma = 0;
            for (int k = 0; k < colunas; k++) {
                soma += matrizA[i][k] * matrizB[k][j];
            }
            matrizResultado[i][j] = soma;
        }
    }
}

int main() {
    int **A = alocarMatriz(3, 3);
    int **B = alocarMatriz(3, 3);
    int **matrizResultado = alocarMatriz(3, 3);

    int valorA[3][3] = {
        {3, 2, 3},
        {4, 5, 1},
        {5, 1, 4}
    };
    int valorB[3][3] = {
        {1, 2, 4},
        {3, 1, 1},
        {2, 2, 3}
    };

    // Preencher matrizes A e B
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            A[i][j] = valorA[i][j];
            B[i][j] = valorB[i][j];
        }
    }

    multiplicarMatrizes(A, B, matrizResultado, 3, 3);

    printf("Resultado da multiplicação A x B:\n");
    imprimirMatriz(matrizResultado, 3, 3);

    liberarMatriz(A, 3);
    liberarMatriz(B, 3);
    liberarMatriz(matrizResultado, 3);

    printf("\nMemória das matrizes liberada com sucesso.\n");
    return 0;
}
