#include <stdio.h>

int main(){
    unsigned long long fibs[81] = {0, 1};
    int number, count = 2;
    while(scanf("%d", &number)){
        if(number < 0 || number > 80)
            return 0;
        while(number >= count){
            fibs[count] = fibs[count-1] + fibs[count-2];
            count++;
        }
        printf("The #%d fib number is: %I64u\n", number, fibs[number]);
    }
    return 0;
}