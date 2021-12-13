#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "processo.h"

//Struct da Celula -> Para representarmos um Nó da lista
typedef struct Celula{
  Processo processo; //Dado a ser inserido
  struct Celula *prox; //prox será utilizado para armazenar o endereço de memória da próxima celula 
  struct Celula *ant; //ant que será utilizado para armazenar o endereço de memória da celula anterior
} Celula;

//Struct da lista
typedef struct{
    int tam; //Tamanho da lista
    Celula *inicio; //Aponta para o primeiro elemmento da lista
}Lista;


//a) Criar uma área de memória interna vazia. Aloca um vetor de células de tamanho N. Vamos utilizar alocação dinâmica deste vetor, devido aos altos valores de N que adotaremos;
Lista *criar_lista();

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
void imprimir(Lista *lista);

//Verifica se alista estar vazia
bool verifica_lista_vazia(Lista *lista);
