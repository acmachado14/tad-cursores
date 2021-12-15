#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

//Inicializar a lista
void criar_lista(Lista **lista,int tamanho){
  (*lista) = (Lista*) malloc(sizeof(Lista));
  Celula *v = (Celula*) malloc(tamanho * sizeof(Celula));
  (*lista) -> vetor = v;
  (*lista) -> vazia = true;
}

void insere_no_inicio(Lista **lista, Processo *processo){

  Celula *cel;
  cel->processo = processo;
  if ((*lista)->vazia == true){
    cel->ant = -1;
    cel->prox = -1;
    (*lista)->posicao = 0;
    (*lista)->vetor[(*lista)->posicao] = *cel;
    (*lista)->vazia = false;
  }else{
    cel->ant = (*lista)->posicao;
    cel->prox = -1;
    (*lista)->vetor[(*lista)->posicao] = *cel;
  }
  (*lista)->posicao++;
  puts("");
  //printf("%d", (*lista)->vetor[(*lista)->posicao].processo->pid);
}


//Imprimir
void imprimir(Lista **lista, int pose){
  //printf("%d", (*lista)->vetor[0].processo->pid);
  Celula *cel;
  Processo *pro;
  *cel = (*lista)-> vetor[pose];
  pro = cel->processo;
  imprimeProcesso(pro);

  printf("\n");
}


/*
//Verifica se a lista está vazia
bool verifica_lista_vazia(Lista *lista){
  return (lista -> tam == 0);
}

//Remove inicio
void remove_primeiro(Lista *lista){
  if(!verifica_lista_vazia (lista)){
   Celula *apontador = lista -> inicio;

   lista -> inicio = apontador -> prox;
   free (apontador);
   lista -> tam--;
  }
}

//Insere ordenado
void insere_ordenado(Lista *lista, Processo processo){
  Celula *apontador, *celula = (Celula*) malloc(sizeof(Celula));

    celula -> processo = processo;
    if(verifica_lista_vazia (lista)){
      celula -> prox = NULL;
      lista -> inicio = celula;
  }
    else if(celula -> processo.pid < lista -> inicio -> processo.pid){
      celula -> prox = lista -> inicio;
      (lista -> inicio) -> ant = celula;
      lista -> inicio = celula;
    }
    else{
      apontador = lista -> inicio;

      while(apontador -> prox && celula -> processo.pid > apontador -> prox -> processo.pid){
        apontador = apontador -> prox;
      }

      celula -> prox = apontador -> prox;
      apontador -> prox -> ant = celula;
      celula -> ant = apontador;
      apontador -> prox = celula;
    }
    lista -> tam++;
}

//Tamanho da lista
int *celulas_ocupadas(Lista *lista){
  printf("%d", lista -> tam);
}*/