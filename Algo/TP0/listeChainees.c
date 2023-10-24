//listes doublement chainees
#include <stdio.h>
#include <stdlib.h>
#include "listeChainees.h"


void afficher(cel * liste){
    cel *posListe = liste;
    //printf("%d %d\n",posListe->p.x,posListe->p.y);
    for(posListe;posListe!=NULL;posListe = posListe->succ){
        printf("%d %d\n",posListe->p.x,posListe->p.y);
    }
}
cel * nouvCell(point p){
    cel *tmp = (cel *)malloc(sizeof(cel));
    if(!tmp){
        printf("Probleme d'allocation memoire");
        return 0;
    }
    else{
        tmp->p = p;
        tmp->pre = tmp->succ = NULL;
        return tmp;
    }
}
//indexation commence a 1
//on insere a la position apres pos
void insererCel(cel *liste,int pos, cel *cellule){
    cel *posListe = liste;
    int k;
    for(k=1;k<pos;k++,posListe=posListe->succ);
    cellule->succ = posListe->succ;
    cellule->pre = posListe;
    if(posListe->succ!=NULL){
        (cellule->succ)->pre = cellule;
    }
    posListe->succ=cellule;  
}

void suppCel(int pos, cel ** liste){
    //on peut pas supprimer le premier element de la liste, on le suprime on perd le debut de la liste.
    cel *posListe = *liste;
    int i;
    if(pos == 1){
        *liste = (posListe)->succ;
    }
    else{
        for(i=1;i<pos;i++,posListe = posListe->succ);
        if(posListe->succ==NULL){
            posListe->pre->succ = NULL;
        }
        else{
            posListe->succ->pre = posListe->pre;
            posListe->pre->succ = posListe->succ;
        }
        //free(posListe);
    }
}

void defile(cel ** liste){
    cel *posListe = *liste;
    *liste = (posListe)->succ;
    afficher(*liste);
}

void menu(){
    char choix;
    int quitter= 0;
    int pos = 0;
    cel * poly,* nvPoint;

    point p1;
    printf("\nEntrez x : ");
    scanf("%d",&p1.x);
    printf("\nEntrez y : ");
    scanf("%d",&p1.y);

    poly = nouvCell(p1);
    afficher(poly);
    printf("\n");
    while(!quitter){
        printf("Que voulez vous faire? (i->inserer, s->supprimer, q->quitter) ");
        scanf("%s",&choix);
        switch (choix) {
            case 'i':
                printf("insertion de point\n");
                point p;
                int pos;

                printf("\nEntrez l'indice dans lequel vous voulez inserer le point : ");
                scanf("%d", &pos);

                printf("\nEntrez x : ");
                scanf("%d", &p.x);

                printf("\nEntrez y : ");
                scanf("%d", &p.y);

                nvPoint = nouvCell(p);
                insererCel(poly,pos,nvPoint);
                afficher(poly);
                break;
            case 's':
                printf("\nsuppresison de point\n");
                int ind;
                printf("\nEntrez l'indice du point que vous voulez supprimer : ");
                scanf("%d", &ind);
                suppCel(ind,&poly);
                afficher(poly);
                break;
            case 'q':
                afficher(poly);
                printf("QUITTER\n");
                //pour free faut free toute la memoire et pas que la premiere case !!!!!
                free(poly);
                quitter = 1;
        }
}
}

int main(){
    //menu 
    cel * poly,* nvPoint;

    point p1,p2,p3;
    p1.x = 1;p1.y =2;

    poly = nouvCell(p1);
    afficher(poly);
    printf("\n");

    p2.x =3; p2.y=4;
    insererCel(poly,1,nouvCell(p2));
    afficher(poly);
    printf("\n");

    p3.x=5;p3.y=6;
    insererCel(poly,2,nouvCell(p3)); 
    insererCel(poly,1,nouvCell(p1));
    afficher(poly);
    printf("\n");

    printf("\nSUPPRESSION\n");
    suppCel(3,&poly);
    //defile(&poly);
    afficher(poly);
    printf("\n");
    //pour free
    cel * finListe;
    for(cel * posListe = poly->succ; posListe->succ!=NULL;posListe = posListe->succ){
        printf("hello");
        free(posListe->pre);
    }
    return EXIT_SUCCESS;
}