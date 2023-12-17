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
        perror("Probleme de memoire\n");
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
void insererFG(noeud* n,noeud * nvCel){
    noeud * noeudPere = n;
    if(noeudPere!=NULL){
        noeudPere->fg = nvCel;
    }
    else{
        printf("Le noeud parent n'existe pas");
    }
    
}
//fonction pour inserer un fils droit au noeud passe en parametre
void insererFD(noeud* n,noeud * nvCel){
    noeud * noeudPere = n;
    if(noeudPere!=NULL){
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
//ofnction pour creer un arbre recursivement
void arbreRecursif(noeud *racine){
    int fils,fg,fd;
    static char a=98;//la variable a contient le code ascii de la premiere lettre de l'alphabet, pour l'incrementer ensuite et l'attribuer au nouveau noeud cree
    noeud * tmpG, *tmpD;
    //on demande a l'utilisateur si le noeud passe en parametre a des fils
    printf("\nEst-ce que le noeud '%c' a des fils ? (0 : non/1 : oui) ", racine->val);
    scanf("%d",&fils);
    //si il a des fils
    if(fils){
        //on demande si c un fils gaughe
        printf("\nEst-ce que le noeud '%c' a un fils gauche ? (0 : non/1 : oui) ", racine->val);
        scanf("%d",&fg);
        //si oui
        if(fg){
            //on attribue a la variable tmpG un nouveau noeud 
            tmpG = nouvNoeud(a++);
            //le fils gauche de la racine c'est tmpG
            racine->fg = tmpG;
            //on refait appelle a la fonction sur le fils gauche insere
            arbreRecursif(tmpG);
        }
        printf("\nEst-ce que le noeud '%c' a un fils droit ? (0 : non/1 : oui) ", racine->val);
        scanf("%d",&fd);
        if(fd){
            //on attribue a la variable tmpD un nouveau noeud 
            tmpD = nouvNoeud(a++);
            //le fils droit de la racine c'est tmpG
            racine->fd = tmpD;
            //on refait appelle a la fonction sur le fils droit insere
            arbreRecursif(tmpD);
        }
    }
}

int main(){
    noeud * arbre,*fg,*fd;
    int quitter = 0;
    char c,choix;
    noeud * n = nouvNoeud('a');
    arbreRecursif(n);
    printf("\nPacrour prefixe :");
    parcoursPrefixe(n);
    printf("\nPacrour infixe : ");
    parcoursInfixe(n);
    printf("\nPacrour suffixe : ");
    parcoursSuffixe(n);
    libererMemoire(arbre);
    return EXIT_SUCCESS;
}