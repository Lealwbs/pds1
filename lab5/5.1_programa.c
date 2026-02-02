#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[50];
    unsigned int idade;
    float salario;
} pessoa;

enum operacoes{
    INSERIR = 1,
    MOSTRAR = 2,
};

int main(){
    const int SIZE = 4;
    pessoa dados[SIZE];
    char prompt[] = {"Digite um numero:\t[1] INSERIR\t[2] MOSTRAR"};
    char input_data[30];
    int input, count = 0;
    
    while(puts(prompt), scanf("%d", &input)){
        switch (input){
        case INSERIR:
            if(count >= 4){
                puts("Espaco insuficiente\n");
                break;
            }
            pessoa new = {}; 
            scanf("%s %i %f", new.nome, &new.idade, &new.salario );
            dados[count++] = new;
            break;

        case MOSTRAR:
            pessoa show = {};
            scanf("%s", input_data);
            for(int i=0; i<SIZE; i++)
                if(strcmp(dados[i].nome, input_data))
                    show = dados[i];

            strcmp(show.nome, "") ? puts("Registro ausente\n") : printf("%s %i %f\n", show.nome, show.idade, show.salario);
            break;
        
        default: 
            break;
        }
    }
}