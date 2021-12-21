#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "processo.h"

typedef struct Celula{
  Processo processo;
  int prox;     //cursor para proximo
  int ant;      //cursor para anterior
  int posicaoVazia; // 0 - vazia | 1 - preenchida
} Celula;

//Struct da lista
typedef struct{
    int tam; //tamanho do vetor
    int primeiro; //aponta pro indice do primeiro termo
    int ultimo; //aponta pro indice do ultimo termo
    bool vazia; //true - esta vazia | false - nao esta vazia
    Celula *vetor; //vetor de celulas
}Lista;


//a) Criar uma área de memória interna vazia. Aloca um vetor de células de tamanho N. Vamos utilizar alocação dinâmica deste vetor, devido aos altos valores de N que adotaremos;
void criar_lista(Lista **lista,int tamanho);

//b) Obter o número de células ocupadas na área de memória. Retorna o número de posições ocupadas no vetor;
int celulasOcupadas(Lista **lista);

//c) Inserir um item de dado na área interna de memória, mantendo os itens ordenados;
void insereOrdenado(Lista **lista, Processo processo);

//d) Retirar o primeiro item da área de memória;
void removePrimeiro(Lista **lista);

//f) Imprimir o conteúdo da área de memória. Somente imprime o conteúdo das células ocupadas.
void imprimir(Lista **lista);

