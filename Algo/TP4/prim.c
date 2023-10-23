#include <stdio.h>
#include <stdlib.h>
#include "graphe.c"
#include "aretes.c" 
#include "aretes.h"
#include "file.c" 
#include "file.h"

#define INFINI 1000.0 // un poids réel supérieur à la plus grande longueur totale
// Fonction qui retourne l’arbre couvrant de poids minimum d’un graphe valué et non orienté
// depuis un sommet de référence aléatoire
// Paramètres :
// adjacencePoids : matrice d’adjacence pondérée du graphe
// ordre : nombre de sommets
aretes * prim (float **adjacencePoids, int ordre) {
    /*Variables locales*/
    aretes *arbre ; // arbre d’incidence nœud-arc de poids minimum à retourner
    int indiceA = 0 ; // indice de l’arbre initialisé à 0
    int *marques ; // tableau dynamique indiquant si les sommets sont marqués ou non
    int s, x, y, ymin ; // numéros de sommets intermédiaires
    float min ; // distance minimale du prochain sommet à marquer
    // Allouer l’arbre de « ordre-1 » arêtes et le tableau marque de « ordre » entiers
    arbre = (aretes *)malloc(sizeof(aretes) * (ordre-1));

    marques = (int *)calloc(ordre, sizeof(int));

    // Choisir un sommet s aléatoirement compris entre 0 et ordre-1
    s = rand()%ordre ;
    // Marquer le sommet aléatoire s
    marques[s] = 1 ;
    //tant que les arêtes de l’arbre ne sont pas toutes traitées
    while (indiceA<ordre-1) {
        // Initialiser la longueur minimale à l’INFINI
        min = INFINI ;
        // Pour tous les sommets x marqués
        // Chercher le sommet de longueur minimale « ymin » adjacent à x
        // et non marqué
        for (x=0 ; x<ordre ; x++){
            if (marques[x]){
                for (y=0 ; y<ordre ; y++){
                    if (adjacencePoids[x][y] && !marques[y] && adjacencePoids[x][y]<min) {
                        min = adjacencePoids[x][y] ; // poids min
                        ymin = y ; // sommet y de poids min
                    }
                }
            }
        }
    }
    // marquer le sommet « ymin » de longueur minimale
    marques[ymin] = 1 ;
    // Insérer l’arête (x, ymin) de longueur min à la position « indiceA » de l’arbre
    //enfile(arbre,nouvCell(x,ymin,min));
    // Passer à l’arête suivante de l‘arbre
    indiceA++ ;
     }
    return arbre ; // retourner l’arbre de poids minimum
}

