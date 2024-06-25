#include <stdio.h>
#include <string.h>

int main(){

    // BASE
    struct cadastro{
        char nome[50];
        int idade;
        char sexo;
        float nota1, nota2, nota3;   
    } pes_a, pes_b, pes_c; // INICIALIZAÇÃO DIRETA

    struct cadastro cade; // INICIALIZAÇÃO SEPARADA

    // ATRIBUIÇÃO
    strcpy(pes_a.nome, "Carlos");
    pes_a.nota1 = 13.6;

    printf("%s %.2f\n", pes_a.nome, pes_a.nota1);

    // OU PODE-SE FAZER ISSO:
    struct cadastro cad[300]; // INICIALIZAÇÃO AMPLA


    // UNION
    // Mesma coisa da STRUCT
    typedef struct cadastro cd;

    cd pessoas[5];

    // Declarando uma variável do tipo Numero
    union Numero {
    int numero_inteiro;
    float numero_decimal;
    };

    union Numero num;

    // Atribuindo valores à union
    num.numero_inteiro = 10;
    printf("Número inteiro: %d\n", num.numero_inteiro);

    num.numero_decimal = 5.5;
    printf("Número decimal: %.2f\n", num.numero_decimal);

    // Imprimindo o valor após troca
    printf("Número inteiro após mudança: %d\n", num.numero_inteiro);

    return 0;
}