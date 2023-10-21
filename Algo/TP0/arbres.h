#ifndef H_ARBRES
#define H_ARBRES


typedef struct noeud{
    int num;
    char val;
    struct noeud *fg;
    struct noeud *fd;
}noeud;

noeud * nouvNoeud(char carac);
noeud * rechercheNoeud(noeud *n, int numN);
void insererFG(noeud* n,int numN,noeud * nvCel);
void insererFD(noeud* n,int numN,noeud * nvCel);
void parcoursPrefixe(noeud * n);
void parcoursInfixe(noeud * n);
void parcoursSuffixe(noeud * n);
#endif