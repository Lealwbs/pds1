#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv){
    if(argc < 2){
        printf("ERRO: Nome do arquivo nao fornecido\n");
        exit(EXIT_FAILURE);
    }

    char* filename = argv[1];
    FILE* file = fopen(filename, "r");
    if(file == NULL){
        printf("ERROR: Nao foi possivel abrir o arquivo\n");
        exit(EXIT_FAILURE);
    }

    int count = 0;
    char letter;

    while(fread(&letter, sizeof(char), 1, file)){
        if(letter == 'a')
            count++;
    }

    printf("%d", count);
    fclose(file);
}