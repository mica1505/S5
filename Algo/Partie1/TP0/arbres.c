#include <stdio.h>
#include <stdlib.h>
#include "arbres.h"

//fonction pour creer et renvoyer une nouvelle cellule dont le fils gauche et droit vaut null
noeud * nouvNoeud(char carac){
    static int nb = 0;
    noeud * nv = (noeud *)malloc(sizeof(noeud));
    if(nv!=NULL){
        nv->val = carac;
        nv->num = nb++;
        nv->fg = NULL;
        nv->fd = NULL;
    }
    else{
        printf("Probleme de memoire\n");
    }
    return nv;
}
//fonctin pour rechercher un noeud
noeud * rechercheNoeud(noeud *n, int numN){
    noeud * tmpNoeud;
    if(n== NULL){
        return NULL;
    }
    if(n->num == numN){
        return n;
    }
    tmpNoeud = rechercheNoeud(n->fg,numN);
    if(tmpNoeud!=NULL){
        return tmpNoeud;
    }
    return rechercheNoeud(n->fd,numN);
}
//fonction pour inserer un fils gauche au noeud passe en parametre
void insererFG(noeud* n,int numN,noeud * nvCel){
    noeud * noeudPere = rechercheNoeud(n,numN);
    if(noeudPere!=NULL){
        nvCel->fg = noeudPere->fg;
        noeudPere->fg = nvCel;
    }
    else{
        printf("Le noeud parent n'existe pas");
    }
    
}
//fonction pour inserer un fils droit
void insererFD(noeud* n,int numN,noeud * nvCel){
    noeud * noeudPere = rechercheNoeud(n,numN);
    if(noeudPere!=NULL){
        nvCel->fd = noeudPere->fd;
        noeudPere->fd = nvCel;
    }
    else{
        printf("Le noeud parent n'existe pas");
    }
    
}
//Parcours prefixe
void parcoursPrefixe(noeud * n){
    if(n!=NULL){
        printf(" %c ",n->val);
        parcoursPrefixe(n->fg);
        parcoursPrefixe(n->fd);
    }
}
//Parcours infixe
void parcoursInfixe(noeud * n){
    if(n!=NULL){
        parcoursInfixe(n->fg);
        printf(" %c ",n->val);
        parcoursInfixe(n->fd);
    }
}
//Parcours suffixe
void parcoursSuffixe(noeud * n){
    if(n!=NULL){
        parcoursSuffixe(n->fg);
        parcoursSuffixe(n->fd);
        printf(" %c ",n->val);
    }
}
//Liberer la memoire allouee
void libererMemoire(noeud *n){
    if(n->fg == NULL && n->fd == NULL){
        free(n);
    }
    else{
        libererMemoire(n->fg);
        libererMemoire(n->fd);
    }
}
//rajouter le parcours infixe et suffixe
int main(){
    noeud * racine = nouvNoeud('a');

    insererFG(racine,0,nouvNoeud('b'));
    insererFD(racine,0,nouvNoeud('c'));
    insererFD(racine,2,nouvNoeud('d'));

    printf("Parcours prefixe : ");
    parcoursPrefixe(racine);
    printf("\n");

    printf("Parcours infixe : ");
    parcoursInfixe(racine);
    printf("\n");

    printf("Parcours suffixe : ");
    parcoursSuffixe(racine);
    printf("\n");
    libererMemoire(racine);
    return EXIT_SUCCESS;
}