#include <stdio.h>
#include <stdlib.h>

void preencher_vetor(int* v, int size);

void somar_vetores(int* v, int* w, int* result, int size);

void imprimir_vetor(int* v, int size);

int main(){
    int tamanho;
    scanf("%d", &tamanho);

    int* vetor_a = (int*) malloc(tamanho * sizeof(int));
    int* vetor_b = (int*) malloc(tamanho * sizeof(int));
    int* vetor_c = (int*) malloc(tamanho * sizeof(int));

    preencher_vetor(vetor_a, tamanho);
    preencher_vetor(vetor_b, tamanho);
    somar_vetores(vetor_a, vetor_b, vetor_c, tamanho);
    imprimir_vetor(vetor_c, tamanho);
    
    free(vetor_a);
    free(vetor_b);
    free(vetor_c);
    return 0;
}

void preencher_vetor(int* v, int size){
    for(int i=0; i<size; i++)
        scanf("%d", &v[i]);
}

void somar_vetores(int* v, int* w, int* result, int size){
    for(int i=0; i<size; i++)
        result[i] = v[i] + w[i];
}

void imprimir_vetor(int* v, int size){
    for(int i=0; i<size; i++)
        printf("%d ", v[i]);
}