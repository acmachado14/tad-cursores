#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

//Inicializar a lista
Lista *criar_lista(){
  Lista *lista = (Lista*) malloc(sizeof(Lista));

  lista -> tam = 0;
  lista -> inicio = NULL;

  return lista;
}

/*
//Inserir no inicio
void inseri_no_inicio(Lista *lista, Processo processo){
  Celula *celula = (Celula*) malloc(sizeof(Celula));

  celula -> processo = processo;
  celula -> prox = lista -> inicio;
  celula -> ant = NULL;
  lista -> inicio = celula;
  lista -> tam++;
}
*/

//Imprimir
void imprimir(Lista *lista){
  if(verifica_lista_vazia (lista)){
    printf("Lista vazia\n");
    return;
  }

  Celula *apontador = lista -> inicio;

  while (apontador != NULL){
    printf("%d", apontador -> processo.pid);
    apontador = apontador -> prox;
  }

  printf("\n");
}

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
}