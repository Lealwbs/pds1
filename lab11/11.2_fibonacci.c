#include <stdio.h>

int fibonacci(int position){
    if(position <= 1) return 1;
    return fibonacci(position-1) + fibonacci(position-2);
}

int main(){
    int input;
    while(scanf("%d", &input)){
        if(input < 0) return 0;
        printf("%dº fib: %d\n", input, fibonacci(input));
    }
    return 0;
}