#include <stdio.h>

int main(){
    int value = 233, max = 457;
    do{
        printf("%d\n", value);
        value += 5 - 2*(300 < value && value < 400);
    } while ( value <= max );
    return 0;
}