#include <stdio.h>
#include <stdlib.h>

// Alocação 1
// Vetor linear, tudo em um bloco

int* cria_matriz(int n_linhas, int n_colunas) {
    int* matriz = (int*)malloc(n_linhas * n_colunas * sizeof(int));
    return matriz;
}

void libera_matriz(int* matriz, int n_linhas, int n_colunas) {
    free(matriz);
}

void preenche_matriz(int* m, int n_linhas, int n_colunas) {
    for(int i = 0; i < n_linhas; i++) {
        for(int j = 0; j < n_colunas; j++) {
            printf("Digite o elemento a[%d][%d]: ", i, j);
            scanf("%d", &m[i * n_colunas + j]);
        }
    }
}

void imprime_matriz(int* m, int n_linhas, int n_colunas) {
    for(int i = 0; i < n_linhas; i++) {
        for(int j = 0; j < n_colunas; j++) {
            printf("%3d", m[i * n_colunas + j]);
        }
        printf("\n");
    }
}

// Alocação 2
// Vetor de ponteiros + vários blocos

int** cria_matriz(int n_linhas, int n_colunas) {
    int** matriz = (int**)malloc(n_linhas * sizeof(int*));

    for(int i = 0; i < n_linhas; i++) {
        matriz[i] = (int*)malloc(n_colunas * sizeof(int));
    }
    return matriz;
}

void libera_matriz(int** matriz, int n_linhas, int n_colunas) {
    for(int i = 0; i < n_linhas; i++) {
        free(matriz[i]);
    }
    free(matriz);
}

void preenche_matriz(int** m, int n_linhas, int n_colunas) {
    for(int i = 0; i < n_linhas; i++) {
        for(int j = 0; j < n_colunas; j++) {
            printf("Digite o elemento a[%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

void imprime_matriz(int** m, int n_linhas, int n_colunas) {
    for(int i = 0; i < n_linhas; i++) {
        for(int j = 0; j < n_colunas; j++) {
            printf("%3d", m[i][j]);
        }
        printf("\n");
    }
}

// Alocação 3
// Vetor de ponteiros + um único bloco contínuo

int** cria_matriz(int n_linhas, int n_colunas) {
    int** matriz = (int**)malloc(n_linhas * sizeof(int*));

    matriz[0] = (int*)malloc(n_linhas * n_colunas * sizeof(int));

    for(int i = 1; i < n_linhas; i++) {
        matriz[i] = matriz[0] + i * n_colunas;
    }

    return matriz;
}

void libera_matriz(int** matriz, int n_linhas, int n_colunas) {
    free(matriz[0]);
    free(matriz);
}

void preenche_matriz(int** m, int n_linhas, int n_colunas) {
    for(int i = 0; i < n_linhas; i++) {
        for(int j = 0; j < n_colunas; j++) {
            printf("Digite o elemento a[%d][%d]: ", i, j);
            scanf("%d", &m[i][j]);
        }
    }
}

void imprime_matriz(int** m, int n_linhas, int n_colunas) {
    for(int i = 0; i < n_linhas; i++) {
        for(int j = 0; j < n_colunas; j++) {
            printf("%3d", m[i][j]);
        }
        printf("\n");
    }
}

// MAIN

int main() {
    int l, c;
    printf("Digite o número de linhas e colunas: ");
    scanf("%d %d", &l, &c);

    int** m = cria_matriz(l, c);
    preenche_matriz(m, l, c);
    imprime_matriz(m, l, c);
    libera_matriz(m, l, c);
    return EXIT_SUCCESS;
}