/**
 * Descripcion: Implementation of time measurement functions
 * Fichero: sorting.h
 * Autor: Miguel Paterson & María Silva 
 * Version: 1.0
 * Fecha: 25-20-2023
 */

#ifndef SORTING_H
#define SORTING_H

#include "permutations.h"

/* constants */

#ifndef ERR
  #define ERR -1
  #define OK (!(ERR))
#endif

/* type definitions */
typedef int (* pfunc_sort)(int*, int, int);

/* Functions */

int SelectSort(int* array, int ip, int iu);
int SelectSortInv(int* array, int ip, int iu);
int min(int* array, int ip, int iu);
int mergesort(int* tabla, int ip, int iu);
int merge(int* tabla, int ip, int iu, int imedio);
int quicksort(int* tabla, int ip, int iu) ;
int partition(int* tabla, int ip, int iu,int *pos);
int median(int *tabla, int ip, int iu,int *pos); 
int median_avg(int *tabla, int ip, int iu, int *pos);
int median_stat(int *tabla, int ip, int iu, int *pos);



#endif
