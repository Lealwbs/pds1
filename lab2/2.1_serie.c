#include <stdio.h>

int main(){
    int n, x0, x1, tmp;
    scanf("%d\n%d\n%d", &n, &x0, &x1);
    printf("X0: %d\n", x0);
    for(int i=1; i<=n; i++){
        printf("X%d: %d\n", i, x1);
        tmp = 4*x1 - 2*x0;
        x0 = x1;
        x1 = tmp;
    }
    return 0;
}