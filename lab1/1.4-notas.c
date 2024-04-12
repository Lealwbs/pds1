#include <stdio.h>

int main(){
    int valor, n100=0, n50=0, n20=0, n10=0, n5=0, n2=0, n1=0;
    scanf("%d", &valor);

    while(valor>=100){
        valor-=100;
        n100++;};

    while(valor>=50){
        valor-=50;
        n50++;};

    while(valor>=20){
        valor-=20;
        n20++;};

    while(valor>=10){
        valor-=10;
        n10++;};

    while(valor>=5){
        valor-=5;
        n5++;};

    while(valor>=2){
        valor-=2;
        n2++;};

    while(valor>=1){
        valor-=1;
        n1++;};

    printf("100: %d \n50: %d \n20: %d \n10: %d \n5: %d \n2: %d \n1: %d", n100, n50, n20, n10, n5, n2, n1);
    return 0;
}