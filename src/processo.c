#include "processo.h"
#include <time.h>

void createProcess(Processo *processo, int num){
    //processo->pid = num;
    setPid(processo);
    setPrioridade(processo);
    setHoras(processo);
}

void imprimeProcesso(Processo *processo) {
    printf("\nProcesso:\n");
    printf(" -> PID: %d\n", getPid(processo));
    printf(" -> Prioridade: %d\n", getPrioridade(processo));
    printf(" -> Horario da criacao: %s\n", getHoras(processo));
}

//gera e seta um numero aleatorio de 0 a 1000
void setPid(Processo *processo) {
    processo->pid = (rand() % 1000);
}

int getPid(Processo *processo) {
    return processo->pid;
}

//gera um numero aleatorio de 0 a 5
void setPrioridade(Processo *processo) {
    processo->prioridade = ((rand() % 5) + (1));
}

int getPrioridade(Processo *processo) {
    return processo->prioridade;
}

//pega a hora atual
void setHoras(Processo *processo) {
    time_t my_time;
    struct tm * timeinfo;
    time (&my_time);
    timeinfo = localtime (&my_time);
    float hora = timeinfo->tm_hour;
    float minutos = timeinfo->tm_min;
    char convertido[16];

    sprintf(convertido, "%d%s%d", timeinfo->tm_hour,":",timeinfo->tm_min);

    strcpy(processo->horas, convertido);
}

char* getHoras(Processo *processo) {
    return processo->horas;
}
