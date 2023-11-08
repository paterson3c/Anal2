/**
 * Descripcion: Implementation of time measurement functions
 * Fichero: sorting.c
 * Autor: Miguel Paterson & María Silva 
 * Version: 1.0
 * Fecha: 25-20-2023
 */

#include <stdio.h>
#include <stdlib.h>
#include "sorting.h"


/***************************************************/
/* Function: SelectSort    Date: 25-20-202         */
/* Authors: Miguel Paterson & María Silva          */
/* Function that implements the selection sort     */
/* algorithm in ascending order.                   */
/* Input:                                          */
/* int *array: An array of integers to sort        */
/* int ip: Initial position in the array           */
/* int iu: Final position in the array             */
/* Output:                                         */
/* int: Number of basic operations executed        */
/* during the sorting process.                     */
/***************************************************/
int SelectSort(int *array, int ip, int iu)
{
  int i, minind, cont = 0;

  for (i = ip; i < iu; i++)
  {
    minind = min(array, i, iu + 1);
    cont += iu - i + 1;
    swap(&array[i], &array[minind]);
  }
  return cont;
}

/***************************************************/
/* Function: SelectSortInv Date: 25-20-202         */
/* Authors: Miguel Paterson & María Silva          */
/*                                                 */
/* Function that implements the selection sort     */
/* algorithm in descending order.                  */
/*                                                 */
/* Input:                                          */
/* int *array: An array of integers to sort        */
/* int ip: Initial position in the array           */
/* int iu: Final position in the array             */
/*                                                 */
/* Output:                                         */
/* int: Number of basic operations executed        */
/* during the sorting process.                     */
/***************************************************/
int SelectSortInv(int *array, int ip, int iu)
{
  int i, minind, cont = 0;

  for (i = iu; i >= ip; i--)
  {
    minind = min(array, ip, i + 1);
    cont += iu - i + 1;
    swap(&array[i], &array[minind]);
  }
  return cont;
}

/***************************************************/
/* Function: min          Date: 25-20-202          */
/* Authors: Miguel Paterson & María Silva          */
/*                                                 */
/* Function that finds the index of the minimum    */
/* element in a subarray.                          */
/*                                                 */
/* Input:                                          */
/* int *array: An array of integers                */
/* int ip: Initial position in the subarray        */
/* int iu: Final position in the subarray          */
/*                                                 */
/* Output:                                         */
/* int: Index of the minimum element               */
/* in the specified subarray.                      */
/***************************************************/
int min(int *array, int ip, int iu)
{
  int i, min, minind;
  min = array[ip];
  minind = ip;
  for (i = ip; i < iu; i++)
  {
    if (min > array[i])
    {
      min = array[i];
      minind = i;
    }
  }
  return minind;
}

/***************************************************/

int mergesort(int* tabla, int ip, int iu) {
  int m = 0, cont = 0;

  if (ip > iu)
    return ERR;
  else if (ip == iu)
    return cont;
  else {
    m = (iu + ip) / 2;
    cont += mergesort(tabla, ip, m);
    cont += mergesort(tabla, m+1, iu);
    return cont + merge(tabla, ip, iu, m);
  }
}


int merge(int* tabla, int ip, int iu, int imedio) {
  int cont = 0, i, j, k, l;
  int *tabla2;
  tabla2 = (int*) malloc((iu - ip + 1) * sizeof(int));

  tabla += ip;
  for (l = 0; l < iu - ip + 1; l++)
    tabla2[l] = tabla[l];
  tabla -= ip;

  i = ip;
  j = imedio + 1;
  k = 0;

  while( i<=imedio && j <= iu) {
    if(tabla[i] < tabla[j]) {
      tabla2[k] = tabla[i];
      i++;
    }
    else{
      tabla2[k] = tabla[j];
      j++; 
    }
    k++;
    cont++;
  }

  if (i > imedio) { 
    while (j <= iu){
      tabla2[k]=tabla[j];
      j++;
      k++;
    }
  }
  else if (j > iu) {
    while (i <= imedio) {
      tabla2[k] = tabla[i];
      i++;
      k++;
    }
  }

  tabla += ip;
  for (l = 0; l < iu - ip + 1; l++)
    tabla[l] = tabla2[l];
  tabla -= ip;

  free(tabla2);

  return cont ;
    
}

int quicksort(int* tabla, int ip, int iu) {
  int im, cont = 0, st = OK;
  
  if (ip > iu) {
    return ERR;
  }
  else if (ip == iu) {
    return OK;
  }
  else {
    st = partition(tabla, ip, iu, &im);
    if (st == ERR) {
      return ERR;
    }
    cont += st;
    
    if (ip < im - 1) {
      st = quicksort(tabla, ip, im - 1);
      if (st == ERR) {
        return ERR;
      }
      cont += st;
    }
    if (im + 1 < iu) {
      st = quicksort(tabla, im + 1, iu);
      if (st == ERR) {
        return ERR;
      }
      cont += st;
    }
    return cont;
  }
}

int partition(int* tabla, int ip, int iu,int *pos) {
  int i, m, k, cont = 0;

  if (ip > iu){
    return ERR;
  }

  median (tabla, ip, iu, pos);
  k = tabla[*pos];
  m = *pos;
  swap(&tabla[ip], &tabla[*pos]);
  *pos = ip;

  for (i = ip + 1; i <= iu; i++) {
    if (tabla[i] < k) {
      *pos = *pos + 1;
      swap(&tabla[*pos],&tabla[i]);
    }
    cont++;
  }
  swap(&tabla[m],&tabla[*pos]);
  return cont;
}

int median(int *tabla, int ip, int iu,int *pos) {
  *pos = ip;
  return OK;
}
