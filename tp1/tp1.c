#include <stdio.h>
#include <stdbool.h>

void ler_tabuleiro(int size, char tabuleiro[size][size], int* qtde_bombas);
void revelar_casas(int size, char tabuleiro[size][size], int x, int y, int* qtde_casas_reveladas);
bool is_valid_position(int x, int y, int tab_size);

typedef enum{
    BOMBA = 'b',
    LIVRE = 'x',
    LIVRE_REVELADO = 'o'
} status_casa;

typedef enum {
    PERDEU = -1,
    FALTOU = 0,
    GANHOU = +1,
} resultado_t;

int main(){
    int qtde_jogos;
    scanf("%d", &qtde_jogos);

    while(qtde_jogos--){
        int tam_tab, qtde_jogadas, status = FALTOU, c_bomba = 0, c_revelada = 0;
        
        scanf("%d", &tam_tab);
        char tabuleiro[tam_tab][tam_tab];
        ler_tabuleiro(tam_tab, tabuleiro, &c_bomba);
        int c_livre = tam_tab*tam_tab - c_bomba;
        
        scanf("%d", &qtde_jogadas);
        for(int x, y, i=0; i<qtde_jogadas; i++){
            scanf("%d %d", &x, &y);

            if(status == PERDEU) continue;

            switch(tabuleiro[x][y]){
                case BOMBA: status = PERDEU; continue;
                case LIVRE: revelar_casas(tam_tab, tabuleiro, x, y, &c_revelada); continue;
                case LIVRE_REVELADO: continue;
            }
        }

        if(c_revelada == c_livre) 
            status = GANHOU;

        switch(status){
            case PERDEU: printf("PERDEU\n"); break;
            case FALTOU: printf("FALTOU TERMINAR\n"); break;
            case GANHOU: printf("GANHOU\n"); break;
        }
    } 
    return 0;
}

void ler_tabuleiro(int size, char tabuleiro[size][size], int* qtde_bombas){
    for(int i=0; i<size; i++)
        for(int j=0; j<size; j++){
            scanf(" %c", &tabuleiro[i][j]);
            (*qtde_bombas) += (tabuleiro[i][j] == 'b');
        }
}

void revelar_casas(int size, char tabuleiro[size][size], int x, int y, int* qtde_casas_reveladas){
    for(int i=x-1; i<=x+1; i++)
        for(int j=y-1; j<=y+1; j++)
            if(is_valid_position(i, j, size) && tabuleiro[i][j] == 'x'){
                tabuleiro[i][j] = 'o';
                (*qtde_casas_reveladas)++;
            }
}

bool is_valid_position(int x, int y, int tab_size){
    return (0 <= x && x < tab_size) && (0 <= y && y < tab_size);
}

