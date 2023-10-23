#ifndef H_GRAPHE
#define H_GRAPHE

typedef struct graphe
{
    int sommet;
    int aretes;
    int **adj;
}graphe;



graphe * chargeGraphe();
void marquerVoisins (int** adjacence, int ordre, int s);
void afficheGraphe(graphe *g);
void libererMemoire(graphe *g);
void afficheTab(int *tab, int taille, char *s);

#endif