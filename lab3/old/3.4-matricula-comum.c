#include <stdio.h>

int main(){
    int i, j, temp, q_aeds, q_calc;

    scanf("%d", &q_aeds);
    int aeds[q_aeds];
    for(i=0; i<q_aeds; i++){
        scanf("%d", &temp);
        aeds[i] = temp;
    };

    scanf("%d", &q_calc);
    int calc[q_calc];
    for(i=0; i<q_calc; i++){
        scanf("%d", &temp);
        calc[i] = temp;
        };

    for(i=0; i<q_aeds; i++){
        for(j=0; j<q_calc; j++){
            if(aeds[i] == calc[j]){
                printf("%d\n", aeds[i]);
                break;
            };
        };
    };
    

    return 0;
}