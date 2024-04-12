#include <stdio.h>

int main(){
    float cels, fahr;
    scanf("%f", &cels);
    fahr = 1.8 * cels + 32.0;
    printf("%.0f", fahr);
    return 0;
}