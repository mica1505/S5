#ifndef H_LiSTES
#define H_LISTES


typedef struct point{
    int x,y;
}point;

typedef struct cellule{
    struct cellule * pre;
    struct cellule * succ;
    point p;
}cel;


void afficher(cel * liste);
cel * nouvCell(point p);
void insererCel(cel *liste,int pos, cel *cellule);
void suppCel(int pos, cel ** liste);
void defile(cel ** liste);

#endif