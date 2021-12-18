#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int pid;
    int prioridade;
    char horas[5];
} Processo;

void createProcess(Processo *processo, int num);

void imprimeProcesso(Processo *processo);

void setPid(Processo *processo);

int getPid(Processo *processo);

void setPrioridade(Processo *processo);

int getPrioridade(Processo *processo);

void setHoras(Processo *processo);

char* getHoras(Processo *processo);