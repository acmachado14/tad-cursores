#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    int pid;
    int prioridade;
    double horas; //horas podem ser do tipo char, avaliar possibilidade!
} Processo;

Processo createProcess(int *pid, int *prioridade, double *horas);

void imprimeProcesso(Processo *processo);

void setPid(Processo *processo, int *pid);

int* getPid(Processo *processo);

void setPrioridade(Processo *processo, int *prioridade);

int* getPrioridade(Processo *processo);

void setHoras(Processo *processo, double *horas);

double* getHoras(Processo *processo);