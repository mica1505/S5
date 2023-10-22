#include <stdio.h>
#include <stdlib.h>
#include "file.c"
#include "graphe.c"
#include "graphe.h"

void plusCourtChemin (int**adjacence, int ordre, int s, int *l, int *pred) {
    //f une file qui contient les sommets dont on n'a pas encore visite les voisins
    //pred permet de garder les predecesseurs
    //l une liste des longueur de tous le ssommets en partant du sommet s
    // Variables locales
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
    
    marques[s] = 1 ;
    // Créer (allouer) la file f et enfiler s dans f
    /*f = file();
    enfiler(f,nouvCell(s));*/
    f = nouvCell(s);
    printf("\n--PREMIER ENFILE FILE--\n");
    afficheFile(f);
    while (!estVide(f)) { 
        x = f->sommet;
        printf("\n--ON RECUPERE X %d-\n",x);
        for (y=0 ; y<ordre ; y++){
            if (adjacence[x][y] && !marques[y]) {
                marques[y] = 1 ;
                printf("\n--BOUCLE ENFILE FILE--\n");
                enfiler(f, nouvCell(y));
                afficheFile(f);
                pred[y] = x ;
                l[y] = l[x]+1 ;
            }
        }
        defile(&f);
        printf("\n--ON DEFILE X %d--\n",x);
        afficheFile(f);
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