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

int main() {
    int **matriz1 = alocarMatriz(3, 3);

    int valoresIniciais[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Preencher matriz1
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matriz1[i][j] = valoresIniciais[i][j];
        }
    }

    // Soma da diagonal principal
    int somaDiagonal = 0;
    for (int i = 0; i < 3; i++) {
        somaDiagonal += matriz1[i][i]; // direto, já que i == j
    }

    printf("A soma da diagonal principal: %d\n", somaDiagonal);

    liberarMatriz(matriz1, 3);
    printf("\nMemoria da matriz liberada com sucesso.\n");

    return 0;
}
