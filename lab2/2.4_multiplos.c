#include <stdio.h>

int main(){
    int number;
    scanf("%d", &number);
    printf("Multiplos de 2: %d\n", (int)(number/2));
    printf("Multiplos de 3: %d\n", (int)(number/3));
    printf("Multiplos de 5: %d\n", (int)(number/5));
    printf("Multiplos de todos: %d\n", (int)(number/30));
    return 0;
}