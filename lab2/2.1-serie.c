#include <stdio.h>

int main(){
    int i, n, x0, x1, temp=0;
    scanf("%d %d %d", &n, &x0, &x1);
    printf("X0: %d\n", x0);
    
    for(i=0; i<n; i++){
        printf("X%d: %d\n", i+1,x1);
        temp = x1;
        x1 = 4*x1 - 2*x0;
        x0 = temp;
    }
    return 0;
}