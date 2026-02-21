#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct contato_t{
    char nome[50];
    char tel[20];
    int idade;
} contato;


int main(int argc, char** argv){
    if(argc < 2){
        printf("ERRO: Nome do arquivo nao fornecido.\n");
        return EXIT_FAILURE;
    }

    char* filename = argv[1];
    FILE* file = fopen(filename, "r");
    if(file == NULL){
        printf("ERRO: Nao foi possivel abrir o arquivo.\n");
        return EXIT_FAILURE;
    }

    contato agenda[100];
    int count = 0;
    char input[20];

    while(fgets(input, sizeof(input), file) != NULL){

        // printf("Entrada: %s", input);

        if(!strcmp(input, "Inserir\n")){
            puts("##### inserir");
            contato c = {};
            fscanf(file, "%s %d %s", c.nome, &c.idade, c.tel);
            agenda[count++] = c;
            printf("Registro %s %d %s inserido", c.nome, c.idade, c.tel);
        } else if(!strcmp(input, "Alterar\n")){
            puts("##### alterar");
        } else if(!strcmp(input, "Excluir\n")){
            puts("##### excluir");
        } else if(!strcmp(input, "Exibir\n")){
            puts("##### exibir");
        } else {
            puts("##### continue");
            continue;
        }
    }

    for(int i=0; i<count; i++){
        contato c = agenda[i];
        printf("Registro #%d: %s %d %s\n", i, c.nome, c.idade, c.tel);
    }

    fclose(file);
    return 0;
}

// gcc -Wall .\7.4_agenda_bin.c -o .\bin\7.4_agenda_bin.exe | .\bin\7.4_agenda_bin.exe .\files\7.4_arquivo.txt