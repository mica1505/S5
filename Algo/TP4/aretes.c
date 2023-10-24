//listes doublement chainees
#include <stdio.h>
#include <stdlib.h>
#include "aretes.h"

void afficheArete(aretes * liste,int ordre){
    //printf("%d %d\n",posListe->p.x,posListe->p.y);
    for(int i=0;i<ordre;i++){
        printf("(%d,%d,poid = %d)\t",liste[i].u,liste[i].v,liste[i].poid);
    }
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