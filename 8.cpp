#include <stdio.h>
#include <stdlib.h>
#define COLUNAS 3

void preencherMatrizComValores(int **matrizDestino, const int (*matrizOrigem)[COLUNAS],int linhas, int colunas) {
    //Apenas matrizes 3x3
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            matrizDestino[i][j] = matrizOrigem[i][j];
        }
    }
}