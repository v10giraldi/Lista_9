#include <stdio.h>
#include <stdlib.h>

// --- Funções dos Exercícios 6, 7, 8 e 9 ---

// Exercício 6: Alocar Matriz
int** alocarMatriz(int linhas, int colunas) {
    int** matriz = (int**)malloc(linhas * sizeof(int*));
    if (matriz == NULL) return NULL;

    for (int i = 0; i < linhas; i++) {
        matriz[i] = (int*)malloc(colunas * sizeof(int));
        if (matriz[i] == NULL) {
            for (int k = 0; k < i; k++) free(matriz[k]);
            free(matriz);
            return NULL;
        }
    }
    return matriz;
}

// Exercício 7: Liberar Matriz
void liberarMatriz(int** matriz, int linhas) {
    if (matriz == NULL) return;
    for (int i = 0; i < linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

// Exercício 8: Preencher Matriz pelo Usuário
void preencherMatriz(int** matriz, int linhas, int colunas) {
    printf("Digite os valores do vetor (%dx%d):\n", linhas, colunas);
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

// Exercício 9: Imprimir Matriz
void imprimirMatriz(int** matriz, int linhas, int colunas) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

// Exercício 10: Programa Principal com PRODUTO VETORIAL
int main() {
    int **vetorA = NULL;
    int **vetorB = NULL;
    int **vetorResultado = NULL;
    
    // O produto vetorial só é possível entre vetores 3D (matrizes 1x3)
    int linhas = 1;
    int colunas = 3;

    printf("--- Calculadora de Produto Vetorial (A x B) ---\n");
    printf("O programa ira solicitar dois vetores de 3 dimensoes (matrizes 1x3).\n\n");

    // Alocar os vetores
    vetorA = alocarMatriz(linhas, colunas);
    vetorB = alocarMatriz(linhas, colunas);
    vetorResultado = alocarMatriz(linhas, colunas);

    if (vetorA == NULL || vetorB == NULL || vetorResultado == NULL) {
        printf("Erro fatal de alocacao de memoria!\n");
        liberarMatriz(vetorA, linhas);
        liberarMatriz(vetorB, linhas);
        liberarMatriz(vetorResultado, linhas);
        return 1;
    }

    // Preencher os vetores com dados do usuário
    printf("\n--- Preenchendo o Vetor A ---\n");
    preencherMatriz(vetorA, linhas, colunas);
    
    printf("\n--- Preenchendo o Vetor B ---\n");
    preencherMatriz(vetorB, linhas, colunas);

    // Imprimir os vetores de entrada
    printf("\nVetor A inserido:\n");
    imprimirMatriz(vetorA, linhas, colunas);
    printf("\nVetor B inserido:\n");
    imprimirMatriz(vetorB, linhas, colunas);

    // --- Cálculo do Produto Vetorial ---
    // Se A = [ax, ay, az] e B = [bx, by, bz], então C = A x B é:
    // cx = (ay * bz) - (az * by)
    // cy = (az * bx) - (ax * bz)
    // cz = (ax * by) - (ay * bx)

    vetorResultado[0][0] = (vetorA[0][1] * vetorB[0][2]) - (vetorA[0][2] * vetorB[0][1]);
    vetorResultado[0][1] = (vetorA[0][2] * vetorB[0][0]) - (vetorA[0][0] * vetorB[0][2]);
    vetorResultado[0][2] = (vetorA[0][0] * vetorB[0][1]) - (vetorA[0][1] * vetorB[0][0]);

    // Imprimir o resultado
    printf("\n--- Resultado do Produto Vetorial ---\n");
    imprimirMatriz(vetorResultado, linhas, colunas);

    // Liberar toda a memória
    liberarMatriz(vetorA, linhas);
    liberarMatriz(vetorB, linhas);
    liberarMatriz(vetorResultado, linhas);
    printf("\nMemoria liberada com sucesso!\n");

    return 0;
}