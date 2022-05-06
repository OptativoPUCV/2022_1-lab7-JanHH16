//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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq)
{
    if(pq->size != 0)
      return pq->heapArray[0].data;
    else return NULL;
}



void heap_push(Heap* pq, void* data, int priority)
{
  //Comprobar tamaño arreglo
  int indice;
  indice = pq->capac;
  if(pq->capac == (pq->size)-1)
  {
    pq = realloc(pq,(indice*2)+1);
  }
  //Insertar
  while(1)
  {   
    indice = pq->size;
    pq->heapArray[indice].data = data;
    pq->heapArray[indice].priority = priority;
    int padre;
    padre = (indice-1)/2;
    if(pq->heapArray[indice].priority > pq->heapArray[padre].priority)
    {
      Heap *auxPQ = malloc(sizeof(Heap));
      auxPQ->heapArray[0].data = pq->heapArray[padre].data;
      auxPQ->heapArray[0].priority = pq->heapArray[padre].priority;
      pq->heapArray[padre].data = pq->heapArray[indice].data;
      pq->heapArray[padre].priority = pq->heapArray[indice].priority;
      pq->heapArray[indice].data = auxPQ->heapArray[0].data;
      pq->heapArray[indice].priority = auxPQ->heapArray[0].priority;
      pq->size = pq->size +1;
      padre=(padre-1)/2;
    }
    else break;
  }
}


void heap_pop(Heap* pq)
{

}

Heap* createHeap(){
  Heap *monticulo = (Heap*) malloc(sizeof(Heap));
  monticulo -> heapArray = malloc(3*sizeof(heapElem));
  monticulo -> capac = 3;
  
   return monticulo;
}
