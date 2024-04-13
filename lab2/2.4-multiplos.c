#include <stdio.h>

int main(){
    int i=1, x, m2=0, m3=0, m5=0, m30=0;
    scanf("%d", &x);

    while(i<=x){

        if (i%2==0)
        {m2++;};
        
        if (i%3==0)
        {m3++;};

        if (i%5==0)
        {m5++;};
        
        if (i%30==0)
        {m30++;};

        i++;
    }; 
    printf("Múltiplos de 2: %d\n Múltiplos de 3: %d\n Múltiplos de 5: %d\n Múltiplos de todos: %d\n", m2, m3, m5, m30);
    return 0;
}