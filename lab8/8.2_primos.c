#include <stdio.h>
#include <stdbool.h>
#include <math.h>

void primos(int m, int *p1, int *p2);

bool eh_primo(int n);

int main(){
    int input, num1, num2;
    scanf("%d", &input);
    primos(input, &num1, &num2);
    printf("%d\n%d", num1, num2);
}

void primos(int m, int *p1, int *p2){
    if(m<=2){
        *p1 = -1;
        *p2 = -1;
        return;
    }

    int i=2, now=2, prev=2, prevev=2;
    while(i++){
        if(eh_primo(i)){
            prevev = prev;
            prev = now;
            now = i;
            if(i>m) 
                break;
        }
    }
    *p1 = eh_primo(m) ? prevev : prev;
    *p2 = now;
}

bool eh_primo(int n){
    for(int i=2; i<(sqrt(n)+1); i++)
        if(n%i == 0)
            return false;
    return true;
}