#include <stdio.h>

int _sum(int number){
    return (number * (number+1)) / 2;
}

int main(){
    int number, sum = 0;
    scanf("%d", &number);
    for(int i=0; i<=number; i++){
        sum += i;
    }
    printf("%d\n", sum);
    printf("%d\n", _sum(number));
    return 0;
}