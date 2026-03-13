#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef char code[10];
typedef char name[50];
typedef char state[3];

typedef struct product_t{
    code codigo;
    name nome;
    int quantidade;
    float preco;
    state estado;
} product;

typedef enum action_t{
    RELATORIO_ESTOQUE = 1,
    PRODUTO_POR_CODIGO = 2,
    PRODUTO_MENOR_ESTOQUE = 3,
    PRODUTOS_POR_ESTADO = 4,
    PRODUTO_MENOR_ESTOQUE_POR_ESTADO = 5,
    QUANTIDADE_TOTAL_ESTOQUE = 6
} action;

FILE* get_input_file(int argc, char** argv);
FILE* get_output_file(int argc, char** argv);
action get_action(int argc, char** argv);

void print_product(product produto);
void log_product(product produto, FILE* arquivo);
int compare_nome(const void *a, const void *b);

void get_relatorio_estoque(product* produtos, int size, FILE* arquivo);
void get_produto_por_codigo(product* produtos, int size, code codigo);
void get_produto_menor_estoque(product* produtos, int size);
void get_produto_por_estado(product* produtos, int size, state estado);
void get_produto_menor_estoque_por_estado(product* produtos, int size, state estado);
void get_quantidade_total_estoque(product* produtos, int size);

int main(int argc, char **argv){
    FILE* input = get_input_file(argc, argv), *output;
    action acao = get_action(argc, argv);
    code codigo; state estado;

    int qtde_produtos;
    fscanf(input, "%d", &qtde_produtos);
    product produtos[qtde_produtos];

    for(int i=0; i<qtde_produtos; i++){
        fscanf(input, "%s", produtos[i].codigo);
        fscanf(input, " %[^\n]", produtos[i].nome);
        fscanf(input, "%d", &produtos[i].quantidade);
        fscanf(input, "%f", &produtos[i].preco);
        fscanf(input, "%s", produtos[i].estado);
    }

    qsort(produtos, qtde_produtos, sizeof(product), compare_nome);

    switch(acao){
        case RELATORIO_ESTOQUE:
            output = get_output_file(argc, argv);
            get_relatorio_estoque(produtos, qtde_produtos, output);
            fclose(output);
            break;
        case PRODUTO_POR_CODIGO:
            strcpy(codigo, argv[3]);
            get_produto_por_codigo(produtos, qtde_produtos, codigo);
            break;
        case PRODUTO_MENOR_ESTOQUE:
            get_produto_menor_estoque(produtos, qtde_produtos);
            break;
        case PRODUTOS_POR_ESTADO:
            strcpy(estado, argv[3]);
            get_produto_por_estado(produtos, qtde_produtos, estado);
            break;
        case PRODUTO_MENOR_ESTOQUE_POR_ESTADO:
            strcpy(estado, argv[3]);
            get_produto_menor_estoque_por_estado(produtos, qtde_produtos, estado);
            break;
        case QUANTIDADE_TOTAL_ESTOQUE:
            get_quantidade_total_estoque(produtos, qtde_produtos);
            break;
    }

    fclose(input);
    exit(EXIT_SUCCESS);
} 

/////////////////////////////
// LEITURA DE PARÂMETROS
/////////////////////////////

FILE* get_input_file(int argc, char** argv){
    if(argc < 2){
        printf("ERRO: Nome do arquivo de entrada nao fornecido\n");
        exit(EXIT_FAILURE);
    }
    FILE* input = fopen(argv[1], "r");
    if(input == NULL){
        printf("ERROR: Nao foi possivel abrir o arquivo de entrada\n");
        exit(EXIT_FAILURE);
    }
    return input;
}

FILE* get_output_file(int argc, char** argv){
    if(argc < 4){
        printf("ERRO: Nome do arquivo saida nao fornecido\n");
        exit(EXIT_FAILURE);
    }
    FILE* output = fopen(argv[3], "w");
    if(output == NULL){
        printf("ERROR: Nao foi possivel abrir o arquivo de saida\n");
        exit(EXIT_FAILURE);
    }
    return output;
}

action get_action(int argc, char** argv){
    if(argc < 3){
        printf("ERRO: Funcao a ser executada nao foi informada\n");
        exit(EXIT_FAILURE);
    }
    int function;
    sscanf(argv[2], "%d", &function);
    if(!(1 <= function && function <= 6)){
        printf("ERRO: Funcao a ser executada precisa ser um numero entre 1 e 6\n");
        exit(EXIT_FAILURE);
    }
    return (action)function;
}

/////////////////////////////
// AUXILIARES
/////////////////////////////

void print_product(product produto){
    printf("%s\n", produto.codigo);
    printf("%s\n", produto.nome);
    printf("%d\n", produto.quantidade);
    printf("%.2f\n", produto.preco);
    printf("%s\n", produto.estado);
}

void log_product(product produto, FILE* arquivo){
    fprintf(arquivo, "%s\n", produto.codigo);
    fprintf(arquivo, "%s\n", produto.nome);
    fprintf(arquivo, "%d\n", produto.quantidade);
    fprintf(arquivo, "%.2f\n", produto.preco);
    fprintf(arquivo, "%s\n", produto.estado);
}

int compare_nome(const void *a, const void *b){
    product* p1 = (product*)a;
    product* p2 = (product*)b;
    return strcmp(p1->nome, p2->nome);
}

/////////////////////////////
// AÇÕES A SEREM EXECUTADAS
/////////////////////////////

void get_relatorio_estoque(product* produtos, int size, FILE* arquivo){
// 1. Gerar relatório de estoque: O programa deve gerar 
// um arquivo TXT, com o nome passado pelo param3, salvo no mesmo diretório 
// de execução. Deve-se salvar a lista de todos os produtos COM OS NOMES EM 
// ORDEM ALFABÉTICA, com os mesmos dados da entrada, um dado por linha 
// (Código, Nome, Quantidade, Preço e Estado).

    for(int i=0; i<size; i++){
        log_product(produtos[i], arquivo);
    }
}

void get_produto_por_codigo(product* produtos, int size, code codigo){
// 2. Pesquisar por produto pelo código: O programa deverá 
// imprimir na saída padrão (tela) todos os dados do produto que
// tenha o código igual ao informado no param3, um dado por linha 
// (Código, Nome, Quantidade, Preço e Estado).

    for(int i=0; i<size; i++){
        if(!strcmp(codigo, produtos[i].codigo)){
            print_product(produtos[i]);
        }
    }
}

void get_produto_menor_estoque(product* produtos, int size){
// 3. Listar dados do produto com menor quantidade em estoque: O programa 
// deverá imprimir na saída padrão (tela) todos os dados do produto 
// que possui a menor quantidade em estoque, um dado por linha 
// (Código, Nome, Quantidade, Preço e Estado).

    int menor_index = 0, menor_qtde = INT_MAX;
    for(int i=0; i<size; i++){
        if(produtos[i].quantidade < menor_qtde){
            menor_qtde = produtos[i].quantidade;
            menor_index = i;
        }
    }
    print_product(produtos[menor_index]);
}

void get_produto_por_estado(product* produtos, int size, state estado){
// 4. Pesquisar por produto pelo estado: O programa deverá imprimir na 
// saída padrão (tela) a lista de produtos do estado informado no param3, 
// EM ORDEM ALFABÉTICA, com todos os dados de cada produto, um dado por linha 
// (Código, Nome, Quantidade, Preço e Estado).

    for(int i=0; i<size; i++){
        if(strcmp(estado, produtos[i].estado) == 0){
            print_product(produtos[i]);
        }
    }
}

void get_produto_menor_estoque_por_estado(product* produtos, int size, state estado){
// 5. Encontrar produto com menor quantidade em estoque do estado: O programa 
// deverá imprimir na saída padrão (tela) o produto do estado informado no
// param3 que possui a menor quantidade em estoque, um dado por linha 
// (Código, Nome, Quantidade, Preço e Estado).

    int menor_index = -1, menor_qtde = INT_MAX;
    for(int i=0; i<size; i++){
        if(strcmp(estado, produtos[i].estado) == 0 && produtos[i].quantidade < menor_qtde){
            menor_qtde = produtos[i].quantidade;
            menor_index = i;
        }
    }
    if(menor_index != -1) print_product(produtos[menor_index]);
}

void get_quantidade_total_estoque(product* produtos, int size){
// 6. Calcular a quantidade total de itens no estoque:
// O programa deverá imprimir na saída padrão (tela) a quantidade total de itens. Para o
// cálculo da quantidade total de itens do estoque deve-se somar a quantidade de cada
// produto, recebida no arquivo de entrada. Cada dado deve ser impresso por linha. (Ex.: 125)

    int soma = 0;
    for(int i=0; i<size; i++){
        soma += produtos[i].quantidade;
    }
    printf("%d\n", soma);
}