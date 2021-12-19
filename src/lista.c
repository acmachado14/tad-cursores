#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

//Inicializar a lista
void criar_lista(Lista **lista,int tamanho){
  (*lista) = (Lista*) malloc(sizeof(Lista));
  Celula *v = (Celula*) malloc(tamanho * sizeof(Celula));

  Celula *cel = (Celula*) malloc(sizeof(Celula));
  for (int i = 0; i < tamanho; i++){
    cel->ant = -1;
    cel->prox = -1;
    cel->posicaoVazia = 0;
    v[i] = *cel;
  }

  (*lista) -> vetor = v;
  (*lista) -> vazia = true;
  (*lista) -> tam = tamanho;

}

//inserir ordenado (com cursor) na proxima posicao vazia
void insere_no_inicio(Lista **lista, Processo processo){

  Celula *cel = (Celula*) malloc(sizeof(Celula));
  cel->processo = processo;
  cel->ant = -1;
  cel->prox = -1;

  int posicaoDoUltimo = (*lista)->ultimo;
  int posicaoDoPrimeiro = (*lista)->primeiro;

  //verificar se lista esta vazia
  if ( (*lista)->vazia == true){
    (*lista)->vetor[0] = *cel;
    (*lista)->primeiro = 0;
    (*lista)->ultimo = 0;
    (*lista)->vetor[0].posicaoVazia = 1; //posicao do vetor nao esta mais vazia
    (*lista)->vazia = false; //lista nao esta mais vazia
  }else{
    //verificar se vai ser o ultimo
    if (processo.pid >= (*lista)->vetor[posicaoDoUltimo].processo.pid){ //entao é o maior

      for (int i = 0; i < (*lista)->tam; i++){
        if ((*lista)->vetor[i].posicaoVazia == 0){

          cel->ant = posicaoDoUltimo;
          cel->prox = -1;
          cel->posicaoVazia = 1;

          (*lista)->vetor[posicaoDoUltimo].prox = i;
          (*lista)->ultimo = i;
          (*lista)->vetor[i] = *cel;

          break;
        }
      }
    //verificar se vai ser o primeiro
    }else if (processo.pid <= (*lista)->vetor[posicaoDoPrimeiro].processo.pid){ //entao é o menor

      for (int i = 0; i < (*lista)->tam; i++){
        if ((*lista)->vetor[i].posicaoVazia == 0){

          cel->ant = -1;
          cel->prox = posicaoDoPrimeiro;
          cel->posicaoVazia = 1;

          (*lista)->vetor[posicaoDoPrimeiro].ant = i;
          (*lista)->primeiro = i;
          (*lista)->vetor[i] = *cel;
          break;
        }
      }
    }
  }

  if((*lista)->vazia == false){
    if (processo.pid < (*lista)->vetor[(*lista)->ultimo].processo.pid){
      if (processo.pid > (*lista)->vetor[(*lista)->primeiro].processo.pid){
        int c;
        for (int i = 0; i < (*lista)->tam; i++){
          if ((*lista)->vetor[i].posicaoVazia == 1){
            int anterior = (*lista)->vetor[i].ant;
            if ((processo.pid <= (*lista)->vetor[i].processo.pid) && (processo.pid >= (*lista)->vetor[anterior].processo.pid)){
              for (int j = 0; j < (*lista)->tam; j++){
                if ((*lista)->vetor[j].posicaoVazia == 0){

                  cel->posicaoVazia = 1; // coloca a posicao como preenchida

                  c = (*lista)->vetor[i].ant; // pegando a posicao de $c (proximo de $b)

                  (*lista)->vetor[i].ant = j; //anterior de $b recebe $a

                  cel->prox = i; // proximo de $a recebe $b

                  (*lista)->vetor[c].prox = j; //proximo de $c recebe $a

                  cel->ant = c; //anterior de $a recebe $b

                  (*lista)->vetor[j] = *cel; // insere no vetor

                  return;
                }
              }
            }
          }
        }
      }
    }
  }
  //Verificar se esta cheia nao precisa fazer pois o codigo vai inserir somente se existir uma posicao vazia no vetor
  //se nao existir ele nem insere!!

}


//Imprimir ordenando com cursores
void imprimir(Lista **lista){
  int posicao = (*lista)->primeiro;

  if ((*lista)->vazia == false){
    while (true){
      imprimeProcesso(&((*lista)-> vetor[posicao].processo));
      posicao = (*lista)-> vetor[posicao].prox;
      if (posicao == -1){
        break;
      }
    }
  }

  printf("\n");
}

//Celulas ocupadas
int celulas_ocupadas(Lista **lista){
  int cont = 0;
  for (int i = 0; i < (*lista)->tam; i++){
    if ((*lista)->vetor[i].posicaoVazia == 1){
      cont++;
    }
  }
  return cont;
}


//Remove no inicio
void remove_primeiro(Lista **lista){
  if ((*lista)->vazia == true){
    return;
  }
  // setando a primeira posicao como vazia
  (*lista)->vetor[(*lista)->primeiro].posicaoVazia = 0;

  // o cursor anterior da proxima celula agora aponta pra -1
  (*lista)->vetor[(*lista)->vetor[(*lista)->primeiro].prox].ant = -1;

  // primeiro agora é proxima celula
  (*lista)->primeiro = (*lista)->vetor[(*lista)->primeiro].prox;

  // verificar se apos a remocao a lista ficou vazia
  int cont = 0;
  for (int i = 0; i < (*lista)->tam; i++){
    if ((*lista)->vetor[i].posicaoVazia == 1){
      cont++;
    }
  }

  if (cont == 0){
    (*lista)->vazia = true;
  }

}


