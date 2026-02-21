# Programação em C — Resumo Prático (PDS1 - UFMG)

Este documento reúne minhas anotações e conceitos essenciais estudados na disciplina **Programação e Desenvolvimento de Software I**.
A ideia é servir como uma *wiki rápida* para consulta futura: sintaxe básica, operadores, estruturas de controle, tipos de dados, vetores, matrizes e boas práticas.

---

## Introdução

### Primeiro Programa

```c
#include <stdio.h>

int main(){
    printf("Hello, world!\n");
    return 0;
}
```

### Funções de Entrada e Saída

#### `printf()`

Usada para imprimir valores na tela.

```c
int num = 10;
printf("%d", num);  // imprime 10
```

#### `scanf()` e `scanf_s()`

Leitura do teclado (sempre usar **&variável** para inteiros, floats etc).

```c
int x;
scanf("%d", &x);
```

`scanf_s()` é uma versão mais segura (exigida em alguns compiladores, como MSVC).

#### Tabela Resumida de Formatos


| Tipo               | printf/scanf |
| -------------------- | -------------- |
| char               | `%c`         |
| int                | `%d`         |
| short              | `%hd`        |
| long               | `%ld`        |
| long long          | `%lld`       |
| unsigned long      | `%lu`        |
| unsigned long long | `%llu`       |
| unsigned           | `%u`         |
| float              | `%f`         |
| double             | `%lf`        |
| long double        | `%Lf`        |
| string             | `%s`         |

---

## Estruturas de Controle

### Condicionais

```c
if (cond) {
    ...
} else {
    ...
}
```

### switch-case

```c
switch (x) {
    case 1: ...; break;
    default: ...;
}
```

### Loops

**for**

```c
for (int i = 0; i < 10; i++)
```

**while**

```c
while (cond)
```

**do-while**

```c
do { ... } while (cond);
```

### Controle de Fluxo

* `continue` → pula para a próxima iteração
* `break` → encerra o laço
* `goto` e `label` → pula para uma linha específica (desencorajado)

---

## Operadores Fundamentais

### Aritméticos


| Operador | Função                     | Atribuição Composta |
| ---------- | ------------------------------ | ----------------------- |
| `+`      | Adição                     | x += y                |
| `-`      | Subtração                  | x -= y                |
| `*`      | Multiplicação              | x *= y                |
| `/`      | Divisão                     | x /= y                |
| `%`      | Resto da divisão (inteiros) | x %= y                |

### Unários


| Operador    | Significado                            |
| ------------- | ---------------------------------------- |
| `+x`        | valor positivo                         |
| `-x`        | negação                              |
| `++x / x++` | incremento (pré/pos)                  |
| `--x / x--` | decremento (pré/pos)                  |
| `&x`        | endereço / referenciação            |
| `*x`        | conteúdo apontado / dereferenciação |

### Lógicos


| Operador | Função |
| ---------- | ---------- |
| `==`     | EQUALS   |
| `&&`     | AND      |
| `||`     | OR       |
| `!`      | NOT      |

### Operadores Bitwise


| Op   | Significado | Exemplo    |
| ------ | ------------- | ------------ |
| `&`  | AND         | `x & 0x0F` |
| `|`  | OR          | `x | 0xF0` |
| `^`  | XOR         | `x ^ 0xFF` |
| `~`  | NOT         | `~x`       |
| `<<` | shift left  | `x << 2`   |
| `>>` | shift right | `x >> 3`   |

> Úteis em sistemas embarcados, compressão, flags, manipulação de bits etc.

---

## Tipos de Dados


| Tipo                     | Tamanho               | Formato Printf | Uso                     |
| -------------------------- | ----------------------- | ---------------- | ------------------------- |
| `char`                   | 1 byte                | %c             | caracteres              |
| `short`                  | 2 bytes               | %hd            | inteiros pequenos       |
| `int`                    | 4 bytes               | %d             | inteiro padrão         |
| `long`                   | 8 bytes               | %ld            | inteiros grandes        |
| `float`                  | 4 bytes               | %f             | ponto flutuante simples |
| `double`                 | 8 bytes               | %lf            | ponto flutuante duplo   |
| `long double`            | 16 bytes              | %Lf            | precisão estendida     |
| `unsigned` (variações) | mesmo tamanho do tipo | %u             | somente positivos       |

---

## Sequências de Escape (char)


| Código | Significado      |
| --------- | ------------------ |
| `\n`    | nova linha       |
| `\t`    | tab              |
| `\\`    | barra invertida  |
| `\"`    | aspas            |
| `\0`    | fim de string    |
| `\a`    | beep             |
| `\r`    | retorno de carro |
| `\b`    | backspace        |

---

## Palavras Reservadas (C89/C99)

```c
auto break case char const continue
default do double else enum extern
float for goto if int long register
return short signed sizeof static
struct switch typedef union unsigned
void volatile while
```

---

## Vetores (Arrays)

### Declaração

```c
int v[5];
float notas[100];
```

### Inicialização

```c
int v[3] = {15, 22, 7};
int v2[] = {10, 20, 30};
```

### Acesso

```c
int x = v[2];
v[1] = 99;
```

---

## Matrizes (Arrays Multidimensionais)

### Declaração

```c
int mat[3][3];
```

### Inicialização

```c
int m[2][2] = {{1,2}, {3,4}};
```

### Preenchimento via loops

```c
for (int i=0; i<3; i++){
    for (int j=0; j<3; j++){
        mat[i][j] = i + j;
    }
}
```

### Passando matrizes para funções

```c
void imprime(int m[][3]) { ... }
```

---

## Função main()

### Recomendado pelo padrão C

```c
int main(void) {
    return 0;
}
```

### Por que evitar `void main()`?

* Não é padrão.
* Pode gerar comportamento indefinido.
* Sistemas operacionais esperam **código de retorno**.

---

## Boas Práticas Rápidas

* **Sempre inicialize variáveis.**
* Use `int main(void)` e `return 0;`.
* Use `const` quando um valor não deve mudar.
* Prefira `while` quando a quantidade de repetições é desconhecida.
* Em leitura de strings, prefira `fgets()` em vez de `gets()` (que é insegura).
* Sempre valide divisões para evitar divisão por zero.
* Comente trechos importantes, mas evite comentar coisas óbvias.

---

## Extras Úteis (acréscimos moderados)

### Conversão de tipos (casting)

```c
int x = 5, y = 2;
float z = (float)x / y; // evita truncamento
```

### Constantes simbólicas

```c
#define PI 3.14159
const int MAX = 100;
```

### Operador ternário

```c
int maior = (a > b) ? a : b;
```

### Função `sizeof()`

```c
printf("%zu", sizeof(double));
sizeof(int);         // normalmente 4
sizeof(double);      // normalmente 8
sizeof(long long);   // normalmente 8
```

---

## Strings

### Declaração e Inicialização

```c
char str0[5];
char str1[20] = "Hello";
char str2[] = "World";
char *str3 = "Lorem";
char str4[] = {'I', 'p', 's', 'u', 'm', '\0'};
str2[0] = 'B'; // "Borld"
```

* Strings em C são arrays de caracteres terminados em `\0` (null character). <br>
  Ex: `char str[6] = "Teste";` → na memória: T e s t e \0
* Na inicialização: aspas duplas. Na atribuição: aspas simples para caracteres individuais.

### Manipulação de Strings

**string.h**: Biblioteca necessária para manipulação de strings.

```c
#include <string.h>
```

**scanf("%REGEX", texto);**: Lê uma linha inteira (até o Enter)

```c
char texto[100];
scanf("%[^\n]", texto); 
```

**gets(str):** Lê uma string do teclado e coloca em str.

```c
char str[10];
gets(str); 
```

**setbuf(stdin, NULL):** Limpa o buffer

```c
setbuf(stdin, NULL);
```

**printf(str):** Imprimir a string

```c
char str[20] = "Hello World";
printf("%s",str); // imprime "Hello World"
```

**strlen(str):** Retorna o tamanho da string (sem contar o \0)

```c
char str[15] = "teste";
printf("%d",strlen(str)); // imprime 5
```

**strcpy(dest, fonte):** Copia uma string para outra

```c
char str1[20] = "Hello";
char str2[20];
strcpy(str2, str1); // str2 agora é "Hello"
```

**strcat(dest, fonte):** Concatena (junta) duas strings

```c
char str1[15] = "bom ";
char str2[15] = "dia";
strcat(str1,str2); // str1 agora é "bom dia"
```

**strcmp(str1, str2):** Compara duas strings por ordem alfabética, se forem iguais retorna 0. Se str1 > str2, retorna um valor positivo. Se str1 < str2, retorna um valor negativo.

```c
if (strcmp(str1, str2) == 0)
    printf("Strings iguais");
else
    printf("Strings diferentes");
```

**char \*fgets(char \*str, int tamanho, FILE \*fp):** Lê uma string do teclado até que um caractere de nova linha ('\n') seja lido (e incluído) ou tamanho-1 caracteres tenham sido lidos. A string resultante sempre terminará com '\0'. No final, retorna um ponteiro para a string lida ou NULL em caso de erro.

```c
char str[10];
fgets(str, 10, stdin); // lê até 9 caracteres + \0 do stdin (teclado)
```

**int fputs (char \*str, FILE \*fp):** Escreve uma string em um arquivo ou na tela.
Se o for bem sucedido, retorna um valor não negativo. Em caso de erro, retorna EOF (-1).

```c
char str[20] = "Hello World";
fputs(str, stdout); // escreve "Hello World" no stdout (tela)
```

### Vetor de Strings (Array de Strings)

```c
char dia_semana[7][14] = {
    "Domingo", "Segunda", "Terca", "Quarta", "Quinta", "Sexta", "Sabado"
};
```

---

## Estruturas (Structs)

### Definição

```c
struct Ponto {
    int x;
    int y;
};

struct aluno {
    char nome[50];
    int idade;
    float nota;
};
```

```c
struct Ponto p1;
p1.x = 10;
p1.y = 20;

struct aluno a1;
strcpy(a1.nome, "Joao");
a1.idade = 20;
a1.nota = 8.5;
```

### Typedef

O comando não cria um novo tipo, apenas um **apelido** (alias) para um tipo já existente.

```c
typedef double nota_t; // cria um novo tipo chamado nota_t
typedef int cpf_t[11] ; // cria um tipo cpf_t (array de 11 ints)
```

Faz mais sentido usar typedef com structs:

```c
typedef struct {
    double x;
    double y;
} ponto_t;

int main(void) {
    ponto_t p;
    return 0;
}
```

### Uso e Acesso

**Estruturas Aninhadas:** Tipos compostos, acessando usando repetidos pontos `.`.

```c
typedef struct {
    double x;
    double y;
} ponto_t;

typedef struct {
    ponto_t centro;
    double raio;
} circulo_t;

typedef struct {
    ponto_t base;
    circulo_t janela;
    double altura;
    double largura;
} casa_t;
```

**Inicializando:** Acessamos os campos usando `{}` ou `.`

```c
ponto_t p1;
p1.x = 10.0;
p1.y = 20.0;
circulo_t c1 = {{0.0, 0.0}, 5.0};
triangulo_t t1 = {{0.0, 0.0}, {5.0, 0.0}, {2.5, 5.0}};
```

```c
struct cadastro{
    char nome[50];
    int idade;
    char sexo;
    float nota1, nota2, nota3;   
} pes_a, pes_b, pes_c; // INICIALIZAÇÃO DIRETA

struct cadastro cade; // INICIALIZAÇÃO SEPARADA
```

**Array de estruturas:** Acessamos os campos usando `indices[]` e `.`

```c
// Variável "conjunto" é uma array de 3 circulos
struct circulo_t conjunto[3]; 
conjunto[0].centro.x = 10.0;
conjunto[1].raio = 5.0;
conjunto[2].largura = 15.0;

// Tipo "triangulo_t" é uma array de 3 pontos
typedef ponto_t triangulo_t[3]; 
triangulo_t t1 = {{0.0, 0.0}, {0.0, 0.0}, {2.5, 5.0}};
// Ou, poderia ser usado:
struct ponto_t t1[3];

t1[1] = (ponto_t){10.0, 9.0};
t1[2].y = 0.5;
```

**Atribuição entre structs:** Devem ser do mesmo tipo

```c
ponto_t p1 = {1.0, 2.0};
ponto_t p2;
p2 = p1; // cópia dos valores de p1 para p2
```

```c
ponto_t p[10];
p[0] = (ponto_t){5.0, 7.0};
p[1] = p[0]; // cópia dos valores de p[0] para p[1]
```

### Unions

**Diferença:** Em uma `struct`, cada campo tem seu próprio espaço na memória. Em uma `union`, todos os campos compartilham o mesmo espaço, ou seja, o tamanho da union é igual ao tamanho do maior campo.

Definição

```c
union dado {
    int i;
    float f;
    char c;
};
```

Uso

```c
union dado d;
d.i = 10;
printf("%d\n", d.i); // imprime 10
d.f = 3.14;
printf("%d\n", d.i); // comportamento indefinido
printf("%f\n", d.f); // imprime 3.14
```

---

## Enumeradores

Definição

```c
enum colors { RED, GREEN, BLUE };

typedef enum {
    domingo = 1,
    segunda = 2,
    terca = 3,
    quarta = 4,
    quinta = 5,
    sexta = 6,
    sabado = 7,
} dias_semana_t;
```

Uso

```c
enum colors c = RED;
dias_semana_t hoje = quarta;
if (hoje == 4) {
    // faz algo
}
```

## Alinhamento de memória

* char (1 byte)
* short int (2 bytes)
* int (4 bytes)
* double (8 bytes)

```c
struct Bom_Alinhamento {
    char c;        // 1 byte
    int i;         // 4 bytes (3 bytes de padding)
    double d;      // 8 bytes
}; // total: 16 bytes

struct Mal_Alinhamento {
    char c;        // 1 byte
    double d;      // 8 bytes (7 bytes de padding)
    int i;         // 4 bytes
}; // total: 20 bytes
```

**Representação em memória (com ASCII):** <br>

> **[xxxx]:** padding (1 byte cada) <br>
> **[char]:** character (2 bytes ao todo) <br>
> **[int_]:** inteiro (4 bytes ao todo) <br>
> **[dobl]:** double (8 bytes ao todo) <br>

**Bom Alinhamento (16 bytes):**

```
[char][xxxx][xxxx][xxxx][int_][int_][int_][int_]
[dobl][dobl][dobl][dobl][dobl][dobl][dobl][dobl]
```

**Mal Alinhamento (20 bytes):**

```
char c:   [char][xxxx][xxxx][xxxx][xxxx][xxxx][xxxx][xxxx]
double d: [dobl][dobl][dobl][dobl][dobl][dobl][dobl][dobl]
int i:    [int_][int_][int_][int_]
```

---

## Funções

```c
tipo_retorno nome_funcao(tipo_parametro parametro) {
    // corpo da função
    return retorno;
}
```

### Uso

```c

int soma(int a, int b) {
    return a + b;
}

// Void no parametro indica que a função não recebe argumentos, e no tipo de retorno indica que a função não retorna nada.
void main(void) {
    int x = 5, y = 10;
    int resultado = soma(x, y);
    printf("A soma é: %d\n", resultado);
}
```

### Passagem por Valor

```c
void incrementa(int n) {
    n = n + 1; // modifica apenas a cópia local
    return; 
}

int main(void) {
    int x = 5;
    incrementa(x);
    printf("%d\n", x); // imprime 5, não 6
    return 0;
}
```

### Escopo

* **Variáveis Locais:** Declaradas dentro de funções, só existem durante a execução da função.

```c
void funcao() {
    int local = 10; // variável local, só existe dentro de funcao()
}
```

* **Variáveis Globais:** Declaradas fora de todas as funções, podem ser acessadas por qualquer função. Devem ser usadas com moderação para evitar dependências e efeitos colaterais indesejados. Use escopo global apenas com constantes.

```c
const int GLOBAL_VALUE = 20; // variável global, pode ser acessada por todas as funções
```

* **Parâmetros formais:** Variáveis declaradas na definição da função, recebem os valores dos argumentos passados na chamada.

```c
void funcao(int parametro) {
    // parametro é uma variável local que recebe o valor do argumento
}
```

### Passagem por Referência (Ponteiros)

* `&` → endereço de uma variável
* `*` → conteúdo apontado por um ponteiro

```c
troca(int *a, int *b) {
    int temp = *a; // guarda o valor apontado por a
    *a = *b;       // atribui o valor apontado por b para a
    *b = temp;     // atribui o valor guardado em temp para b
}

void incrementa(int *n) {
    (*n)++; // incrementa o valor apontado por n
}

int main(void) {
    int x = 5, y = 10;
    troca(&x, &y); // passa os endereços de x e y
    printf("x: %d, y: %d\n", x, y); // imprime x: 10, y: 5

    int z = 7;
    incrementa(&z); // passa o endereço de z
    printf("%d\n", z); // imprime 8
    return 0;
}
```

### Arrays

Vetores:

```c
void imprime_vetor(int vetor[], int size) {...}
void imprime_vetor(int vetor[n], int size) {...}
void imprime_vetor(int *vetor, int size) {...}
```

Matrizes:

```c
void imprime_matriz(int m[][4], int row, int col) {...}
void imprime_matriz(int m[3][4], int row, int col) {...}
void imprime_matriz(int (*m)[4], int row, int col) {...}
void imprime_matriz(int **m, int row, int col) {...}
```

### Struct

Valor:

```c
void imprime_ponto(ponto_t p) {
    printf("Ponto: (%.2f, %.2f)\n", p.x, p.y);
}

int main(void) {
    ponto_t p1 = {10.0, 20.0};
    imprime_ponto(p1); // passa a struct por valor
    return 0;
}
```

Referência:

```c
void imprime_ponto(ponto_t *p) {
    printf("Ponto: (%.2f, %.2f)\n", p->x, (*p).y );
}

int main(void) {
    ponto_t p1 = {10.0, 20.0};
    imprime_ponto(&p1); // passa o endereço da struct
    return 0;
}
```

---

## Arquivos

### Introdução

```c
#include <stdio.h>
#include <stdlib.h> // necessário para exit() e system("pause")

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Erro: nome do arquivo não fornecido.\n");
        system("pause"); // pausa a execução (Windows): 
        // Pressione qualquer tecla para continuar...
        exit(1); // encerra o programa com código de erro
    }
    return 0; // mesmo que exit(0) ou return EXIT_SUCCESS;
}
```

`argc`: número de argumentos passados na linha de comando (incluindo o nome do programa). <br>
`argv`: array de strings (char*) contendo os argumentos, argv[0] é o nome do programa executável. **argv é o mesmo que *argv[]

### Tipos de Arquivos

| Tipo de Arquivo | Descrição                         | Binário ou Texto? |
| ----------------- | ------------------------------------- | -------------------- |
| .txt            | arquivo de texto                    | Texto              |
| .csv            | tabela separada por vírgula`,`     | Texto              |
| .tsv            | tabela separada por tabulação`\t` | Texto              |
| .pdf            | documento portátil                 | Binário           |
| .docx           | arquivo do Word                     | Texto              |
| .out, *, .exe   | executável                         | Binário           |

### Caminhos

**Windows:** `C:\Users\Usuario\Documents\arquivo.txt`

**Linux/Mac/Unix:** `/home/usuario/documentos/arquivo.txt`

**Caminho Absoluto:** Especifica a localização completa do arquivo, começando pela raiz do sistema de arquivos. Ex: `C:\Users\Usuario\Documents\arquivo.txt` ou `/home/usuario/documentos/arquivo.txt`.

**Caminho Relativo:** Especifica a localização do arquivo em relação ao diretório atual do programa. Ex: `./arquivo.txt` (mesmo diretório) ou `../arquivo.txt` (diretório pai).

### Abrindo Arquivos

```c
#include <stdio.h> // necessário para FILE, fopen, fclose etc

FILE *f = fopen(filename, mode);

if (f == NULL) {
    // erro ao abrir o arquivo
}

fclose(f); // fecha o arquivo quando terminar, retorna 0 se sucesso, EOF (-1) se erro
```

**Valores de retorno:** Em caso de sucesso, `fopen()`, `fdopen()` e `freopen()` retornam um ponteiro `FILE`. Caso contrário, `NULL` é retornado e a variável global `errno` é definida para indicar o erro.

**NULL:** É uma macro que representa um ponteiro nulo, ou seja, um ponteiro que não aponta para nenhum endereço válido. É comumente usado para indicar que uma função falhou ou que um ponteiro não foi inicializado.

**EOF:** (End Of File) é uma constante que indica o fim de um arquivo. Geralmente, é definida como `-1`. Quando uma função de leitura atinge o final do arquivo, ela retorna `EOF` para indicar que não há mais dados a serem lidos.

### Arquivos Pré-definidos

| Arquivo   | Descrição |
| --------- | ------------------ |
| `stdin`   | Entrada padrão (teclado) |
| `stdout`  | Saída padrão (tela) |
| `stderr`  | Saída de erro padrão (tela) |
| `stdaux`  | Saída auxiliar (geralmente não usada, porta serial) |
| `stdprn`  | Saída para impressora (geralmente não usada, porta paralela) |

### Funções de abertura

| Função | Descrição |
| --------- | ------------------ |
| `fopen(filename, mode)` | Abre um arquivo com o nome `filename` e o modo de acesso `mode`. Retorna um ponteiro para o arquivo ou NULL em caso de erro. |
| `fdopen(fd, mode)` | Associa um fluxo de arquivo a um descritor de arquivo existente `fd` com o modo de acesso `mode`. Retorna um ponteiro para o arquivo ou NULL em caso de erro. |
| `freopen(filename, mode, stream)` | Reabre o arquivo associado ao fluxo `stream` com o nome `filename` e o modo de acesso `mode`. Retorna um ponteiro para o arquivo ou NULL em caso de erro. |

### Modos de Abertura

| Modo    | Tipo    | Operação                 | Arquivo precisa existir? | Se existir             | Se não existir | Ponto inicial do ponteiro |
| ------- | ------- | ------------------------ | ------------------------ | ---------------------- | -------------- | ------------------------- |
| **r**   | Texto   | Leitura                  | Sim                      | Apenas lê              | Erro (NULL)    | Início (0)                |
| **w**   | Texto   | Escrita                  | Não                      | Apaga e recria         | Cria novo      | Início (0)                |
| **a**   | Texto   | Escrita (append)         | Não                      | Escreve no final       | Cria novo      | Fim (EOF)                 |
| **r+**  | Texto   | Leitura/Escrita          | Sim                      | Lê e escreve           | Erro (NULL)    | Início (0)                |
| **w+**  | Texto   | Leitura/Escrita          | Não                      | Apaga e recria         | Cria novo      | Início (0)                |
| **a+**  | Texto   | Leitura/Escrita (append) | Não                      | Lê, e escreve no final | Cria novo      | Fim (EOF)                 |
| **rb**  | Binário | Leitura                  | Sim                      | Apenas lê              | Erro (NULL)    | Início (0)                |
| **wb**  | Binário | Escrita                  | Não                      | Apaga e recria         | Cria novo      | Início (0)                |
| **ab**  | Binário | Escrita (append)         | Não                      | Escreve no final       | Cria novo      | Fim (EOF)                 |
| **r+b** | Binário | Leitura/Escrita          | Sim                      | Lê e escreve           | Erro (NULL)    | Início (0)                |
| **w+b** | Binário | Leitura/Escrita          | Não                      | Apaga e recria         | Cria novo      | Início (0)                |
| **a+b** | Binário | Leitura/Escrita (append) | Não                      | Lê, e escreve no final | Cria novo      | Fim (EOF)                 |

**Resumo:** r = read, w = write, a = append, + = leitura e escrita, b = binário

### Funções de Leitura e Escrita

| Função                   | Descrição                            | 
| ------------------------ | ------------------------------------ | 
| `scanf(...)`             | Lê da entrada padrão (teclado)       |
| `getc(...)`              | Lê um caractere da entrada padrão    |
| `gets(...)`              | Lê uma string* da entrada padrão (insegura) |
| `putc(...)`              | Escreve um caractere na saída padrão |
| `puts(...)`              | Escreve uma string na saída padrão   |
| `printf(...)`            | Escreve formatado na saída padrão    | 
| `fscanf(arquivo, ...)`   | Lê de um arquivo (não retorna EOF)   |
| `fgetc(arquivo)`         | Lê um caractere de um arquivo (retorna EOF) |
| `fgets(str, tamanho, arquivo)`    | Lê uma string de um arquivo (segura) |
| `fputc(char, arquivo)`    | Escreve um caractere em um arquivo   |
| `fputs(str, arquivo)`    | Escreve uma string em um arquivo     |
| `fprintf(arquivo, ...)`  | Escreve formatado em um arquivo      |

### Outras Funções

| Função                     | Descrição                                      |
| -------------------------- | ---------------------------------------------- |
| `feof(arquivo)`            | Verifica se chegou ao fim do arquivo           |
| `ferror(arquivo)`          | Verifica se ocorreu um erro no arquivo         |
| `fclose(arquivo)`          | Fecha um arquivo aberto                        |
| `fflush(arquivo)`          | Limpa o buffer de um arquivo                   |
| `ftell(arquivo)`           | Retorna a posição atual do ponteiro do arquivo |
| `rewind(arquivo)`          | Move o ponteiro do arquivo para o início       |
| `remove(filename)`         | Exclui um arquivo do sistema (pelo nome do arquivo), retorna 0 se sucesso |
| `rename(oldname, newname)` | Renomeia um arquivo no sistema                 | 
| `tmpfile()`                | Cria um arquivo temporário no sistema          |
| `exit(codigo_de_retorno)`  | Encerra o programa com um código de status: 0 para sucesso, diferente de 0 para erro (stdlib.h) |

### Blocos de Dados

**`fread(buffer, size, count, arquivo)`:** Lê um bloco de dados de um arquivo para um buffer
```c
FILE *arquivo = fopen("dados.bin", "rb"); // abre um arquivo binário para leitura
char str1[20], str2[20];
float x;
int v[2];

// lê a string toda do arquivo
fread(str1, sizeof(char), 12, arquivo);
str1[12] = '\0'; // adiciona o terminador de string

// lê os 5 primeiros caracteres da string do arquivo
fread(str2, sizeof(char), 5, arquivo);
str2[5] = '\0'; // adiciona o terminador de string

// lê o valor de x do arquivo
fread(&x, sizeof(float), 1, arquivo);

// lê os 2 elementos do vetor v do arquivo
fread(v, sizeof(int), 2, arquivo);
```

**`fwrite(buffer, size, count, arquivo)`:**  Escreve um bloco de dados de um buffer para um arquivo
```c
FILE *arquivo = fopen("dados.bin", "wb"); // abre um arquivo binário para escrita
char str[20] = "Hello World";
float x = 3.14;
int v[5] = {1, 2, 3, 4, 5};

// grava a string toda no arquivo
fwrite(str, sizeof(char), strlen(str), arquivo); 

// grava apenas os 5 primeiros caracteres da string no arquivo
fwrite(str, sizeof(char), 5, arquivo); 

// grava o valor de x no arquivo
fwrite(&x, sizeof(float), 1, arquivo); 

// grava os 2 primeiros elementos do vetor v no arquivo
fwrite(v, sizeof(int), 2, arquivo); 
```

**`fseek(arquivo, offset, origem)`:** Move o ponteiro do arquivo para uma posição específica, devolve 0 quando sucesso. Necessário `#include <stdio.h>`: Biblioteca padrão de entrada e saída, que inclui as funções de manipulação de arquivos.
```c
fseek(arquivo, 0, SEEK_SET); // move para o início do arquivo
fseek(arquivo, 10, SEEK_CUR); // move 10 bytes a partir da posição atual
fseek(arquivo, -20, SEEK_END); // move 20 bytes antes do final do arquivo
```

---