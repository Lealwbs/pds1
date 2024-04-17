#include <stdio.h>

int main(){
    int i, num=1, fib[801];
    fib[0] = 0;
    fib[1] = 1;

    for(i=2; i<800; i++){
        fib[i] = fib[i-1] + fib[i-2];
    };

    do {
        scanf("%d", &num);
        if(num>=0 && num<=800){
            printf("%d\n", fib[num]);
        };
    }
    while(num>=0 && num<=800);
    
    return 0;
}