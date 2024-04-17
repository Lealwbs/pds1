**3.1) Primos num intervalo**

Faça um programa para imprimir todos os números primos num intervalo entre A e B,
sendo A e B números inteiros positivos e menores que 10000. A e B devem ser
fornecidos pelo usuário do seu programa.
A entrada consiste em dois números inteiros que representam o intervalo A e B.


| Entrada | Saída|
|:-:|:-|
| 50 <br> 150 | 53 <br> 59 <br> ... <br> 149  |
<hr>

**3.2) Série e arrays**

A sequência de Fibonacci pode ser definida como:

`fib(0) = 0` <br>
`fib(1) = 1` <br>
`fib(n) = fib(n-1) + fib(n-2), para n>2`

Implemente um programa que calcule a série de Fibonacci para um determinado n
fornecido pelo usuário. Você deve armazenar em um vetor cada elemento da série, de
forma que a posição 0 armazene o termo 0, a posição 1 o termo 1, e assim por diante.
Seu programa deve receber do usuário um número entre 0 e 800 e imprimir o termo
correspondente ao número recebido. O usuário deve ser capaz de entrar com vários
números interativamente em uma mesma execução. O programa termina quando o
usuário entrar com um número negativo ou maior que 800.


| Entrada | Saída |
|:-|:-|
| 5 <br> -1 // valor negativo para finalizar | 5  |
| 0 <br> 2 <br> 6 <br> -1 // valor negativo para finalizar | 0 <br> 1 <br> 8 |
<hr>

**3.3) Ordem inversa**

Faça um programa para ler um vetor X de 10 elementos e gerar um outro vetor com
esses 10 elementos em ordem inversa. Exemplo: Se `X= {3, 5, 2, 8, 4}`, deverá ser
gerado um vetor `Y= {4, 8, 2, 5, 3}`. O valor de n é lido pelo teclado.
Cada posição do vetor deve ser impressa em uma linha através do `“\n”`.

| Entrada | Saída |
|:-:|:-:|
| 1<br>2<br>3<br>4<br>5<br>6<br>7<br>8<br>9<br>10  | 10<br>9<br>8<br>7<br>6<br>5<br>4<br>3<br>2<br>1  |
<hr>

**3.4) Matrícula em comum**
Faça um programa que leia dois vetores de inteiros representando o número de
matrícula de alunos matriculados respectivamente em AEDS 1 e Cálculo 1. Em
seguida, o programa deverá imprimir o número de matrícula dos alunos que estão
matriculados simultaneamente nestas duas disciplinas (ou seja, calcular a interseção
dos dois vetores).
O primeiro valor se refere à quantidade de alunos na disciplina de AEDS 1. Em
seguida, são informadas as matrículas de cada aluno na disciplina. A mesma
sequência é fornecida para a disciplina de Cálculo 1. Por fim, deve-se imprimir a
matrícula dos alunos que estão matriculados em ambas disciplinas.

| Entrada | Saída |
|:-|:-|
| 5 // número de alunos em AEDS 1 <br> 123 <br>321<br>456<br>654<br>888<br>2 //número de alunos em Cálculo 1<br>123<br>321 |  123 <br> 321  |

<hr>

**3.5) Maior da Matriz**
Faça um programa que encontre o maior elemento de uma matriz. Inicialmente é
fornecido o número de linhas e colunas da matriz. Em seguida, os valores de cada
posição da matriz são informados em uma linha separada por espaços simples.

| Entrada | Saída |
|:-|:-:|
| 3 //qtd linhas <br> 4 //qtd colunas <br> 1 1 8 7 <br> 0 8 6 4 <br> 5 5 2 4 | 8 |

**3.6) Matriz Oposta**
Chama-se matriz oposta de A a matriz –A cuja soma com A resulta na matriz nula.
Exemplo: Dada a matriz: A =
| 2 | -3 |
|:-:|:-:|
| -1 | 4 |

A oposta de A será -A =
| -2 | 3 |
|:-:|:-:|
| 1 | -4 |

pois:
A + (-A)=
| 0 | 0 |
|:-:|:-:|
| 0 | 0 |

Faça um programa que receba como entrada os valores de uma matriz n x m e
imprima sua matriz oposta. O formato de entrada é similar ao exercício anterior. Obs:
Para a saída, deve se imprimir os valores separados por um espaço simples

| Entrada | Saída |
|:-|:-:|
| 2 //qtd linhas <br> 2 //qtd colunas <br> 1 1 <br> 1 1 | -1 -1 <br> -1 -1 |
