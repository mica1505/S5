//listes doublement chainees
#include <stdio.h>
#include <stdlib.h>
#include "aretes.h"

void afficheFile(aretes * liste){
    aretes *posListe = liste;
    //printf("%d %d\n",posListe->p.x,posListe->p.y);
    for(posListe;posListe!=NULL;posListe = posListe->succ){
        printf("(%d,%d,poir = %d)\t",posListe->u,posListe->v,posListe->poid);
    }
}
aretes * nouvCell(int u,int v,int poid){
    aretes *tmp = (aretes *)malloc(sizeof(aretes));
    if(!tmp){
        printf("Probleme d'allocation memoire");
        return 0;
    }
    else{
        tmp->u = u;
        tmp->v = v;
        tmp->poid = poid;
        tmp->pre = tmp->succ = NULL;
        return tmp;
    }
}

void enfiler(aretes *liste,aretes *cellule){
    if(!cellule){
        perror("\nLa cellule vaut null\n");
    }
    if(!liste){
        perror("\nLa file est vide\n");
    }
    aretes *posListe = liste;
    for(posListe;posListe->succ!=NULL;posListe = posListe->succ);
    cellule->pre = posListe;
    posListe->succ=cellule; 

}
int estVide(aretes *liste){
    if(liste==NULL){
        return 1;
    }
    else{
        return 0;
    }
}

aretes * defile(aretes ** liste){
    aretes *posListe = *liste;
    aretes * tmp = (*liste);

    *liste = (posListe)->succ;
    free(posListe);
    if(estVide(*liste)){
        printf("\nFILE VIDE\n");
    }
    return tmp;
}

/*int main(){
    //menu 
    char choix;
    int quitter= 0;
    cel * poly,* nvPoint;

    poly = nouvCell(1);
    afficher(poly);
    printf("\n");

    enfiler(poly,nouvCell(2));
    afficher(poly);
    printf("\n");

    enfiler(poly,nouvCell(3)); 
    afficher(poly);
    printf("\n");

    printf("\nSUPPRESSION %d : \n",defile(&poly));
    
    afficher(poly);

    printf("\nSUPPRESSION %d : \n",defile(&poly));
    
    afficher(poly);
    printf("\n");
    
    printf("\nSUPPRESSION %d : \n",defile(&poly));
    
    afficher(poly);
    printf("est vide %d\n",estVide(poly));

    return EXIT_SUCCESS;
}*/