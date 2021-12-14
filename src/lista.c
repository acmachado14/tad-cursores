#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

//Inicializar a lista
Lista* criar_lista(int tamanho){
  Celula *v = (Celula*) malloc(tamanho * sizeof(Celula));
  Lista *lista;
  lista -> vetor = v;
  lista -> vazia = true;
  return lista;
}

Lista* insere_no_inicio(Lista *lista, Processo *processo){

  Celula *cel;
  cel->processo = processo;
  if (lista->vazia == true){
    cel->ant = -1;
    cel->prox = -1;
    lista->posicao = 0;
    lista->vetor[lista->posicao] = *cel;
    lista->vazia = false;
    puts("Sal");
  }else{
    cel->ant = lista->posicao;
    cel->prox = -1;
    lista->posicao++;
    lista->vetor[lista->posicao] = *cel;
    puts("Sal");
  }
  puts("Sal");
  return lista;
}


//Imprimir
void imprimir(Lista *lista){

  for (int i =0; i < lista->posicao +1; i++){
    Celula *cel;
    *cel = lista -> vetor[i];
    Processo *pro = cel->processo;
    imprimeProcesso(pro);
  }
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