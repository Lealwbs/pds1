#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int my_pow(int x, int y);

int soma_quadrados(int n);

bool palindromo(char* str);

int main(){
    if(false)
        for(int i=1; i<=5; i++)
            for(int j=0; j<=4; j++)
                printf("%d^%d = %d\n", i, j, my_pow(i, j));

    if(false)
        for(int i=1; i<=10; i++)
            printf("n=%d: %d\n", i, soma_quadrados(i));

    if(false){
        printf("casa_asac: %d\n", palindromo("casa_asac")? 1 : 0);
        printf("arroz: %d\n", palindromo("arroz")? 1 : 0);
        printf("arara: %d\n", palindromo("arara")? 1 : 0);
    }
    
    return 0;
}

int my_pow(int x, int y){
    if(y == 0) return 1;
    if(y == 1) return x;
    if(y == 2) return x*x;
    if(y & 0b1) return x * my_pow(x*x, (y-1)/2);
    return my_pow(x*x, y/2);
}

int soma_quadrados(int n){
    int sum = 0;
    for(int i=1; i<=n; i++)
        sum += my_pow(i, 2);
    return sum;
}

bool palindromo(char* str){
    int size = strlen(str);
    for(int i=0; i<size; i++)
        if(str[i] != str[size-1-i])
            return false;
    return true;
}