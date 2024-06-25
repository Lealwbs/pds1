#include <stdio.h>
#include <string.h>

int main(){
    char str1[30]; 
    char str2[30];
    gets(str1);
    gets(str2);
    strcat(str1, str2);
    puts(str1);
}



