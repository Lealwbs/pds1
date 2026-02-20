#include <stdio.h>
#include <stdbool.h>

bool is_bissexto(int year);

int main(void){
    int input = 0;
    while(scanf("%d", &input)){
        if(input < 0) break;
        printf("%d\n", is_bissexto(input));
    }
    return 0;
}

bool is_bissexto(int year){
    return (year%4 == 0 && (year%100 != 0 || year%400 == 0));
}