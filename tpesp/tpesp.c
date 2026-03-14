#include <stdio.h>
#include <stdbool.h>

void uniao(const int* a, const int* b, const int size, int *vetor_uniao, int* u_size);

void interseccao(const int* a, const int* b, const int size, int* vetor_interseccao, int* i_size);

void print_vetor(const int* vetor, const int size);

bool is_in_vector(const int value, const int* vector, const int size);

int main(){
    int size, uniao_size, interseccao_size;
    scanf("%d", &size);

    int vetor_a[size], vetor_b[size], vetor_uniao[2*size], vetor_interseccao[size];
    for(int i=0; i<size; i++){ scanf("%d", &vetor_a[i]); }
    for(int i=0; i<size; i++){ scanf("%d", &vetor_b[i]); }

    uniao(vetor_a, vetor_b, size, vetor_uniao, &uniao_size);
    interseccao(vetor_a, vetor_b, size, vetor_interseccao, &interseccao_size);

    printf("UNIAO: ");
    print_vetor(vetor_uniao, uniao_size);
    printf("INTERSECCAO: ");
    print_vetor(vetor_interseccao, interseccao_size);

    return 0;
}

void uniao(const int* a, const int* b, const int size, int *vetor_uniao, int* u_size){
    *u_size = 0;
    for(int i=0; i<size; i++){
        if(!is_in_vector(a[i], vetor_uniao, *u_size)){
            vetor_uniao[*u_size] = a[i];
            (*u_size)++;
        }
    }
    for(int i=0; i<size; i++){
        if(!is_in_vector(b[i], vetor_uniao, *u_size)) vetor_uniao[(*u_size)++] = b[i];
    }
}

void interseccao(const int* a, const int* b, const int size, int* vetor_interseccao, int* i_size){
    *i_size = 0;
    for(int i=0; i<size; i++){
        if(is_in_vector(a[i], b, size) && !is_in_vector(a[i], vetor_interseccao, *i_size)) 
            vetor_interseccao[(*i_size)++] = a[i];
    }
}

void print_vetor(const int* vetor, const int size){
    for(int i=0; i<size; i++){
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

bool is_in_vector(const int value, const int* vetor, const int size){
    for(int i=0; i<size; i++){
        if(value == vetor[i]) return true;
    }
    return false;
}