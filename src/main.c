#include "lista.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    Processo p1;
    createProcess(&p1);
    imprimeProcesso(&p1);

    Lista *lista = criar_lista();
    imprimir(lista);
    celulas_ocupadas(lista);
    return 0;
}