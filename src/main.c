#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    Processo p1, p2, p3;
    createProcess(&p1);
    //imprimeProcesso(&p2);


    int N = 5;
    Lista *lista = criar_lista(N);

    lista = insere_no_inicio(lista, &p1);

    imprimir(lista);
    return 0;


    //ler N
    //ler NOL numero de linhas de operacoes
    //Op 0 para insercao e 1 para remocao INICIO
    //Qt quantidade de vezes que a operacao sera realizada
}