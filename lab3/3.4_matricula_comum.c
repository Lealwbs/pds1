#include <stdio.h>
#include <stdlib.h>

int main(){
    int qtde_aeds, qtde_calc, *alunos_aeds, *alunos_calc;

    printf("Quantos alunos em AEDS: ");
    scanf("%d", &qtde_aeds);
    alunos_aeds = (int*)malloc(qtde_aeds * sizeof(int));
    for(int i=0; i<qtde_aeds; i++)
    scanf("%d", &alunos_aeds[i]);
    
    printf("Quantos alunos em CALC: ");
    scanf("%d", &qtde_calc);
    alunos_calc = (int*)malloc(qtde_calc * sizeof(int));
    for(int i=0; i<qtde_calc; i++)
    scanf("%d", &alunos_calc[i]);
    
    printf("Alunos em ambas as materias:\n");
    for(int i=0; i<qtde_aeds; i++)
        for(int j=0; j<qtde_calc; j++)
            if(alunos_aeds[i] == alunos_calc[j])
                printf("%d\n", alunos_aeds[i]);

    free(alunos_aeds);
    free(alunos_calc);
    return 0;
}