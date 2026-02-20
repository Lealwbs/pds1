#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(int n){
    if(n < 2) return false;
    for(int i=2; i<(int)sqrt(n) + 1; i++)
        if(n%i==0) return false;
    return true;
}

int sum_primes(int n){
    int sum = 0;
    int i = 2;
    while(n){
        if(is_prime(i)){
            sum += i;
            n--;
        }
        i++;
    }
    return sum;
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
        printf("%d\n", sum_primes(value));
    }
    return 0;
}