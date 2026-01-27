#include <stdio.h>

int main(){
    int a, b, c;
    scanf("%d\n%d\n%d", &a, &b, &c);
    if( (a%b==0) && (a%c==0) ){
        printf("O numero eh divisivel");
    } else {
        printf("O numero nao eh divisivel");
    }
    return 0;
}