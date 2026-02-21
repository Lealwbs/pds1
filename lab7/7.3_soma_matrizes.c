#include <stdio.h>

void print_matrix(int matrix[5][5]);

int main(int argc, char** argv){
    if(argc < 2){
        printf("ERRO: Nome do arquivo nao fornecido.\n");
        return -1;
    }
    
    char* filename = argv[1];
    FILE* file = fopen(filename, "r");
    if(file == NULL){
        printf("ERRO: Nao foi possivel abrir o arquivo.\n");
        return -1;
    }

    int value, matrix[5][5];
    
    for(int k=0; k<2; k++)
        for(int i=0; i<5; i++)
            for(int j=0; j<5; j++){    
                fscanf(file, "%d ", &value);
                matrix[i][j] = (k==0) ? value : matrix[i][j] + value;
            }
    
    print_matrix(matrix);

    fclose(file);
    return 0;
}

void print_matrix(int matrix[5][5]){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}