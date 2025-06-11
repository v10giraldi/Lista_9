#include <stdio.h>
#include <stdlib.h>

int **alocarMatriz(int linhas, int colunas){
    int **matriz = NULL;
    matriz = (int**)malloc(linhas * sizeof(int*));
    if (matriz == NULL){
            printf("Erro de alocação!");
            return NULL;
        }
        
    for (int i = 0;i < linhas;i++) {
        matriz[i] = (int*)malloc(colunas*sizeof(int));
        if(matriz[i]==NULL){
            printf("Erro de alocação!");
            return NULL;
        }}
    return matriz;
}

int main(){
    int size = 5;
    int **matriz = alocarMatriz(size,size);

    for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) 
    matriz[i][j] = i+j;
    }

    for(int i = 0;i < size; i++){
        for(int j = 0;j < size;j++){
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
}