#include "processo.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
    Processo p1;
    createProcess(&p1);
    imprimeProcesso(&p1);
    return 0;
}