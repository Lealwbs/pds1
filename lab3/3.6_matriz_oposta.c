#include <stdio.h>

int main(){
    int linhas, colunas;
    scanf("%d\n%d", &linhas, &colunas);
    int matriz[linhas][colunas];

    for(int l=0; l<linhas; l++)
        for(int c=0; c<colunas; c++)
            scanf("%d", &matriz[l][c]);

    for(int l=0; l<linhas; l++){
        for(int c=0; c<colunas; c++)
            printf("%d ", -matriz[l][c]);
        printf("\n");
    }
    
    return 0;
}