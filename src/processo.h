#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int pid;
    int prioridade;
    char horas[5];
} Processo;

void createProcess(Processo *processo, int PID, int prioridade, char hora[16]);

void imprimeProcesso(Processo *processo);

void setPid(Processo *processo, int pid);

int getPid(Processo *processo);

void setPrioridade(Processo *processo, int prioridade);

int getPrioridade(Processo *processo);

void setHoras(Processo *processo, char *horas);

char* getHoras(Processo *processo);