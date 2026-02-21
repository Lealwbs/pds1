#include <stdio.h>

void media(double vet[], int n, int *i);

int main(){
    int size = 0, result = 0;
    scanf("%d", &size);
    double array[size];

    for(int i=0; i<size; i++){
        // scanf("%d", &array[i]);
        scanf("%lf", (array + i));
    }

    media(array, size, &result);
    printf("%d", result);
    return 0;
}

void media(double vet[], int n, int *i){
    int result = 0;
    for(int i=0; i<n; i++)
        result += vet[i];
    *i = result / n;
}
