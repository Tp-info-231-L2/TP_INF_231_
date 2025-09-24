#include "somme_matrice.h"

void somme_matrice(size_t const lignes, size_t const colonnes) {

    //conditions pour les lignes et colonnes.
    if (lignes <= 0) {
        printf("Le nombre de lignes doit être supérieur à zero.\n");
        return ;
    }

    if (colonnes <= 0) {
        printf("Le nombre de colonnes doit être supérieur à zero.\n");
        return ;
    }
    
    // On aloue la mémoire pour la matrice A.
    int **A = malloc(lignes * sizeof(int*));
    
    // Pareil pour ses colonnes.
    for (size_t i = 0; i < lignes; i++) {
        for (size_t j = 0; j < colonnes; j++) {
            A[i] = malloc(colonnes * sizeof(int));
        }
    }

    // On vérifie si l'allocation s'est bien déroulée.
    if (A == NULL) {
        fprintf(stderr, "L'allocation de mémoire a echouée.\n");
        exit(1);
    }

    // Même procédé avec la matrice B et C (C est la matrice somme des deux autres.)

    int **B = malloc(lignes * sizeof(int*));
    
    // Pareil pour ses colonnes.
    for (size_t i = 0; i < lignes; i++) {
        for (size_t j = 0; j < colonnes; j++) {
            B[i] = malloc(colonnes * sizeof(int));
        }
    }

    // On vérifie si l'allocation s'est bien déroulée.
    if (B == NULL) {
        fprintf(stderr, "L'allocation de mémoire a echouée.\n");
        exit(1);
    }

    int **C = malloc(lignes * sizeof(int*));
    
    for (size_t i = 0; i < lignes; i++) {
        for (size_t j = 0; j < colonnes; j++) {
            C[i] = malloc(colonnes * sizeof(int));
        }
    }

    if (C == NULL) {
        fprintf(stderr, "L'allocation de mémoire a echouée.\n");
        exit(1);
    }

    // On demande à l'utilisateur d'entrer les coefficients des matrices.
    
    for (size_t i = 0; i < lignes; i++) {
        for (size_t j = 0; j < colonnes; j++) {
            printf("Matrice A : Entrez le coefficient A[%zu][%zu] : ", i+1, j+1);
            scanf("%d", &A[i][j]);
        }
    }
    printf("\n");

    for (size_t i = 0; i < lignes; i++) {
        for (size_t j = 0; j < colonnes; j++) {
            printf("Matrice B : Entrez le coefficient B[%zu][%zu] : ", i+1, j+1);
            scanf("%d", &B[i][j]);
        }
    }
    printf("\n");

    // On calcule la somme
    for (size_t i = 0; i < lignes; i++) {
        for (size_t j = 0; j < colonnes; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }

    // Affichage du résultat

    

    printf("\nLa somme donne : \n\n");
    for (size_t i = 0; i < lignes; i++) {
        for (size_t j = 0; j < colonnes; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }
    printf("\n");


    // Libération mémoire
    for (size_t i = 0; i < lignes; i++) free(A[i]);
    free(A);

    for (size_t i = 0; i < lignes; i++) free(B[i]);
    free(B);

    for (size_t i = 0; i < lignes; i++) free(C[i]);
    free(C);
}