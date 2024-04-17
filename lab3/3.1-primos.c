#include <stdio.h>

int main(){
    int a, b, i, j, divs;
    scanf("%d", &a);
    scanf("%d", &b);

    for(i=2; i<10000; i++){
        divs = 0;
        for(j=2; j<i; j++){
            if(i%j==0){
                divs++;
                break;
            };
        };
        if(divs==0 && i>=a && i<=b){
            printf("%d\n", i);
        };
    };
    return 0;
};