#include <stdio.h>
#include <stdlib.h>

#include "graphe.h"
//indexation a 0
//les sommets d'un graphe d'ordre n sont numerotes de 0 a n-1
//fonction qui permet la saisie d'un graphe
graphe * chargeGraphe(){

    int n,m;
    graphe *g = (graphe *)malloc(sizeof(graphe));

    if(!g){
        perror("Erreur d'allocation memoire.\n");
        return NULL;
    }
    //on demande a l'utilisateur le nombre de sommets
    printf("Entrez le nombre de sommets du graphe : ");
    scanf("%d",&g->sommet);
    //on initialise la matrice d'adjacence du grphe
    g->adj = (int **)malloc(g->sommet * sizeof(int));

    if(!g->adj){
        perror("Erreur d'allocation memoire.\n");
        return NULL;
    }
    //on initialise les coef de la matrice d'adj a 0
    for(int i=0;i<g->sommet;i++){
        g->adj[i] = (int *)calloc(g->sommet, sizeof(int));
        if(!g->adj[i]){
            perror("Erreur d'allocation memoire.\n");
            return NULL;
        }
    }

    //on demande a l'utilisateur le nombre d'aretes
    do
    {
        printf("Entrez le nombre d'aretes du graphe : ");
        scanf("%d",&g->aretes);
    } while (g->aretes > (g->sommet*(g->sommet-1))/2);
    
    printf("\nSAISIE DES %d ARETES : \nEntrez les numeros des sommets (u,v) tq u et v sont voisins : ",g->aretes);

    //on part du principe que les sommets sont numerotes de 0 a g->sommet-1
    // et que g est un graphe non oriente et simple
    for(int i=0;i<g->aretes;i++){
        printf("\nArete n_%d :",i+1);
        scanf("%d %d", &n,&m);
        g->adj[n][m] = 1;
        g->adj[m][n] = 1;
    }

    return g;
}
//fonciton pour afficher un graphe (matrice d'adj)
void affiche(graphe *g){
    for(int i=0;i<g->sommet;i++){
        printf("\n");
        for(int j=0;j<g->sommet;j++){
            printf("%d ",g->adj[i][j]);
        }
    }
    printf("\n");
}
//fonction pour liberer la memeoire allouee
void libererMemoire(graphe *g){
    for(int i=0;i<g->sommet;i++){
        free(g->adj[i]);
    }
    free(g);
}
//fonction pour afficher un tableau
void afficheMarques(int *tab, int taille, char *s){
    printf("\n %s \n", s);
    for(int i=0;i<taille;i++){
        printf(" %d ",tab[i]);
    }
}
// Procédure qui marque tous les sommets par ordre de voisinage depuis un sommet de
// référence
// Paramètres :
// adjacence : matrice d’adjacence du graphe
// ordre : nombre de sommets
// s : numéro du sommet de référence 
void marquerVoisins (int** adjacence, int ordre, int s){
    
    int *marques, *ordreMarquage;
    //marques : tableau dynamique indiquant si les sommets sont marqués ou non
    //ordreMarquage : tableau dynamique indiquant l'ordre de marquage des voisins
    int x, y,indiceMarquage = 1,tousMarques=1; 

    marques = (int *)calloc(ordre, sizeof(int));
    ordreMarquage = (int *)malloc(sizeof(int)*ordre);

    if(!marques){
        perror("Erreur d'allocation memoire.\n");
    }
    //on marque le sommet s
    marques[s] = 1 ;
    ordreMarquage[0] = s;
    //tant que tous les voisins ne sont pas marques on parcours l liste marque et on marque les voisins des sommets marques
    do{
        for (x=0 ; x<ordre && tousMarques<ordre; x++){
            if (marques[x]){
                for (y=0 ; y<ordre; y++){
                    if (adjacence[x][y] && !marques[y]){
                        marques[y] = 1;
                        ordreMarquage[indiceMarquage++] = y;
                        tousMarques++;
                    }
                }
            }
        }
    }while(tousMarques<ordre);
    afficheMarques(ordreMarquage,ordre,"ORDRE DES VOISINS MARQUES");
}

int main(int argc, char *argv[]){
    graphe * test = chargeGraphe();
    affiche(test);
    marquerVoisins(test->adj,test->sommet,2);
    libererMemoire(test);
    return EXIT_SUCCESS;
}