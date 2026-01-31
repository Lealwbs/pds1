#include <stdio.h>
#include <string.h>

void substitute_char(char* str, char old, char new);

int main(){
    char str[30], old_char, new_char;
    gets(str);
    scanf("%c\n%c", &old_char, &new_char);
    substitute_char(str, old_char, new_char);
    puts(str);
    return 0;
}

void substitute_char(char* str, char old, char new){
    for(int i=0; i<strlen(str); i++){
        if(str[i] == old){
            str[i] = new;
            return;
        }
    }
}