#include "processo.h"

Processo createProcess(int *pid, int *prioridade, double *horas){
    Processo processo;
    setPid(&processo, pid);
    setPrioridade(&processo, prioridade);
    setHoras(&processo, horas);
    return processo;
}

void imprimeProcesso(Processo *processo) {
    printf("\nProcesso:\n");
    printf(" -> PID: %s\n", getPid(processo));
    printf(" -> Prioridade: %s\n", getPrioridade(processo));
    printf(" -> Horário da criação: %s\n", getHoras(processo));
}

void setPid(Processo *processo, int *pid) {
    processo->pid = pid;
}

int* getPid(Processo *processo) {
    return processo->pid;
}

void setPrioridade(Processo *processo, char *prioridade) {
    processo->prioridade = prioridade;
}

int* getPrioridade(Processo *processo) {
    return processo->prioridade;
}

void setHoras(Processo *processo, double *horas) {
    processo->horas = horas;
}

double* getHoras(Processo *processo) {
    return processo->horas;
}
