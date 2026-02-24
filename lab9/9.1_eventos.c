#include <stdio.h>

typedef enum month_e{
    Janeiro = 1,
    Fevereiro,
    Marco,
    Abril,
    Maio,
    Junho,
    Julho,
    Agosto,
    Setembro,
    Outubro,
    Novembro,
    Dezembro
} Month;

typedef struct data_t{
    int dia;
    Month mes;
    int ano;
} Data;

typedef char String[100];

typedef struct evento_t{
    String nome;
    String local;
    Data data;
} Evento;

void cadastrar_eventos(Evento agenda[], int n);
void imprimir_eventos(Evento agenda[], Data d, int n);

int main(){
    
    int qtde_eventos;
    scanf("%d", &qtde_eventos);
    Evento eventos[qtde_eventos];
    cadastrar_eventos(eventos, qtde_eventos);

    Data data_pesquisa;
    scanf("%d %d %d", &(data_pesquisa.dia), (int*)&(data_pesquisa.mes), &(data_pesquisa.ano));
    imprimir_eventos(eventos, data_pesquisa, qtde_eventos);

    return 0;
}

void cadastrar_eventos(Evento agenda[], int n){
    for(int i=0; i<n; i++){
        Evento event;
        scanf("%s %s %d %d %d", event.nome, event.local, 
            &(event.data.dia), (int*)&(event.data.mes), &(event.data.ano));
        agenda[i] = event;
    }
}

void imprimir_eventos(Evento agenda[], Data d, int n){
    for(int i=0; i<n; i++){
        Evento event = agenda[i];
        if(event.data.dia == d.dia && event.data.mes == d.mes && event.data.ano == d.ano)
            printf("%s %s\n", event.nome, event.local);
    }
}