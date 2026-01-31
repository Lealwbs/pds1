#include <stdio.h>

int main(){
    int input[10];
    for(int i=0; i<10; i++)
        scanf("%d", &input[i]);
    for(int i=9; i>=0; i--)
        printf("%d\n", input[i]);
    return 0;
}