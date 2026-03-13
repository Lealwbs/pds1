#include <stdio.h>

void movedisco(int origem, int destino) {
    printf("%d -> %d\n", origem, destino);
}

void movetorre(int altura, int de, int para, int uso){
    if(altura > 0){
        movetorre(altura-1, de, uso, para);
        movedisco(de, para);
        movetorre(altura-1, uso, para, de);
    };
}

int main () {
    int n;
    printf("Entre com o numero de discos: ");
    scanf("%d", &n);
    movetorre(n, 1, 3, 2);
    return 0;
}