#include <stdio.h>
#include <math.h>
#define M_PI 3.14159265358979323846

int main(){
    double diff;
    int iterations = 0, signal = 1;
    scanf("%lf", &diff);
    for(double my_pi = 0; fabs(my_pi - M_PI) > diff; iterations++, signal *= -1){
        my_pi += 4.0/(2*iterations + 1) * signal;
    }
    printf("%d", iterations);
    return 0;
}