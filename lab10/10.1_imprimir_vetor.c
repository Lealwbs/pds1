#include <stdio.h>
#include <stdlib.h>

void preencher_vetor(int* v, int size);

void imprimir_vetor(int* v, int size);

int main(){
    int tamanho;
    scanf("%d", &tamanho);

    int* vetor = (int*) malloc(tamanho * sizeof(int));

    preencher_vetor(vetor, tamanho);
    imprimir_vetor(vetor, tamanho);

    free(vetor);
    return 0;
}

void preencher_vetor(int* v, int size){
    for(int i=0; i<size; i++)
        scanf("%d", v++); // ou &(v[i])
}

void imprimir_vetor(int* v, int size){
    for(int i=0; i<size; i++)
        printf("%d\n", *v++); // ou (v[i])
}