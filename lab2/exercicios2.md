**2.1) Série**

Implemente um programa que imprima todos os termos da série dado n, e os termos x0 e
x1. Os outros termos da série serão:

`xn = 4\*xn-1 -2\*xn-2`

O primeiro valor é referente à variável n, ou seja, o valor de termos da série, seguida de
(X0) e (X1). O programa deve imprimir o valor de cada termo até o enésimo termo. No
exemplo abaixo, com o valor de n=4, x0=3 e x1=4, o programa deve imprimir o valor de
x0, x1, x2, x3 e x4. 

| Entrada | Saída|
|:-:|:-|
| 4 <br> 3 <br> 4 | X0: 3 <br> X1: 4 <br> X2: 10 <br> X3: 32 <br> X4: 108  |
<hr>

**2.2) Pi**

Aproxime o valor de Pi empregando a série infinita de Gregory-Leibniz:

`Pi = 4 - 4/3 + 4/5 - 4/7 + ...`

Executando a série acima, a sua função deve retornar o número de iterações necessárias
para encontrar um valor próximo ao valor de `M_PI` (uma constante com o valor de PI da
biblioteca `math.h`) com uma diferença máxima de X, que é fornecida como entrada. No
exemplo abaixo: foi necessário calcular 100002 termos da série para obter um valor
próximo ao valor de PI (`M_PI`) com uma diferença de 0.000010.

| Entrada | Saída |
|:-:|:-:|
| 0.000010 | 100001  |
<hr>

**2.3) Contagem**

Faça um programa que mostre uma contagem na tela de 233 a 457, só que contando de 3
em 3 quando estiver entre 300 e 400 e de 5 em 5 quando não estiver. (utilize `do{}while()`) 

| Entrada | Saída |
|:-:|:-:|
|  | ...<br>457  |
<hr>

**2.4) Múltiplos**
Faça um programa que compute quantos são os múltiplos de 2, de 3 e de 5 entre 1 e X ;
compute também quantos são os números múltiplos de 2, 3 e 5 ao mesmo tempo.
(utilize `while()`)

É fornecido o valor de X onde deve ser impresso a quantidade de múltiplos conforme
abaixo. 

| Entrada | Saída |
|:-:|:-|
| 1000 | Múltiplos de 2: 500 <br> Múltiplos de 3: 333 <br> Múltiplos de 5: 200 <br> Múltiplos de todos: 33  |
| 500 | Múltiplos de 2: 250 <br> Múltiplos de 3: 166 <br> Múltiplos de 5: 100 <br> Múltiplos de todos: 16 |
<hr>

**2.5) Soma**
Faça um programa que pegue um número do teclado e calcule a soma de todos os números
de 1 até ele (use laço `for()`). Ex.: o usuário entra 7, o programa vai mostrar 28, pois
1+2+3+4+5+6+7=28. 

| Entrada | Saída |
|:-:|:-:|
| 7 | 28|
