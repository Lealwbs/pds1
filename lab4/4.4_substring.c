#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool is_substr(char* str, char* substr);

int main(){
    char str[30], substr[30];
    gets(str);
    gets(substr);
    is_substr(str, substr) ? puts("Eh substring") : puts("Nao eh substring");
    return 0;
}

bool is_substr(char* str, char* substr){
    for(int i=0; i<strlen(str); i++)
        for(int j=0; j<strlen(substr); j++){
            if(str[i+j] != substr[j]) break;
            if(j == strlen(substr)-1) return true;
        }
    return false;
}