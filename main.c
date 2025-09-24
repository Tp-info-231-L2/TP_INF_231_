#include <stdio.h>
#include <stdlib.h>
#include "somme_matrice.h"
#include "produit_matrice.h"
#include "recherche_seq.h"
#include "tablib.h" 


int main() {
    int choix = 0;
    char buffer[20];

    do {
        printf("\n\t\t\t\t\tVoici le menu\n\n");
        printf("\t1. Additionner deux matrices.\n");
        printf("\t2. Multiplier deux matrices.\n");
        printf("\t3. Recherche sequentielle dans un tableau d'entiers.\n");
        printf("\t4. Tester si un tableau est trié.\n");
        printf("\t5. La médiane dans un tableau.\n");
        printf("\t6. Inverser un tableau.\n");
        printf("\t7. Produit vectoriel.\n");
        printf("\t8. Produit scalaire x matrices.\n");
        printf("\t9. Multiplier deux entiers supérieurs à zero par incrémentations de compteurs.\n");
        printf("\n\t10. Quitter.\n");
        
        printf("Entrez votre choix : ");
        if (scanf("%s", buffer) != 1) {
            fprintf(stderr, "Erreur : Arguments invalides.\n");
            exit(EXIT_FAILURE);
        }

        choix = atoi(buffer);

        switch (choix) {
            // additionnner deux matrices.
            case 1: {
                size_t lignes, colonnes;
                char buffer_lignes[20], buffer_colonnes[20];

                printf("Entrez le nombre de lignes des matrices : ");
                scanf("%s", buffer_lignes);
                printf("Entrez le nombre de colonnes des matrices : ");
                scanf("%s", buffer_colonnes);

                lignes = atoi(buffer_lignes);
                colonnes = atoi(buffer_colonnes);

                somme_matrice(lignes, colonnes);
                break;
            }
            case 2: {
                // Multiplier deux matrices
                size_t lignes_1, colonnes_1, colonnes_2;
                char buffer_lignes_1[20], buffer_colonnes_1[20], buffer_colonnes_2[20];

                printf("Entrez le nombre de lignes de la matrice A : ");
                scanf("%s", buffer_lignes_1);
                printf("Entrez le nombre de colonnes de la matrice A : ");
                scanf("%s", buffer_colonnes_1);
                printf("Entrez le nombre de colonnes de la matrice B : ");
                scanf("%s", buffer_colonnes_2);

                lignes_1   = atoi(buffer_lignes_1);
                colonnes_1 = atoi(buffer_colonnes_1);
                colonnes_2 = atoi(buffer_colonnes_2);

                produit_matrice(lignes_1, colonnes_1, colonnes_2);
                break;
            }
            // Recherche sequentielle
            case 3:
                recherche_seq();
                break;
            case 4: {
                int *tableau;
                size_t taille;

                printf("Entrez le nombre d'élément à insérer dans le tableau : ");
                scanf("%zu", &taille);
                if (taille < 1) {
                    printf("La taille doit être supérieure à 1.\n");
                    exit(EXIT_FAILURE);
                }

                tableau = malloc(taille * sizeof(*tableau));

                for (size_t i = 0; i < taille; i++) {
                    printf("Entrez l'élément %zu du tableau : ", i + 1);
                    scanf("%d", &tableau[i]);
                }

                check_sort_array(tableau, taille);
                break;
            }
            // Détermination de la médiane dans un tableau.
            case 5: {
                int *tab;
                size_t taille;
                printf("Entrez le nombre d'éléments à insérer dans le tableau : ");
                scanf("%zu", &taille);

                if (taille < 1) {
                    printf("La taille doit être supérieure à zero.\n");
                    return 1;
                }

                tab = malloc(taille * sizeof(*tab));
                
                if (tab == NULL) {
                    fprintf(stderr, "Echec d'allocation mémoire.\n");
                    exit(1);
                }

                for (size_t i = 0; i < taille; i++) {
                    printf("Entrez le nombre entier %zu : ", i + 1);
                    scanf("%d", &tab[i]);
                }

                median_array(tab, taille);
                break;
            }
            // Inverse d'un tableau
            case 6: {
                int *tab;
                size_t taille;
                printf("Entrez le nombre d'éléments à insérer dans le tableau : ");
                scanf("%zu", &taille);

                if (taille < 1) {
                    printf("La taille doit être supérieure à zero.\n");
                    return 1;
                }

                tab = malloc(taille * sizeof(*tab));
                
                if (tab == NULL) {
                    fprintf(stderr, "Echec d'allocation mémoire.\n");
                    exit(1);
                }

                for (size_t i = 0; i < taille; i++) {
                    printf("Entrez le nombre entier %zu : ", i + 1);
                    scanf("%d", &tab[i]);
                }

                inverse_array(tab, taille);
                break;
            }
            // Produt vectoriel de deux vecteurs A et B
            case 7: {
                int tab_1[3];
                int tab_2[3];

                // On demande à l'utilisateur d'entrer les coordonnées entiières x, y, z des vecteurs.
                for(size_t i = 0; i < 3; i++) {
                    printf("Entrez le coordonnée x_%zu du vecteur A : ", i + 1);
                    scanf("%d", &tab_1[i]);
                }
                printf("\n");

                for(size_t i = 0; i < 3; i++) {
                    printf("Entrez le coordonnée x_%zu du vecteur B : ", i + 1);
                    scanf("%d", &tab_2[i]);
                }
                printf("\n");

                int x = calcul_determinant(tab_1[1], tab_1[2], tab_2[1], tab_2[2]);
                int y = - calcul_determinant(tab_1[0], tab_1[2], tab_2[0], tab_2[2]);
                int z = calcul_determinant(tab_1[0], tab_1[1], tab_2[0], tab_2[1]);

                printf("(%d, %d, %d)∧(%d, %d, %d) = (%d, %d, %d)", tab_1[0], tab_1[1], tab_1[2], 
                    tab_2[0], tab_2[1], tab_2[2], x, y, z);
                printf("\n");
                break;;
            }
            // Mutiplication scalaire × matrice.
            case 8: {
                int scalaire = 0, taille;
                int **matrice;
                size_t lignes, colonnes;

                printf("Entrez le scalaire : ");
                scanf("%d", &scalaire);

                printf("Entrez le nombre de lignes de la matrice : ");
                scanf("%zu", &lignes);
                if (lignes < 1 ) {
                    printf("Le nombre de lignes est supérieur à zero.\n");
                    return 1;
                }

                printf("Entrez le nombre de colonnes de la matrice : ");
                scanf("%zu", &colonnes);
                if (colonnes < 1 ) {
                    printf("Le nombre de colonnes est supérieur à zero.\n");
                    return 1;
                }

                matrice = malloc(lignes * sizeof(int*));

                for (size_t i = 0; i < lignes; i++) {
                    matrice[i] = malloc(colonnes * sizeof(int));
                }

                if (matrice == NULL) {
                    return EXIT_FAILURE;
                }

                for(size_t i = 0; i < lignes; i++) {
                    for (size_t j = 0; j < colonnes; j++) {
                        printf("Entrez le coefficient matrice[%zu][%zu] : ", i + 1, j + 1);
                        scanf("%d", &matrice[i][j]);
                    }
                }

                printf("Avant on avait : \n");

                for(size_t i = 0; i < lignes; i++) {
                    for (size_t j = 0; j < colonnes; j++) {
                        printf("%d\t", matrice[i][j]);
                    }
                    printf("\n");
                }

                scalaire_Matrice(matrice, lignes, colonnes, scalaire);

                printf("\nAprès multiplication par le scalaire on a : \n");

                for(size_t i = 0; i < lignes; i++) {
                    for (size_t j = 0; j < colonnes; j++) {
                        printf("%d\t", matrice[i][j]);
                    }
                    printf("\n");
                }
                
                break;
            }
            // Multiplier deux entiers par incrémentation de compteur lorsque ceux ci sont supérieur à zero.
            case 9: {
                size_t a;
                size_t b;
                int produit = 0;
                printf("Entrez le premier entier : ");
                scanf("%zu", &a);

                printf("Entrez le deuxieme entier : ");
                scanf("%zu", &b);

                if (a && b <= 0) {
                    printf("Les entiers doivent être supérieurs à zero.\n");
                    return 1;
                }

                produit = multiplication(a, b);
                printf("%zu × %zu = %d\n", a, b, produit);
                break;
            }
            case 10:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide, réessayez.\n");
        }

    } while (choix != 10);

    return 0;
}