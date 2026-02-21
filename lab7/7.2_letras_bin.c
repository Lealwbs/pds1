#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    if(argc < 2){
        printf("ERRO: Nome do arquivo nao fornecido.\n");
        return 1;
    }

    char* filename = argv[1];
    FILE* file = fopen(filename, "rb");
    if(file == NULL){
        printf("ERRO: Nao foi possivel abrir o arquivo.\n");
        return 1;
    }

    int count = 0;
    char letter;

    while(fread(&letter, sizeof(char), 1, file)){
        if( letter == 'a')
            count++;
    }

    printf("%d", count);
    fclose(file);
    return 0;
}