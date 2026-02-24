#include <stdio.h>
#include <math.h>

typedef struct iris_t{
    float sepala_comp;
    float sepala_larg;
    float petala_comp;
    float petala_larg;
    char tipo[50];
} Iris;

void classificar(Iris nao_identificada, Iris registros_identificados[], int n);
float get_euclidian_distance(Iris a, Iris b);

int main(){
    int qtde_registros;
    scanf("%d", &qtde_registros);

    Iris unknown, registros[qtde_registros];
    for(int i=0; i<qtde_registros; i++){
        Iris iris;
        scanf("%f %f %f %f %s", &iris.sepala_comp, &iris.sepala_larg,
            &iris.petala_comp, &iris.petala_larg, iris.tipo);
        registros[i] = iris;
    }

    scanf("%f %f %f %f", &unknown.sepala_comp, &unknown.sepala_larg,
        &unknown.petala_comp, &unknown.petala_larg);
    
    classificar(unknown, registros, qtde_registros);

    return 0;
}

void classificar(Iris nao_identificada, Iris registros_identificados[], int n){
    int index_menor_dist = 0;
    float valor_menor_dist = INFINITY;
    for(int i=0; i<n; i++){
        float distance = get_euclidian_distance(nao_identificada, registros_identificados[i]);
        if(distance < valor_menor_dist){
            index_menor_dist = i;
            valor_menor_dist = distance;
        }
    }
    printf("%s", registros_identificados[index_menor_dist].tipo);
}

float get_euclidian_distance(Iris a, Iris b){
    float sum = 0;
    sum += pow(a.sepala_comp - b.sepala_comp, 2);
    sum += pow(a.sepala_larg - b.sepala_larg, 2);
    sum += pow(a.petala_comp - b.petala_comp, 2);
    sum += pow(a.petala_larg - b.petala_larg, 2);
    return sqrt(sum);
}