#include <stdio.h>
#include <stdlib.h>
#include "file.c"
#include "graphe.c"
#include "graphe.h"


// Procédure qui recherche le plus court chemin depuis un sommet de référence
// Paramètres :
// adjacence : matrice d’adjacence du graphe
// ordre : nombre de sommets
// s : numéro de sommet de référence
// l : tableau dynamique alloué des longueurs minimales des sommets depuis s
// pred : tableau dynamique alloué des prédécesseurs des sommets 
void plusCourtChemin (int**adjacence, int ordre, int s, int *l, int *pred) {
    int *marques ;
    int x, y ;
    cel *f ;

    marques = (int *)calloc(ordre, sizeof(int));

    if(!marques){
        perror("Erreur d'allocation memoire.\n");
    }
    // Initialiser les longueurs minimales à 0
    for (x=0 ; x<ordre ; x++) {
        l[x] = 0 ;
    }
    //on marque le sommet s passe en parametre
    marques[s] = 1 ;
    //on initialise la file avec le sommet s passe en parametre
    f = nouvCell(s);
    //tant que la file n'est pas vide 
    while (!estVide(f)) { 
        //on prend le premier element de la file : x
        x = f->sommet;
        for (y=0 ; y<ordre ; y++){
            //on marque les voisins du sommet x et on les enfile
            if (adjacence[x][y] && !marques[y]) {
                marques[y] = 1 ;
                //on enfile les voisins
                enfiler(f, nouvCell(y));
                //x est le predecesseur de y
                pred[y] = x ;
                //on calcule la longueur du chemin entre x et y
                l[y] = l[x]+1 ;
            }
        }
        //on defile le premier elememnt de la file
        defile(&f);
    }

}

int main(){
    graphe * test = chargeGraphe();
    afficheGraphe(test);
    //marquerVoisins(test->adj,test->sommet,1);
    int l[test->sommet],pred[test->sommet];

    printf("\nPLUS COURT CHEMIN\n");

    plusCourtChemin(test->adj,test->sommet,2,l,pred);

    afficheTab(l,test->sommet,"Liste des longueurs");
    afficheTab(l,test->sommet,"Liste des predecesseurs");
    libererMemoire(test);
    return EXIT_SUCCESS;
}