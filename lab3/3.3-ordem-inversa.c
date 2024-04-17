#include <stdio.h>

int main(){
    int i, vetor[10];

    for(i=0; i<10; i++){
        scanf("%d", &vetor[i]);
    };

    for(i=9; i>=0; i--){
        printf("%d\n", vetor[i]);
    };

    return 0;
}