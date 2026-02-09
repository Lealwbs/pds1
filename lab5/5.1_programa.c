#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    char nome[50];
    unsigned int idade;
    float salario;
} pessoa;

int main(){
    const int SIZE = 4;
    pessoa dados[SIZE];
    char input_data[30];
    int count = 0;

    while(puts("\t\t\t\t[ inserir | mostrar ]"), setbuf(stdin, NULL), gets(input_data)){
        if(!strcmp(input_data, "inserir")){
            if(count >= SIZE){
                puts("] Espaco insuficiente");
                continue;
            }
            pessoa *new = &dados[count++]; 
            scanf("%s %i %f", new->nome, &new->idade, &new->salario );
            printf("] Registro %s %i %.2f inserido\n", new->nome, new->idade, new->salario);

        } if(!strcmp(input_data, "mostrar")){
            bool found = false;
            scanf("%s", input_data);
            for(int i=0; i<SIZE; i++)
                if(!strcmp(dados[i].nome, input_data)){
                    pessoa *show = &dados[i];
                    printf("] Registro %s %i %f\n", show->nome, show->idade, show->salario);
                    found = true;
                    break;
                }
            if(!found) puts("] Registro ausente");

        } continue;
    } 
    return 0;
}