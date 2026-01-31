#include <stdio.h>
#include <string.h>

int main(){
    char str1[20], str2[20];
    // scanf("%s\n%s", str1, str2);
    // strcat(str1, str2);
    // printf("%s", str1);
    gets(str1);
    gets(str2);
    strcat(str1, str2);
    puts(str1);
    return 0;
}