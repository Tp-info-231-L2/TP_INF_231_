
#ifndef TABLIB_H
#define TABLIB_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// fonction pour vérifier si le tableau est trié

void check_sort_array(int *tableau, size_t taille); 

//inverser un tableau.

void inverse_array (int *tableau, size_t taille);

// Fonction de trie pour le tableau.
void selection_sort(int *arr, size_t taille);

void median_array(int *array, size_t taille);

// produit vecteur x matrices.

void scalaire_Matrice(int **matrix, size_t lignes, size_t colonnes, int const scalaire);

// produit vectoriel.
int calcul_determinant(int val_1, int val_2, int val_3, int val_4);

int multiplication(size_t a, size_t b);

#endif

