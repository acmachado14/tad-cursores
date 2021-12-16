#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

//Inicializar a lista e aloca a memória no HEAP
void criar_lista(Lista **lista,int tamanho){
  (*lista) = (Lista*) malloc(sizeof(Lista));
  Celula *v = (Celula*) malloc(tamanho * sizeof(Celula));
  (*lista) -> vetor = v;
  (*lista) -> vazia = true;
  (*lista) -> posicao = 0;
  (*lista) -> tam = 0;
}

void insere_no_inicio(Lista **lista, Processo *processo){
  /*for (int i = 0; i < 10; i++){
    printf("teste");
    printf("\n");
  }*/
  Celula *cel;
  cel->processo = processo;
  if ((*lista)->vazia == true){
    cel->ant = -1;
    cel->prox = -1;
    (*lista)->vetor[(*lista)->posicao] = *cel;
    (*lista)->vazia = false;
    (*lista)->ultimo = (*lista)->posicao;
    (*lista)->primeiro = (*lista)->posicao;
  }else{
    cel->ant = (*lista)->posicao;
    cel->prox = -1;
    (*lista)->vetor[(*lista)->posicao] = *cel;
    (*lista)->ultimo = (*lista)->posicao;
  }
  (*lista)->posicao++;
  (*lista)->tam++;
  puts("");
}
      // Código para ordenação do vetor (Não testado) Erro ao definir função na lista.h
void ordena(int *vetor, int *tam){
  
  int primeiro, j, menor, troca;
  for (primeiro = 0; primeiro < tam-1; primeiro++){
    menor = primeiro;
    for (j = primeiro+1; j < tam-1 ; j++){
      if(vetor[j] < vetor[menor]){
        menor = j;
      }
    if (primeiro != menor){
      troca = vetor[primeiro];
      vetor[primeiro] = vetor[menor];
      vetor[menor] = troca;
    }
    }
  }
}

//Imprimir
void imprimir(Lista **lista){

  for (int i = 0; i < (*lista)->posicao; i++){
    imprimeProcesso((*lista)-> vetor[i].processo);
  }

  printf("\n");
}

int celulas_ocupadas(Lista **lista){
  return (*lista)->posicao;
}


//Remove inicio
void remove_primeiro(Lista **lista){
  Celula *cel;
  cel = NULL;
  //(*lista) -> vetor[(*lista) -> primeiro] = cel;
  (*lista) -> tam--;
}


/*
//Verifica se a lista está vazia
bool verifica_lista_vazia(Lista *lista){
  return (lista -> tam == 0);
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