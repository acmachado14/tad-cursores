#include "lista.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//Cria um processo com valores aleatorios (PID e Prioridade) e Hora atual do computador
Processo aleatorio(char horaAtual[16]){
    Processo processo;
    int pid, prioridade;
    pid = (rand() % 1000); // pegar pid aleatorio
    prioridade = ((rand() % 5) + (1)); //pegar prioridae aleatoria
    createProcess(&processo, pid, prioridade, horaAtual); // construct
    return processo;
}

int main(){
    srand(time(NULL));
    Lista *lista;
    Processo p;

    char horaAtual[16];
    time_t my_time;
    struct tm * timeinfo;
    time (&my_time);
    timeinfo = localtime (&my_time);
    float hora = timeinfo->tm_hour;
    float minutos = timeinfo->tm_min;

    //converte hora pra char
    sprintf(horaAtual, "%d%s%d", timeinfo->tm_hour,":",timeinfo->tm_min);


// ------------------------------------Leitura do Arquivo------------------------------------------
    FILE *fp;
    FILE *fpSaida;
    char* str1 = "../testes/";
    char* str2 = ".txt";
    char* str3 = "_resultado.txt";
    char teste[46];
    char buffer[50];
    char buffer2[50];

    printf("Digite o nome do teste a ser executado na pasta de testes: \n");
    scanf("%s", &teste);

    strcat(strcpy(buffer, str1), teste);

    strcpy(buffer2, buffer);

    strcat(strcpy(buffer, buffer), str2);

    fp = fopen(buffer,"r");

    strcat(strcpy(buffer2, buffer2), str3);

    fpSaida = fopen(buffer2,"w");

    //ler N
    //ler NOL numero de linhas de operacoes
    //Op 0 para insercao e 1 para remocao INICIO
    //Qt quantidade de vezes que a operacao sera realizada

    int j = 0, Op, Qt, NOL, N;

    fscanf(fp,"%d", &N); // tamanho

    fscanf(fp,"%d", &NOL); //numero de linhas
// --------------------------------------------------------------------------------------------

    criar_lista(&lista,N);


// -----------------------------------------Iniciar tempo de execucao-----------------------------------------------
    clock_t start, end;
    double timeUsed;
    start = clock();
// ----------------------------------------------------------------------------------------------------------------
    while ( j < NOL ){
        fscanf(fp,"%d %d", &Op, &Qt);
        if(Op == 0){ //insercao
            for (int i = 0; i < Qt; i ++){
                p = aleatorio(horaAtual);
                insereOrdenado(&lista, p);
            }
        }else{ //remocao
            for (int i = 0; i < Qt; i ++){
                removePrimeiro(&lista);
            }
        }
        j++;
    }

    end = clock();

    imprimir(&lista);

    timeUsed = ((double) (end - start)) / CLOCKS_PER_SEC;

    fclose(fp); //fecha arquivo
    puts("----------------------------------------------------------------");
    printf("Tempo de execucao: %f",timeUsed);
    puts("\n");

    // -----------------------------------------Fechar tempo de execucao-----------------------------------------------

    // -------------------------------------Armazenar dados nos arquivos-----------------------------------------------
    fprintf(fpSaida, "Nome/Numero do teste: %s Tempo de execucao: %f ", teste, timeUsed);
    fclose(fpSaida); //fecha arquivo
    return 0;



}