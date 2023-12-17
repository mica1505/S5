//listes doublement chainees
#include <stdio.h>
#include <stdlib.h>
#include "aretes.h"
//ofnction pour afficher les aretes contenues dans la liste passee en parametre
void afficheArete(aretes * liste,int nbAretes){
    for(int i=0;i<nbAretes;i++){
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