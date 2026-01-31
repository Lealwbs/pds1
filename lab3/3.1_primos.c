#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool is_prime(unsigned int number);

int main(){
    unsigned int start, end;
    scanf("%u\n%u", &start, &end);
    for(int i=start; i<=end; i++)
        if(is_prime(i))
            printf("%d\n", i);
    return 0;
}

bool is_prime(unsigned int number){
    if(number < 2) 
        return false;
    for(int i=2; i<=(int)sqrt(number); i++)
        if(number % i == 0) 
            return false;
    return true;
}