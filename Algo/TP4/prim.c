#include <stdio.h>
#include <stdlib.h>

#include "graphe.c"
#include "aretes.c" 



#define INFINI 1000.0


aretes * prim (int **adjacencePoids, int ordre,int s) {
    aretes *arbre ; // arbre d’incidence nœud-arc de poids minimum à retourner
    int indiceA = 0 ; // indice de l’arbre initialisé à 0
    int *marques ; // tableau dynamique indiquant si les sommets sont marqués ou non
    int s, x, y, ymin,sommetMarque ; // numéros de sommets intermédiaires
    float min ; // distance minimale du prochain sommet à marquer
    // Allouer l’arbre de « ordre-1 » arêtes et le tableau marque de « ordre » entiers
    arbre = (aretes *)malloc(sizeof(aretes) * (ordre-1));

    marques = (int *)calloc(ordre, sizeof(int));

    // Choisir un sommet s aléatoirement compris entre 0 et ordre-1
    // Marquer le sommet aléatoire s
    marques[s] = 1 ;
    //tant que les arêtes de l’arbre ne sont pas toutes traitées/tous les sommets ne sont pas marques
    while (indiceA<ordre-1) {
        // Initialiser la longueur minimale à l’INFINI
        min = INFINI ;
        // Pour tous les sommets x marqués
        // Chercher le sommet de longueur minimale « ymin » adjacent à x
        // et non marqué
        for (x=0 ; x<ordre ; x++){
            if (marques[x]){
                sommetMarque = x;
                //si un sommet est marque on visite tous ses voisins et on marque celui qui le plus petit poid?
                for (y=0 ; y<ordre ; y++){
                    if (adjacencePoids[x][y] && !marques[y] && adjacencePoids[x][y]<min) {
                        min = adjacencePoids[x][y] ; // poids min
                        ymin = y ; // sommet y de poids min
                    }
                }
            }
        }
    // marquer le sommet « ymin » de longueur minimale
    marques[ymin] = 1 ;
    // Insérer l’arête (x, ymin) de longueur min à la position « indiceA » de l’arbre

    arbre[indiceA] = nouvCell(sommetMarque,ymin,min);
    
    // Passer à l’arête suivante de l‘arbre
    indiceA++ ;
    }
    return arbre ; // retourner l’arbre de poids minimum
}

int main(int argc, char *argv[]){
    graphe * test = chargeGraphe();
    afficheGraphe(test);
    aretes * res = prim((test->adj),8,2);
    afficheArete(res);
    libererMemoire(test);
    return EXIT_SUCCESS;
}