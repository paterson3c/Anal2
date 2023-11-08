/**
 * Descripcion: Implementation of time measurement functions
 * Fichero: permutations.h
 * Autor: Miguel Paterson & María Silva 
 * Version: 1.0
 * Fecha: 25-20-2023
 */

#ifndef PERMUTATIONS_H
#define PERMUTATIONS_H

/* constants */

#ifndef ERR
  #define ERR -1
  #define OK (!(ERR))
#endif

int random_num(int inf, int sup);
int* generate_perm(int N);
int** generate_permutations(int n_perms, int N);
void swap(int *a, int *b);
#endif
