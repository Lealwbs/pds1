#include <stdio.h>
// #include <stdlib.h>

enum semana{dom = 0, seg, ter, qua, qui, sex, sab};
enum semana ref, ref2;

int main(){

    for(ref; ref<10; ref++, ref2++){
        printf("%d\n", ref);
        //printf("%d\n", ref2);


    }

    // printf("%d", semana);
    //printf("%d\n", ter);

    return 0;
}