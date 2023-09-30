//listes doublement chainees
#include <stdio.h>
#include <stdlib.h>

typedef struct point{
    int x,y;
}point;

typedef struct cellule{
    struct cellule * pre;
    struct cellule * succ;
    point p;
}cel;


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

void insererCel(cel *liste,int pos, cel *cellule){
    cel *posListe = liste;
    int k;
    for(k=1;k<pos;k++,posListe=posListe->succ);
    printf("-- k : %d -- \n", k);
    cellule->succ = posListe->succ;
    cellule->pre = posListe;
    if(posListe->succ!=NULL){
        (cellule->succ)->pre = cellule;
    }
    posListe->succ=cellule;  
}

void afficher(cel * liste){
    cel *posListe = liste;
    //printf("%d %d\n",posListe->p.x,posListe->p.y);
    for(posListe;posListe!=NULL;posListe = posListe->succ){
        printf("%d %d\n",posListe->p.x,posListe->p.y);
    }
}

int main(){
    point p,p2;
    p.x = 1;
    p.y = 2; 

    cel * ajoutCel = nouvCell(p);
    afficher(ajoutCel);
    printf("//\n");
    p2.x = 4;
    p2.y = 5;
    cel * nvpoint = nouvCell(p2);
    afficher(nvpoint);
    printf("//\n");
    insererCel(ajoutCel,1,nvpoint);
    //ajoutCel->succ = nvpoint;
    afficher(ajoutCel);

    free(ajoutCel);
    free(nvpoint);
    return EXIT_SUCCESS;
}