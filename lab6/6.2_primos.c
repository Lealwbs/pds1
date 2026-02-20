#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(int n){
    if(n < 2) return false;
    for(int i=2; i<(int)sqrt(n) + 1; i++)
        if(n%i==0) return false;
    return true;
}

int main(void){
    int value = 0;
    while(puts("Digite um numero: "), scanf("%d", &value)){
        if(value == -1) break;
        if(value < 2){
            printf("-1\n");
            value = -1;
            continue;
        } 
        printf("%d\n", is_prime(value));
    }
    return 0;
}