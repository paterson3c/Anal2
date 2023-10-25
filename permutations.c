/**
 *
 * Descripcion: Implementation of function that generate permutations
 *
 * File: permutations.c
 * Autor: Carlos Aguirre
 * Version: 1.1
 * Fecha: 21-09-2019
 *
 */


#include "permutations.h"
#include "time.h"
#include "stdlib.h"


void swap(int *a, int *b)
{
  int aux;
  aux = *a;
  *a = *b;
  *b = aux;
}

/***************************************************/
/* Function: random_num Date:                      */
/* Authors: Miguel Paterson & María Silva          */
/*                                                 */
/* Rutine that generates a random number           */
/* between two given numbers                       */
/*                                                 */
/* Input:                                          */
/* int inf: lower limit                            */
/* int sup: upper limit                            */
/* Output:                                         */
/* int: random number                              */
/***************************************************/
int random_num(int inf, int sup)
{
  return inf + (int) ((sup - inf + 1.0) *rand() / (RAND_MAX + 1.0));
}

/***************************************************/
/* Function: generate_perm Date:                   */
/* Authors: Miguel Paterson & María Silva          */
/*                                                 */
/* Rutine that generates a random permutation      */
/*                                                 */
/* Input:                                          */
/* int n: number of elements in the permutation    */
/* Output:                                         */
/* int *: pointer to integer array                 */
/* that contains the permitation                   */
/* or NULL in case of error                        */
/***************************************************/
int* generate_perm(int N)
{
  int *perm;
  int i ;
  int ran;

  perm = (int*) malloc(N*sizeof(int));

  for(i=0; i<N; i++) {
    perm[i] = i;
  }

  for(i=0; i<N; i++) {
    ran = random_num(i, N-1);
    swap(&perm[i], &perm[ran]);
  }

  return perm;
}

/***************************************************/
/* Function: generate_permutations Date:           */
/* Authors: Miguel Paterson & María Silva          */
/*                                                 */
/* Function that generates n_perms random          */
/* permutations with N elements                    */
/*                                                 */
/* Input:                                          */
/* int n_perms: Number of permutations             */
/* int N: Number of elements in each permutation   */
/* Output:                                         */
/* int**: Array of pointers to integer that point  */
/* to each of the permutations                     */
/* NULL en case of error                           */
/***************************************************/
int** generate_permutations(int n_perms, int N)
{
  /* your code */
  int **perm;
  int i;

  perm = (int**) malloc(n_perms*sizeof(int*));

  for (i=0; i < n_perms; i++) {
    perm[i]=generate_perm(N);
  }
 
  return perm;
  
}
