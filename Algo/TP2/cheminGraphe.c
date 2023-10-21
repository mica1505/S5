#include <stdio.h>
#include <stdlib.h>
#include "file.c"


void plusCourtChemin (int**adjacence, int ordre, int s, int *l, int *pred) {
    // Variables locales
    int *marques ;
    int x, y ;
    cel *f ; // file d’attente de sommets

    marques = (int *)calloc(ordre, sizeof(int));

    if(!marques){
        perror("Erreur d'allocation memoire.\n");
    }
    // Initialiser les longueurs minimales à 0
    for (x=0 ; x<ordre ; x++) {
        l[x] = 0 ;
    }
    // Marquer le sommet s à 1
    marques[s] = 1 ;
    // Créer (allouer) la file f et enfiler s dans f
    enfiler(f,nouvCell(s));
    while (f!=NULL) { // Tant que la file f n’est pas vide
        x = defile(f); // Défiler le premier sommet x de la file f
        printf("\nX : %d\n",x);
        // Pour tous les sommets y adjacents à x et non marqués
        for (y=0 ; y<ordre ; y++){
            if (adjacence[x][y] && !marques[y]) {
                marques[y] = 1 ; // marquer le sommet y
                enfiler(f, nouvCell(y)); // enfiler le sommet y dans f
                pred[y] = x ; // x est le prédécesseur de y
                l[y] = l[x]+1 ; // // incrémenter la longueur de y
            }
        }
    }
}