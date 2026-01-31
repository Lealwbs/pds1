#include <stdio.h>

int main(){
    int linhas, colunas, value, max_value = -1;

    scanf("%d\n%d", &linhas, &colunas);
    for(int l=0; l<linhas; l++)
        for(int c=0; c<colunas; c++){
            scanf("%d", &value);
            max_value = value > max_value ? value : max_value;
        }

    printf("%d", max_value);
    return 0;
}