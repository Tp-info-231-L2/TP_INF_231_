#include "recherche_seq.h"

void recherche_seq() {
    size_t taille = 0;
    int nombre_recherche = 0;
    
    printf("Combien d'élément voulez-vous inserer dans le tableau : ");
    scanf("%zu", &taille);

    // La taille du tableau est supérieure à zero
    if (taille <= 0) {
        fprintf(stderr, "La taille du tableau doit être supérieure à zero.\n");
        return;
    }

    int* tab = malloc(taille * sizeof(*tab));
    if (tab == NULL) {
        fprintf(stderr, "memory allocation failed.\n");
        exit(1);
    }

    for (size_t i = 0; i < taille; i++) {
        printf("Entrez l'élément %zu : ", i+1);
        scanf("%d", &tab[i]);
    }
    
    while(1) {
        printf("Entrez l'élément à rechercher (Appuyer sur 'q' ou 'Q' pour quitter): ");
        
        // Vérification si l'utilisateur veut quitter.

        char buffer[100];
        if (scanf("%s", buffer) != 1) {break;};
        if (buffer[0] == 'q' || buffer[0] == 'Q') {break;};

        // conversion de buffer (string) en int.
        nombre_recherche = atoi(buffer);

        bool trouve = false;
        int index_recherche = -1;

        // On recherche le nombre dans le tableau
        for (size_t i = 0; i < taille; i++) {
            if (tab[i] == nombre_recherche) {
                trouve = true;
                index_recherche = i;
                break;
            }
        }

        if (trouve) {
            printf("Le nombre %d est présent à l'index %d.\n", nombre_recherche, index_recherche);
        }
        else {
            printf("Ce nombre n'est pas dans le tableau.\n");
        }
        printf("\n");
    }
    free(tab);
    printf("Fin de la recherche.\n");

}