Aqui estãos todos os arquivos dos laboratórios do curso de Programação e Desenvolvimento de Software I.

# Linguagem C

## Introdução

```c
#include <stdio.h>

int main(){
	printf("Hello, world!\n");
	system("pause"); //Usado para executar comandos do OS (Manter janela aberta)
	return 0; //Retornar 0 (Sem erros), 1 (Com erros)
}
```

**printf()**: Usado para imprimir saída na tela.

```c
int num
printf("%d", num);
```

**scanf()**: Usado para ler entrada do usuário.

```c
int num;
scanf("%d", &num);
```

**scanf_s()**: Uma versão mais segura de **`scanf()`** que evita vulnerabilidades de estouro de buffer.

```c
int num;
scanf_s("%d", &num);
```

**if-else**: Usado para tomar decisões condicionais.

```c
if (condição) {
    // código a ser executado se a condição for verdadeira
} else {
    // código a ser executado se a condição for falsa
}
```

**for loop**: Usado para executar um bloco de código repetidamente.

```c
for (inicialização; condição; incremento) {
    // código a ser repetido
}
```

**while loop**: Outra estrutura de repetição.

```c
while (condição) {
    // código a ser repetido enquanto a condição for verdadeira
}
```

**do-while loop**: Similar ao **`while`**, mas garante que o bloco seja executado pelo menos uma vez.

```c
do {
    // código a ser repetido
} while (condição);
```

**switch-case**: Usado para múltiplas condições.

```c
switch (expressão) {
    case valor1:
        // código a ser executado se expressão == valor1
        break;
    case valor2:
        // código a ser executado se expressão == valor2
        break;
    default:
        // código a ser executado se nenhum dos valores corresponder à expressão
}
```

---

# Tipos de Dados

| Nome | Tamanho | Quando usar | printf %? | Exemplo |
| --- | --- | --- | --- | --- |
| char | 1 byte | Caracteres entre -128 e 127 (ou 0 e 255) | %c | 'A' |
| short | 2 bytes | Inteiros -32,768 e 32,767 (ou 0 e 65,535) | %hd | 1234 |
| int | 4 bytes | Inteiros gerais (maior parte dos casos). | %d | 123456 |
| long | 8 bytes | Inteiros longos de alcance maior | %ld | 1234567890 |
| float | 4 bytes | Números flutuante de precisão simples | %f | 3.14159 |
| double | 8 bytes | Números flutuante de precisão dupla | %lf | 3.14159265358979 |

---

# Matrizes

1. **Declaração de Matriz**: Uma matriz é uma coleção de elementos do mesmo tipo de dados, organizados em linhas e colunas. A declaração de uma matriz em C segue o formato: `tipo nome_da_matriz[tamanho_linhas][tamanho_colunas];`
    
    ```c
    int matriz[3][3];
    ```
    
2. **Inicialização de Matriz**: Você pode inicializar uma matriz ao declará-la ou atribuir valores posteriormente usando loops.
    
    ```c
    int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    ```
    
    Ou:
    
    ```c
    int matriz[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            matriz[i][j] = i + j;
        }
    }
    ```
    
3. **Acesso aos Elementos da Matriz**: Você pode acessar elementos individuais da matriz usando índices.
    
    ```c
    int valor = matriz[1][2]; // Acessando o elemento na segunda linha, terceira coluna
    ```
    
4. **Iteração sobre uma Matriz**: Você pode percorrer todos os elementos de uma matriz usando loops aninhados.
    
    ```c
    for (int i = 0; i < tamanho_linhas; i++) {
        for (int j = 0; j < tamanho_colunas; j++) {
            // faça algo com matriz[i][j]
        }
    }
    ```
    
5. **Passagem de Matriz para Funções**: Matrizes são passadas para funções como ponteiros para seu primeiro elemento.
    
    ```c
    void funcao(int matriz[][3]) {
        // faça algo com matriz
    }
    ```
    
6. **Vetores Unidimensionais**: Um vetor unidimensional é uma matriz com apenas uma dimensão. A declaração é semelhante a uma matriz, mas com apenas um tamanho.
    
    ```c
    int vetor[5]; // Vetor de inteiros com 5 elementos
    ```
    
    Acesso e manipulação são semelhantes aos de uma matriz, mas com apenas um índice.
    
    ```c
    int valor = vetor[2]; // Acessando o terceiro elemento do vetor
    ```
    
    ---
    
    # `int main()` vs `void main()`
    
    Em C, **`int main()`** e **`void main()`** são duas assinaturas diferentes para a função principal de um programa. A diferença entre elas está no tipo de valor que a função retorna e na lista de parâmetros que ela aceita:
    
    1. **int main()**:
        - A função **`main`** retorna um valor inteiro (**`int`**).
        - Esta é a forma padrão e mais comum de definir a função principal em C.
        - O valor retornado pela função **`main`** é um código de saída que indica o status de execução do programa para o ambiente de execução (geralmente, um código não zero indica algum tipo de erro).
        
        Exemplo:
        
        ```c
        int main() {
            // código do programa
            return 0; // indica que o programa foi executado com sucesso
        }
        ```
        
    2. **void main()**:
        - A função **`main`** não retorna nenhum valor (**`void`**).
        - Embora possa ser reconhecida por alguns compiladores, essa forma não é padrão e não é especificada pelo padrão da linguagem C.
        - Pode resultar em comportamento indefinido ou incompatibilidade com alguns compiladores e ambientes.
        
        Exemplo:
        
        ```c
        void main() {
            // código do programa
        }
        ```
        
    
    É importante notar que, embora **`void main()`** possa funcionar em alguns compiladores, não é considerado uma prática recomendada em C. O padrão da linguagem especifica **`int main()`** como a assinatura correta para a função principal.