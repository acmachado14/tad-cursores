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

    int N = 5;
    Lista *lista;
    criar_lista(&lista,N);


    insere_no_inicio(&lista, &p1);
    insere_no_inicio(&lista, &p2);
    insere_no_inicio(&lista, &p3);

    for (int i = 0; i < 3; i++){
        imprimir(&lista,i);
    }

    return 0;


    //ler N
    //ler NOL numero de linhas de operacoes
    //Op 0 para insercao e 1 para remocao INICIO
    //Qt quantidade de vezes que a operacao sera realizada
}