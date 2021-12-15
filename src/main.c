#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    Processo p1;
    Processo p2;
    Processo p3;

    createProcess(&p1);

    createProcess(&p2);

    createProcess(&p3);

    int N = 5, linhas;
    Lista *lista;
    criar_lista(&lista,N);


    insere_no_inicio(&lista, &p1);
    insere_no_inicio(&lista, &p2);
    insere_no_inicio(&lista, &p3);

    for (int i = 0; i < 3; i++){
        imprimir(&lista,i);
    }


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