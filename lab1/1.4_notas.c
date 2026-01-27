#include <stdio.h>

void print_amount(int* name, int* amount, int size){
    for(int i=0; i<size; i++){
        printf("%d: %d\n", name[i], amount[i]);
    }
}

int main(){
    int notas[] = {100, 50, 20, 10, 5, 2, 1};
    int quantidades[] = {0, 0, 0, 0, 0, 0, 0};
    int valor, posicao = 0;

    scanf("%d", &valor);
    while(valor){
        if(valor < notas[posicao]){
            posicao += 1;
            continue;
        }
        valor -= notas[posicao];
        quantidades[posicao] += 1;
    }
    
    print_amount(notas, quantidades, 7);
    return 0;
}