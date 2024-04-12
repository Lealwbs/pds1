#include <stdio.h>

int main(){
    int num1, num2, num3;
    scanf("%d %d %d", &num1, &num2, &num3);

    if(num1%num2==0 && num1%num3==0){
        printf("O número é divisível");
    }
    else{
        printf("O número não é divisível");
    };
    return 0;
}