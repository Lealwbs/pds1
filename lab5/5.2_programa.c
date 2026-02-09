#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    char rua[50];
    unsigned int numero;
    char estado[50];
} endereco;

typedef struct{
    char nome[50];
    unsigned int idade;
    float salario;
    endereco end;
} pessoa;

int main(){
    const char PROMPT[] = {"\t\t\t\t[ inserir | mostrar | alterar ]"};
    const bool EXIBIR_PROMPT = false;
    const int SIZE = 5;
    pessoa dados[SIZE];
    char input_data[50];
    int count = 0;

    while( (void)(EXIBIR_PROMPT && puts(PROMPT)), gets(input_data)){
        if(!strcmp(input_data, "inserir")){
            if(count >= SIZE){
                puts("] Espaco insuficiente");
                continue;
            }
            pessoa *new = &dados[count++]; 
            scanf("%s %i %f %s %i %s", 
                new->nome, &new->idade, &new->salario, 
                new->end.rua, &new->end.numero, new->end.estado );
            printf("] Registro %s %i %.2f %s %i %s inserido\n", 
                new->nome, new->idade, new->salario, 
                new->end.rua, new->end.numero, new->end.estado);

        } if(!strcmp(input_data, "mostrar")){
            bool found = false;
            scanf("%s", input_data);
            for(int i=0; i<SIZE; i++)
                if(!strcmp(dados[i].nome, input_data)){
                    pessoa *show = &dados[i];
                    printf("] Registro %s %i %.2f %s %i %s\n", 
                        show->nome, show->idade, show->salario, 
                        show->end.rua, show->end.numero, show->end.estado);
                    found = true;
                    break;
                }
            if(!found) puts("] Registro ausente");

        } if(!strcmp(input_data, "alterar")){
            bool found = false;
            scanf("%s", input_data);
            for(int i=0; i<SIZE; i++)
                if(!strcmp(dados[i].nome, input_data)){
                    pessoa *edit = &dados[i];
                    scanf("%i %f %s %i %s", 
                        &edit->idade, &edit->salario, 
                        edit->end.rua, &edit->end.numero, edit->end.estado );
                    printf("] Registro %s %i %.2f %s %i %s alterado\n", 
                        edit->nome, edit->idade, edit->salario, 
                        edit->end.rua, edit->end.numero, edit->end.estado);
                    found = true;
                    break;
                }
            if(!found) puts("] Registro ausente para alteracao");

        } continue;
    } 
    return 0;
}