/**
 *
 * Descripcion: Implementation of sorting functions
 *
 * Fichero: sorting.c
 * Autor: Carlos Aguirre
 * Version: 1.0
 * Fecha: 16-09-2019
 *
 */

#include <stdio.h>
#include "sorting.h"


/***************************************************/
/* Function: SelectSort    Date:                   */
/* Authors: Miguel Paterson & María Silva          */
/*                                                 */
/* Function that implements the selection sort     */
/* algorithm in ascending order.                   */
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
/* Function: SelectSortInv Date:                   */
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
/* Function: min Date:                             */
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