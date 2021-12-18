#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    Processo p1;
    Processo p2;
    Processo p3;
    Processo p4;
    Processo p5;
    Processo p6;
    Processo p7;

    createProcess(&p1, 5);

    createProcess(&p2, 89);

    createProcess(&p3, 2);

    createProcess(&p4, 50);

    createProcess(&p5, 15);

    createProcess(&p6, 7);

    createProcess(&p7, 90);

    int N = 10, linhas;
    Lista *lista;
    criar_lista(&lista,N);


    insere_no_inicio(&lista, &p1);
    insere_no_inicio(&lista, &p2);
    insere_no_inicio(&lista, &p3);
    insere_no_inicio(&lista, &p4);
    insere_no_inicio(&lista, &p5);
    insere_no_inicio(&lista, &p6);
    insere_no_inicio(&lista, &p7);

    remove_primeiro(&lista);
    imprimir(&lista);
    puts("----------------------------------------------------------------");
    printf("Numero de celulas ocupadas: %d",celulas_ocupadas(&lista));

    insere_no_inicio(&lista, &p3);

    imprimir(&lista);
    puts("----------------------------------------------------------------");
    printf("Numero de celulas ocupadas: %d",celulas_ocupadas(&lista));




/*

    //ler N
    //ler NOL numero de linhas de operacoes
    //Op 0 para insercao e 1 para remocao INICIO
    //Qt quantidade de vezes que a operacao sera realizada


    scanf("%d", N); //tamanho
    scanf("%d", NOL); //numero de linhas

    int j = 0, Op, Qt;
    while ( j < NOL ){
        scanf("%d %d", Op, Qt);
        if(Op == 0){ //insercao
            for (int i = 0; i < Qt; i ++){
                //insere_no_inicio(&lista, &p3);
            }
        }else{ //remocao
            for (int i = 0; i < Qt; i ++){
                //remove_inicio(&lista);
            }
        }
        j++;
    }
*/

    return 0;



}