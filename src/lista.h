#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "processo.h"

//Struct da Celula -> Para representarmos um Nó da lista
typedef struct Celula{
  Processo *processo;
  int prox;
  int ant;
} Celula;

//Struct da lista
typedef struct{
    int tam, primeiro, ultimo, posicao;
    bool vazia;
    Celula *vetor;
}Lista;


void insere_no_inicio(Lista **lista, Processo *processo);

//a) Criar uma área de memória interna vazia. Aloca um vetor de células de tamanho N. Vamos utilizar alocação dinâmica deste vetor, devido aos altos valores de N que adotaremos;
void criar_lista(Lista **lista,int tamanho);

//b) Obter o número de células ocupadas na área de memória. Retorna o número de posições ocupadas no vetor;

int *celulas_ocupadas(Lista *lista);

//c) Inserir um item de dado na área interna de memória, mantendo os itens ordenados;
//Insere ordenado
void insere_ordenado(Lista *lista, Processo processo);

/*
//Insere no inicio
void inseri_no_inicio(Lista *lista, Processo processo);
*/

//d) Retirar o primeiro item da área de memória;
void remove_primeiro(Lista *lista);

//f) Imprimir o conteúdo da área de memória. Somente imprime o conteúdo das células ocupadas.
void imprimir(Lista **lista, int pose);

//Verifica se alista estar vazia
bool verifica_lista_vazia(Lista *lista);
