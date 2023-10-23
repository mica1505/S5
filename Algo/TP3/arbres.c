#include <stdio.h>
#include <stdlib.h>
#include "arbres.h"


noeud * nouvNoeud(char carac){
    static int nb = 0;
    noeud * nv = (noeud *)malloc(sizeof(noeud));
    if(nv!=NULL){
        nv->val = carac;
        nv->num = nb++;
        nv->fg = NULL;
        nv->fd = NULL;
        //printf("NODE CREATED\n");
    }
    else{
        printf("Probleme de memoire\n");
    }
    return nv;
}

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

void parcoursPrefixe(noeud * n){
    if(n!=NULL){
        printf(" %c ",n->val);
        parcoursPrefixe(n->fg);
        parcoursPrefixe(n->fd);
    }
}

void parcoursInfixe(noeud * n){
    if(n!=NULL){
        parcoursInfixe(n->fg);
        printf(" %c ",n->val);
        parcoursInfixe(n->fd);
    }
}

void parcoursSuffixe(noeud * n){
    if(n!=NULL){
        parcoursSuffixe(n->fg);
        parcoursSuffixe(n->fd);
        printf(" %c ",n->val);
    }
}

//rajouter le parcours infixe et suffixe
int main(){
    noeud * racine = nouvNoeud('a');
    /*
    faut le faire recursivement : 
        -on demande a l'utilisateur d'inserer un noeud (racine) et on lui demande si il veut un FG ou un FD
        -on lui demande si c une feuille : 
            - si oui on rajoute rien
            - sinon on rappelle la meme fonction
    */
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
    free(racine);
    return EXIT_SUCCESS;
}