#include <stdio.h>
#include <math.h>

int main(){
    int i;
    double  x_dif;
    double valor_pi = 4;
    double queb = 0;

    scanf("%lf", &x_dif);

    for(i=1; fabs(valor_pi - M_PI) > x_dif; i++){

        if(i%2==1){
            queb = -4.0/(2.0*i+1.0);} 
        else{
            queb = 4.0/(2.0*i+1.0);};

        valor_pi += queb;
    };

    printf("%d\n", i);


    return 0;
}