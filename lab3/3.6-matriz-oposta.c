#include <stdio.h>

int main(){
    int i, j, temp, linhas, colunas;
    scanf("%d", &linhas);
    scanf("%d", &colunas);
    int matriz[linhas][colunas];

    for(i=0; i<linhas; i++){
        for(j=0; j<linhas; j++){
            scanf("%d", &temp);
            matriz[i][j] = -1 * temp;
        };
    };

    for(i=0; i<linhas; i++){
        for(j=0; j<linhas; j++){
            printf("%d ", matriz[i][j]);
        };
        printf("\n");
    };

    return 0;
}