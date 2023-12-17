//listes doublement chainees
#include <stdio.h>
#include <stdlib.h>
#include "file.h"
 //fonction pour afficher les elements d'une file
void afficheFile(cel * liste){
    cel *posListe = liste;
    //printf("%d %d\n",posListe->p.x,posListe->p.y);
    for(posListe;posListe!=NULL;posListe = posListe->succ){
        printf("%d\t",posListe->sommet,posListe->sommet);
    }
}
//fonction qui retourne une file vide
cel * file(){
    cel *tmp = (cel *)malloc(sizeof(cel));
    if(!tmp){
        perror("Probleme d'allocation memoire");
        return NULL;
    }
    tmp->pre = NULL;
    tmp->succ = NULL;
    //tmp->sommet = (int) NULL;
    return tmp;
}
//fonction qui cree et retourne une nouvelle cellule 
cel * nouvCell(int u){
    cel *tmp = (cel *)malloc(sizeof(cel));
    if(!tmp){
        printf("Probleme d'allocation memoire");
        return 0;
    }
    else{
        tmp->sommet = u;
        tmp->pre = tmp->succ = NULL;
        return tmp;
    }
}
//ofnction qui enfile l'elelemt cellule a la fin de la file
void enfiler(cel *liste,cel *cellule){
    if(!cellule){
        perror("\nLa cellule vaut null\n");
    }
    if(!liste){
        perror("\nLa file est vide\n");
    }
    cel *posListe = liste;
    for(posListe;posListe->succ!=NULL;posListe = posListe->succ);
    cellule->pre = posListe;
    posListe->succ=cellule; 

}
//fonction qui retourne 1 si la file est vde,0 sinon
int estVide(cel *liste){
    if(liste==NULL){
        return 1;
    }
    else{
        return 0;
    }
}
//fonction qui defile le premier element de la file liste
int defile(cel ** liste){
    cel *posListe = *liste;
    int tmp = (*liste)->sommet;

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