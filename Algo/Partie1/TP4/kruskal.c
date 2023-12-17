#include <stdio.h>
#include <stdlib.h>

#include "graphe.c"
#include "aretes.c" 


aretes * chargeAretes(int ordre,int nbAretes){
    int n,m,p;
    aretes tmp;
    aretes *art = (aretes *)malloc(sizeof(aretes)*nbAretes);

    if(!art){
        perror("Erreur d'allocation memoire.\n");
    }
    
    printf("\nSAISIE DES %d ARETES : \nEntrez les numeros des sommets (u,v,p) tq u et v sont voisins et p est le poid de l'arete : ",nbAretes);

    for(int i=0;i<nbAretes;i++){
        printf("\nArete n_%d :",i+1);
        scanf("%d %d %d", &tmp.u,&tmp.v,&tmp.poid);
        art[i]=tmp;
    }

    return art;
}
// Fonction qui retourne l’arbre couvrant de poids minimum d’un graphe valué et non orienté
// depuis un sommet de référence
// Paramètres :
// graphe : tableau d’arêtes du graphe
// ordre : nombre de sommets
// s : numéro de sommet de référence
// n : nombre d’arêtes du graphe
aretes * kruskal (aretes * graphe, int ordre, int s, int n,int *nres) {
    // Variables locales
    aretes *arbre ; // tableau d’arêtes de poids minimum à retourner
    int *connexe; // tableau dynamique des numéros de sommets connexes de l’arbre
    int indiceA = 0, indiceG = 0 ; // indices de l’arbre et du graphe initialisés à 0
    int x, s1, s2 ; // numéros de sommets intermédiaires
    aretes u ; // arête reliant 2 sommets x1 et x2

    // Allouer l’arbre de « ordre - 1 » arêtes
    arbre = (aretes *)malloc(sizeof(aretes)*(ordre-1));
    if(!arbre){
        perror("Erreur d'allocation dynamique.");
    }
    // Allouer le tableau connexe de « ordre » sommets
    connexe = (int *)malloc(sizeof(int)*ordre);
    if(!connexe){
        perror("Erreur d'allocation dynamique.");
    }
    // Initialiser les connexités indicées sur les numéros de sommets
    for (x=0 ; x<ordre ; x++){
         connexe[x] = x ;
    }
    // Trier le graphe par ordre croissant des poids de ses « n » arêtes en utilisant le tri a bulles
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (graphe[j].poid > graphe[j+1].poid) {
                aretes temp = graphe[j];
                graphe[j] = graphe[j + 1];
                graphe[j + 1] = temp;
            }
        }
    }
    
    printf("\n------Aretes tries------\n");
    afficheArete(graphe,n);
    printf("\n-------------\n");

    // tant que les arêtes de l’arbre et du graphe ne sont pas toutes traitées
    while (indiceA<ordre-1 && indiceG<n) {
        u = graphe[indiceG] ; // retourner l’arête u numéro indiceG du graphe
        s1 = connexe[u.u] ; s2 = connexe[u.v] ; // les sommets s1, s2 de l’arête u11
        // Tester si les sommets s1 et s2 de l’arête u forment un cycle dans l’arbre
        if (s1==s2){ // cycle si s1 et s2 connexes
            indiceG++ ; // passer à l’arête suivante du graphe
        }else { // pas de cycle
            // insérer l’arête u à la position « indiceA » de l’arbre
            arbre[indiceA] = u ;
            indiceA++ ; indiceG++ ; // passer à l’arête suivante de l’arbre et du graphe
            // Indiquer que les sommets s1 et s2 sont connexes
            for (x=0 ; x<ordre ; x++){
                if (connexe[x]==s1){
                    connexe[x] = s2 ;
                }
            }
        }
    }
    // Le graphe est non connexe si le nombre d’arêtes de l’arbre < nombre de sommets-1
    if (indiceA<ordre-1) { 
        printf("Le graphe n'est pas connexe\n") ; 
    }
    *nres = indiceA;
    return arbre ; // retourner l’arbre de poids minimum
}

int main(int argc, char *argv[]){
    int nbAretes = 11,ordre=8,nres;
    aretes * test = chargeAretes(ordre,nbAretes);
    afficheArete(test,nbAretes);
    aretes * res = kruskal(test,ordre,2,nbAretes,&nres);
    printf("\nResultat kruskal\n");
    afficheArete(res,nres);
    return EXIT_SUCCESS;
}
