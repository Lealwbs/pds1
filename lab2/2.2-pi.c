// VOU ALTERAR ESSE CÓDIGO DEPOIS, QUERO TENTAR REFAZÊ-LO

#include <stdio.h>
#include <math.h>

int main(){
    
    int num_ite=1;
    int i;
    double x_dif=0;
    double valor_pi = 4;
    double queb = 0;
    
    scanf("%lf", &x_dif);
    //(M_PI - valor_pi) > x_dif
    for (i = 1; /*i<=100000 && */((fabs((M_PI - valor_pi)) > x_dif) ) ; i++){
        //printf("i= %d\n", i); 
        
        if (i % 2 == 1) {
             queb = -4.0 / (2.0 * i + 1.0);} 
        else {
             queb = +4.0 / (2.0 * i + 1.0);}
        
        valor_pi+= queb;
        num_ite++;
    };
    
    //printf("\nValor PI: %lf\n", valor_pi);
    //printf("Numero INPUT: %lf\n\n", x_dif);
    //printf("M_PI - valor_pi: %lf\n\n", fabs((M_PI - valor_pi)));

    //printf("Valor i:%d\n", i);
    //printf("Numero de Iterações:%d\n", num_ite);
    printf("%d\n", num_ite);
    return  0;
}