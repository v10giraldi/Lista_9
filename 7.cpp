#include <stdio.h>
#include <stdlib.h>

void liberarMatriz(int **matriz, int linhas) {
    if (matriz == NULL) {
        return; // Nada a liberar se a matriz for NULL
    }
    //Liberar a memória de cada linha
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
    
}