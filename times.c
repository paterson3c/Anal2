/**
 * Descripcion: Implementation of time measurement functions
 * Fichero: times.c
 * Autor: Miguel Paterson & María Silva 
 * Version: 1.0
 * Fecha: 25-20-2023
 */

#include "times.h"
#include <stdlib.h>
#include <stdio.h>

/***************************************************/
/* Function: average_sorting_time Date:            */
/* Authors: Miguel Paterson & María Silva          */
/*                                                 */
/* Routine that computes and returns the average   */
/* time required by the provided sorting method    */
/* for sorting a given number of permutations      */
/* of a given length. Also computes the average,   */
/* minimum, and maximum number of basic operations */
/* used by the sorting method.                     */
/*                                                 */
/* Input:                                          */
/* pfunc_sort metodo: Pointer to the sorting method*/
/* int n_perms: Number of permutations             */
/* int N: Length of each permutation               */
/* PTIME_AA ptime: Struct to store results         */
/*                                                 */
/* Output:                                         */
/* short: OK if all goes well, ERR otherwise       */
/***************************************************/
short average_sorting_time(pfunc_sort metodo, int n_perms,int N,  PTIME_AA ptime)
{
  int i, j, count = 0, **perms;
  clock_t start, end, total;
  int st;

  ptime->N = N;
  ptime->n_elems = n_perms;

  if (!ptime || !metodo || n_perms < 1 || N < 1)
    return ERR;
  
  perms = generate_permutations(n_perms, N);
  if (!perms)
    return ERR;

  start = clock();
  for (i = 0; i < n_perms; i++)
  {
    st = metodo(perms[i], 0, N - 1);
    if (st == ERR)
      return ERR;
    count = st;

    if (i == 0) {
      ptime->max_ob = count;
      ptime->min_ob = count;
    }

    if( count < ptime->min_ob)
      ptime->min_ob = count;
    if (count > ptime->max_ob)
      ptime->max_ob = count;
    
    ptime->average_ob += (double) count;
  }
  end = clock();

  total = end - start;
  ptime->time = (double) total / CLOCKS_PER_SEC / n_perms;
  ptime->average_ob /= (double) n_perms;

  for (j=0; j < i; j++)
    free(perms[j]);
  
  free(perms);

  return st;
}


/***************************************************/
/* Function: generate_sorting_times Date:          */
/* Authors: Miguel Paterson & María Silva          */
/*                                                 */
/* Routine that generates a table of average       */
/* sorting times and basic operations for the      */
/* provided sorting method, over a range of        */
/* permutation lengths. The results are saved      */
/* to a file.                                      */
/*                                                 */
/* Input:                                          */
/* pfunc_sort method: Pointer to the sorting method*/
/* char* file: Name of the output file             */
/* int num_min: Minimum permutation length         */
/* int num_max: Maximum permutation length         */
/* int incr: Increment in permutation length       */
/* int n_perms: Number of permutations             */
/*                                                 */
/* Output:                                         */
/* short: OK if all goes well, ERR otherwise       */
/***************************************************/
short generate_sorting_times(pfunc_sort method, char* file, int num_min, int num_max,  int incr, int n_perms)
{
  int i, j;
  PTIME_AA time;
  short st = OK;

  time = (PTIME_AA) calloc((((num_max - num_min) / incr) + 1), sizeof(TIME_AA));
  if(!time)
    return ERR;

  for(i = num_min, j = 0; i < num_max && st != ERR; i += incr, j++) {
    st = average_sorting_time(method, n_perms, i, &time[j]);
    if(st == ERR)
      break;
  }

  if (st == ERR) {
    free(time);
    return ERR;
  }

  st = save_time_table(file, time, j);

  free(time);
  return st;
}

/***************************************************/
/* Function: save_time_table Date:                 */
/* Authors: Miguel Paterson & María Silva          */
/*                                                 */
/* Routine that saves the table of average sorting */
/* times and basic operations to a file.           */
/*                                                 */
/* Input:                                          */
/* char* file: Name of the output file             */
/* PTIME_AA ptime: Array of results                */
/* int n_times: Number of entries in ptime         */
/*                                                 */
/* Output:                                         */
/* short: OK if all goes well, ERR otherwise       */
/***************************************************/
short save_time_table(char* file, PTIME_AA ptime, int n_times)
{
  int i;
  FILE *f;

  f = fopen(file, "a");
  if(!f)
    return ERR;

  for(i = 0; i< n_times; i++) {
    fprintf(f, "%d %f %f %d %d\n", ptime[i].N, ptime[i].time, ptime[i].average_ob, ptime[i].min_ob, ptime[i].max_ob);
  }

  fclose(f);
  return OK;
}


