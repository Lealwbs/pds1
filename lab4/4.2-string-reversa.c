#include <stdio.h>
#include <string.h>

int main(){

    char str1[60];
    char str2[60];

    setbuf(stdin, NULL);
    gets(str1);

    // puts(str1);

    int i;
    for(i=0; i<strlen(str1); i++){
        str2[strlen(str1)-i-1] = str1[i];
    };

    // printf("%d", str2[strlen(str1)]);
    str2[strlen(str1)] = "\n";

    puts(str2);

    return 0;
}
