#include "produit_matrice.h"


/*Pour pouvoir multiplier deux matrices, il faudrait au préalable que
    le nombre de colonnes de la première soit égal au nombre de lignes de la seconde.
    Ansi la matrice obtenue est une matrice de taille n * k où n est le nombre de lignes de la première et 
    k le nombre de colonnes de la seconde. 
*/
void produit_matrice(size_t const lignes, size_t const colonnes_1, size_t const colonnes_2){

    // conditions pour les lignes et colonnes.
    if (lignes <= 0 || colonnes_1 <= 0 || colonnes_2 <= 0) {
        printf("Le nombre de colonnes et de lignes doit être supérieur à zero.\n");
        return;
    }

    // Allocation de la mémoire pour les trois matrices.

    int **A = malloc(lignes * sizeof(int*));
    for(size_t i = 0; i < lignes; i++) {
        for(size_t j = 0; j < colonnes_1; j++) {
            A[i] = malloc(colonnes_1 * sizeof(int));
        }
    }

    if (A == NULL) {
        fprintf(stderr, "Echec d'allocation mémoire.\n");
        exit(1);
    }
     
    // Pour la matrice B, le nombre de colonnes de A devient son nombre de lignes.
    size_t const lignes_B = colonnes_1;

    int **B = malloc(lignes_B * sizeof(int*));
    for(size_t i = 0; i < lignes_B; i++) {
        for(size_t j = 0; j < colonnes_2; j++) {
            B[i] = malloc(colonnes_2 * sizeof(int));
        }
    }

    if (B == NULL) {
        fprintf(stderr, "Echec d'allocation mémoire.\n");
        exit(1);
    }

    int **C = malloc(lignes * sizeof(int*));
    for(size_t i = 0; i < lignes; i++) {
        for(size_t j = 0; j < colonnes_2; j++) {
            C[i] = malloc(colonnes_2 * sizeof(int));
        }
    }

    if (C == NULL) {
        fprintf(stderr, "Echec d'allocation mémoire.\n");
        exit(1);
    }

    // On demande à l'utilisateur d'entrer les coefficients des matrices.
    
    for (size_t i = 0; i < lignes; i++) {
        for (size_t j = 0; j < colonnes_1; j++) {
            printf("Matrice A : Entrez le coefficient A[%zu][%zu] : ", i+1, j+1);
            scanf("%d", &A[i][j]);
        }
    }
    printf("\n");

    for (size_t i = 0; i < lignes_B; i++) {
        for (size_t j = 0; j < colonnes_2; j++) {
            printf("Matrice B : Entrez le coefficient B[%zu][%zu] : ", i+1, j+1);
            scanf("%d", &B[i][j]);
        }
    }
    printf("\n");

    // On calcule la produit
    for (size_t i = 0; i < lignes; i++) {
        for (size_t j = 0; j < colonnes_2; j++) {
            C[i][j] = 0;
            for (size_t k = 0; k < colonnes_1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // On affiche le résultat
    printf("Le produit est : \n");
    for (size_t i = 0; i < lignes; i++) {
        for (size_t j = 0; j < colonnes_2; j++) {
            printf("%d\t", C[i][j]);
        }
        printf("\n");
    }


    // Libération mémoire
    for (size_t i = 0; i < lignes; i++) free(A[i]);
    free(A);

    for (size_t i = 0; i < lignes_B; i++) free(B[i]);
    free(B);

    for (size_t i = 0; i < lignes; i++) free(C[i]);
    free(C);

}