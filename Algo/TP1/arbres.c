#include <stdio.h>
#include <stdlib.h>

typedef struct noeud{
    int num;
    char val;
    struct noeud fg;
    struct noeud fd;
}noeud;

noeud * nouvNoeud(char carac){
    static int nb = 0;
    noeud * nv = (noeud *)malloc(sizeof(noeud));
    nv->val = carac;
    nv->num = ++nb;
    nv->fg = NULL;
    nv->fd = NULL;
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
    if(noeudPere->fg!=NULL){
        nvCel->fg = noeudPere->fg;
    }
    noeudPere->fg = nvCel;
}

void parcoursPrefixe(noeud * n){
    if(n!=NULL){
        printf("%s\n",n->val);
    }
    parcoursPrefixe(n->fg);
    parcoursPrefixe(n->fd);
}

int main(){
    printf("VTF");
    return EXIT_SUCCESS;
}