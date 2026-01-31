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

| Tipo        | printf/scanf |
| ------------- | -------------- |
| char        | `%c`         |
| int         | `%d`         |
| short       | `%hd`        |
| long        | `%ld`        |
| unsigned    | `%u`         |
| float       | `%f`         |
| double      | `%lf`        |
| long double | `%Lf`        |
| string      | `%s`         |

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
| `\|\|`   | OR       |
| `!`      | NOT      |

### Operadores Bitwise

| Op   | Significado | Exemplo    |
| ------ | ------------- | ------------ |
| `&`  | AND         | `x & 0x0F` |
| `\|` | OR          | `x \| 0xF0`|
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