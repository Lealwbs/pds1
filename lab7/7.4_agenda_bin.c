#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char nome_t[50];
typedef char tel_t[20];
typedef struct contato{
    nome_t nome;
    tel_t tel;
    int idade;
} contato_t;

void inserir(contato_t pessoa, contato_t* agenda, int* posicao);

void alterar(contato_t pessoa, contato_t* agenda, int count);

void excluir(nome_t nome, contato_t* agenda, int count);

void exibir(nome_t nome, contato_t* agenda, int count);

int find(nome_t nome, contato_t* agenda, int count);

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

    contato_t agenda[100];
    int count = 0;
    char input[20];

    while(fgets(input, sizeof(input), file) != NULL){

        if(!strcmp(input, "Inserir\n")){
            contato_t c;
            fscanf(file, "%s %d %s", c.nome, &c.idade, c.tel);
            inserir(c, agenda, &count);
            continue;
        } else if(!strcmp(input, "Alterar\n")){
            contato_t c;
            fscanf(file, "%s %d %s", c.nome, &c.idade, c.tel);
            alterar(c, agenda, count);
            continue;
        } else if(!strcmp(input, "Excluir\n")){
            nome_t nome;
            fscanf(file, "%s", nome);
            excluir(nome, agenda, count);
            continue;
        } else if(!strcmp(input, "Exibir\n")){
            nome_t nome;
            fscanf(file, "%s", nome);
            exibir(nome, agenda, count);
            continue;
        } else {
            continue;
        }
    }

    fclose(file);
    return 0;
}

void inserir(contato_t pessoa, contato_t* agenda, int* posicao){
    agenda[(*posicao)++] = pessoa;
    printf("Registro %s %d %s inserido\n", pessoa.nome, pessoa.idade, pessoa.tel);
};

void alterar(contato_t pessoa, contato_t* agenda, int count){
    int pos = find(pessoa.nome, agenda, count);
    if(pos == -1){
        printf("Registro %s invalido\n", pessoa.nome);
        return;
    }
    agenda[pos] = pessoa;
    printf("Registro %s %d %s alterado\n", pessoa.nome, pessoa.idade, pessoa.tel);
};

void excluir(nome_t nome, contato_t* agenda, int count){
    int pos = find(nome, agenda, count);
    if(pos == -1){
        printf("Registro %s invalido\n", nome);
        return;
    }
    contato_t pessoa = agenda[pos];
    contato_t vazio = {"", "", 0};
    agenda[pos] = vazio;
    printf("Registro %s %d %s excluido\n", pessoa.nome, pessoa.idade, pessoa.tel);
};

void exibir(nome_t nome, contato_t* agenda, int count){
    int pos = find(nome, agenda, count);
    if(pos == -1){
        printf("Registro %s invalido\n", nome);
        return;
    }
    contato_t pessoa = agenda[pos];
    printf("Registro %s %d %s exibido\n", pessoa.nome, pessoa.idade, pessoa.tel);
};

int find(nome_t nome, contato_t* agenda, int count){
    for(int i=0; i<count; i++)
        if(!strcmp(nome, agenda[i].nome))
            return i;
    return -1;
};

// gcc -Wall .\7.4_agenda_bin.c -o .\bin\7.4_agenda_bin.exe | .\bin\7.4_agenda_bin.exe .\files\7.4_arquivo.txt