#include "processo.h"
#include <time.h>

//Cria o processo
void createProcess(Processo *processo, int pid, int prioridade, char hora[16]){
    setPid(processo, pid);
    setPrioridade(processo, prioridade);
    setHoras(processo, hora);
}

//Imprime processo
void imprimeProcesso(Processo *processo) {
    printf("\nProcesso:\n");
    printf(" -> PID: %d\n", getPid(processo));
    printf(" -> Prioridade: %d\n", getPrioridade(processo));
    printf(" -> Horario da criacao: %s\n", getHoras(processo));
}

//gera e seta um numero aleatorio de 0 a 1000
void setPid(Processo *processo, int pid) {
    processo->pid = pid;
}

//devolve PID
int getPid(Processo *processo) {
    return processo->pid;
}

//seta prioridade
void setPrioridade(Processo *processo, int prioridade) {
    processo->prioridade = prioridade;
}

//devolve prioridade
int getPrioridade(Processo *processo) {
    return processo->prioridade;
}

//seta hora
void setHoras(Processo *processo, char hora[16]) {
    strcpy(processo->horas, hora);
}

//devolve hora
char* getHoras(Processo *processo) {
    return processo->horas;
}
