#include <stdio.h>

int main(){
    int a, b, c;
    scanf("%d\n%d\n%d", &a, &b, &c);
    if(a < b){
        a = b;
    }
    if(a < c){ 
        a = c;
    }
    printf("%d", a);
    return 0;
}