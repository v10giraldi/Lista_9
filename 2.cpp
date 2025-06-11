#include <stdio.h>
#include <stdlib.h>

// Funções utilitárias
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

// Função para transpor
void transpostaMatriz(int **matrizA, int **matrizResultado, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matrizResultado[j][i] = matrizA[i][j];
        }
    }
}

int main() {
    int **matriz1 = alocarMatriz(3, 3);

    int valoresIniciais[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matriz1[i][j] = valoresIniciais[i][j];
        }
    }

    printf("Matriz Original:\n");
    imprimirMatriz(matriz1, 3, 3);

    int **matrizTransposta = alocarMatriz(3, 3);
    transpostaMatriz(matriz1, matrizTransposta, 3, 3);

    printf("\nMatriz Transposta:\n");
    imprimirMatriz(matrizTransposta, 3, 3);

    liberarMatriz(matrizTransposta, 3);
    liberarMatriz(matriz1, 3);

    printf("\nMemória das matrizes liberada com sucesso.\n");

    return 0;
}