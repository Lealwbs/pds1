#include <stdio.h>

int main(){
    int i, j, qlinhas, qcolunas, maior=0;

    scanf("%d", &qlinhas);
    scanf("%d", &qcolunas);
    int matriz[qlinhas][qcolunas];

    for(i=0; i<qlinhas; i++){
        for(j=0; j<qcolunas; j++){
            scanf("%d", &matriz[i][j]);
            if(matriz[i][j] > maior){
                maior = matriz[i][j];
            };
        };
    };

    printf("%d", maior);

    return 0;
}