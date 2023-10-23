#include <stdio.h>
#include <stdlib.h>

#include "graphe.h"

graphe * chargeGraphe(){

    int n,m;
    graphe *g = (graphe *)malloc(sizeof(graphe));

    if(!g){
        perror("Erreur d'allocation memoire.\n");
        return NULL;
    }

    printf("Entrez le nombre de sommets du graphe : ");
    scanf("%d",&g->sommet);

    g->adj = (int **)malloc(g->sommet * sizeof(int));

    if(!g->adj){
        perror("Erreur d'allocation memoire.\n");
        return NULL;
    }

    for(int i=0;i<g->sommet;i++){
        g->adj[i] = (int *)calloc(g->sommet, sizeof(int));
        if(!g->adj[i]){
            perror("Erreur d'allocation memoire.\n");
            return NULL;
        }
    }

    
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

void afficheGraphe(graphe *g){
    for(int i=0;i<g->sommet;i++){
        printf("\n");
        for(int j=0;j<g->sommet;j++){
            printf("%d ",g->adj[i][j]);
        }
    }
    printf("\n");
}

void libererMemoire(graphe *g){
    for(int i=0;i<g->sommet;i++){
        free(g->adj[i]);
    }
    free(g);
}

void afficheTab(int *tab, int taille, char *s){
    printf("\n %s \n", s);
    for(int i=0;i<taille;i++){
        printf(" %d ",tab[i]);
    }
}

void marquerVoisins (int** adjacence, int ordre, int s){
    int *marques, *ordreMarquage;
    int x, y,indiceMarquage = 1,tousMarques=1; 

    marques = (int *)calloc(ordre, sizeof(int));
    ordreMarquage = (int *)malloc(sizeof(int)*ordre);

    if(!marques){
        perror("Erreur d'allocation memoire.\n");
    }
    
    marques[s] = 1 ;
    ordreMarquage[0] = s;
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
    afficheTab(ordreMarquage,ordre,"ORDRE DES VOISINS MARQUES");
}

/*int main(int argc, char *argv[]){
    graphe * test = chargeGraphe();
    afficheGraphe(test);
    marquerVoisins(test->adj,test->sommet,1);
    libererMemoire(test);
    return EXIT_SUCCESS;
}*/