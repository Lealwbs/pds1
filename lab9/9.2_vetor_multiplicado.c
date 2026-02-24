#include <stdio.h>

void imprime(int vetor[], int n);
void multiplica(int vetor[], int n, double v);

int main(){
    int tam_vetor;
    scanf("%d", &tam_vetor);
    
    int vetor[tam_vetor];
    for(int i=0; i<tam_vetor; i++){
        scanf("%d", &vetor[i]);
    }

    double valor_multp;
    scanf("%lf", &valor_multp);

    imprime(vetor, tam_vetor);
    multiplica(vetor, tam_vetor, valor_multp);
    imprime(vetor, tam_vetor);
    multiplica(vetor, tam_vetor, 1/valor_multp);
    imprime(vetor, tam_vetor);
}

void imprime(int vetor[], int n){
    for(int i=0; i<n; i++)
        printf("%d ", vetor[i]);
    printf("\n");
}

void multiplica(int vetor[], int n, double v){
    for(int i=0; i<n; i++)
        vetor[i] *= v;
}