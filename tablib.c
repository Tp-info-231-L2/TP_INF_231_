#include "tablib.h"

// Verification sur le tableau est trié.

void check_sort_array(int *tableau, size_t taille) {
    // On suppose que le tableau est trié.
    bool est_trie = true;

    for (size_t i = 0; i < taille -1; i++)
    {
        if (tableau[i] > tableau [i + 1]) {
            est_trie = false;
            break;
        }
    }

    if (est_trie) {
        printf("Le tableau est trié.\n");
    }
    else {
        printf("Le tableau n'est pas trié.\n");
    }
    
}

// produit vecteur x matrices.

void scalaire_Matrice(int **matrix, size_t lignes, size_t colonnes, int const scalaire) {

    if (!matrix) return ;

    for(size_t i = 0; i < lignes; i++) {
        for (size_t j = 0; j < colonnes; j++) {
            matrix[i][j] = scalaire * matrix[i][j];
        }
    }
}

// Fonction pour trier le tableau.
void selection_sort(int *arr, size_t taille) {
    for (size_t i = 0; i < taille -1; i++) {
        size_t min_index = i;
        for (size_t j = i + 1; j < taille; j++) {
            if(arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        if (min_index != i) {
            int temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }
}


// Médiane dans un tableau.
void median_array(int *array, size_t taille) {
    int index_mediane;
    // On trie le tableau.
    selection_sort(array, taille);
    printf("Tableau trié : ");
    for(size_t i=0; i<taille; i++)
    printf("%d ", array[i]);
    printf("\n");


    // Si l'effectif est pair, la médiane est la valeur se trouvant à (N\2) + 1;
    if (taille % 2 != 0) {
        index_mediane = taille / 2;
        printf("La médiane est : %d et se trouve à l'index %d.\n", array[index_mediane], index_mediane);
    }
    else {
        // la médiane est égale à la moyennes des deux valeurs du milieu.
        int val_1 = array[(taille / 2) - 1];
        int val_2 = array[taille / 2];
        float moyenne = (val_1 + val_2) / 2.;

        printf("La médiane est : %.2f.\n", moyenne);
    }
}


// Inverser un tableau.
void inverse_array (int *tableau, size_t taille) {
    int *out_array = malloc(taille * sizeof(*out_array));
    
    if (out_array == NULL) {
        fprintf(stderr, "Echec d'allocation mémoire.\n");
        return;
    }

    for (size_t i = 0; i < taille; i++) {
        out_array[i] = tableau[taille-1-i];
    }

    printf("Tableau initial : ");
    for(size_t i = 0; i < taille; i++) {
        printf("%d\t", tableau[i]);
    }
    printf("\n");

    printf("Tableau inverse : ");
    for(size_t i = 0; i < taille; i++) {
        printf("%d\t", out_array[i]);
    }
    printf("\n");

    free(out_array);
}

// calculer le produit scalaire.
int calcul_determinant(int val_1, int val_2, int val_3, int val_4) {
    
    return (val_1 * val_4) - (val_2 * val_3);
}

// calcul de a x b pour a, b > 0

int multiplication(size_t a, size_t b) {
    int produit = 0;

    size_t i = 0;
    size_t j = 0;

    while (i < b) {
        while (j < a) {
            produit++;
            j++;
        }
        j = 0;
        i++;
    }

    return produit;
}