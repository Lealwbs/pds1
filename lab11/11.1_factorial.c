#include <stdio.h>

unsigned long long int factorial(int number){
    if(number <= 1) return 1;
    return number * factorial(number-1);
}

int main(){
    int input;
    while(scanf("%d", &input)){
        if(input < 0) return 0;
        printf("%d! = %llu\n", input, factorial(input));
    }
    return 0;
}