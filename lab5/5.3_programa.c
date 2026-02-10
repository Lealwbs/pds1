#include <stdio.h>
#include <string.h>

typedef struct{
    char nome[50];
    char marca[50];
    float preco;
} produto;

typedef struct{
    char marca[50];
    int quantidade;
    float preco_total;
} dados_produto;

int main(){
    const int MAX_SIZE = 8;
    produto produtos[8] = {};
    dados_produto unicos[8];
    int qtde_unicos = 0;
    float valor_total = 0;

    for(int i=0; i<MAX_SIZE; i++){
        char marca[50];
        scanf("%s %s %f", produtos[i].nome, marca, &produtos[i].preco);
        strcpy(produtos[i].marca, marca);
        valor_total += produtos[i].preco;

        int id = -1;
        for(int i=0; i<MAX_SIZE; i++)
            if(!strcmp(marca, unicos[i].marca))
                id = i;
                
        if(id == -1){
            strcpy(unicos[qtde_unicos].marca, produtos[i].marca);
            unicos[qtde_unicos].quantidade = 1;
            unicos[qtde_unicos].preco_total = produtos[i].preco;
            qtde_unicos++;
        } else {
            unicos[id].quantidade += 1;
            unicos[id].preco_total += produtos[i].preco;
        }
    }

    printf("\n");

    for(int i=0; i<qtde_unicos; i++)
        printf("%s %i\n", unicos[i].marca, unicos[i].quantidade);
    
    printf("media total %.2f\n", valor_total/8.0);

    for(int i=0; i<qtde_unicos; i++)
        printf("media %s %.2f\n", unicos[i].marca, unicos[i].preco_total/unicos[i].quantidade);

    return 0;
}