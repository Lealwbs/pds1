#include <stdio.h>
#include <string.h>

int main(){

    char s1[30];
    char s2[30];
    int retorno = 0;

    gets(s1);
    gets(s2);

    for(int i=0; i<strlen(s1); i++){
        int count = 0;
        while(s1[i+count] == s2[count]){
            // printf("s1[i]: %c é igual a s2[count (%d)]: %c\n", s1[i+count], count, s2[count]);
            count++;
            if(count == strlen(s2)){
                retorno = 1;
                // printf("É substring");
                break;
            };
        };
    };


    if(retorno == 1) {
        printf("É substring");

    } else {

        printf("Não é substring");
    };


    return 0;
};