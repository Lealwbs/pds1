#include <stdio.h>
#include <string.h>

int main(){

    char str0[60];
    char letra;
    char novaletra;

    gets(str0);
    scanf("%c\n%c", &letra, &novaletra);

    // printf("%c %c\n", letra, novaletra);
    // printf("%c\n", str0[0]);

    for(int i=0; i<strlen(str0); i++){
        // printf("%c", str0[i]);
        if(str0[i] == letra){
            // printf("ISSO: %c :É IGUAL A ISSO: %c\n", str0[i], letra);
            str0[i] = novaletra;
            break;
        };
    };

    puts(str0);
    return 0;
};