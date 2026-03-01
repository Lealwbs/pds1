#include <stdio.h>
#include <stdlib.h>

int main(){

    int row, col;
    scanf("%d %d", &row, &col);

    int** matrix = (int**) malloc(row * sizeof(int));
    for(int i=0; i<row; i++){
        matrix[i] = (int*) malloc(col * sizeof(int));
        for(int j=0; j<col; j++){
            scanf("%d", &matrix[i][j]);
        }
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i<row; i++)
        free(matrix[i]);
    free(matrix);

    return 0;
}