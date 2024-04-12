#include <stdio.h>

int main(){
    int num1, num2, num3, maior;
    scanf("%d %d %d", &num1, &num2, &num3);

    if(num1>num2){
        maior=num1;}
    else{
        maior=num2;};

    if(num3>maior){
        maior=num3;};

    printf("%d", maior);
    return 0;
}