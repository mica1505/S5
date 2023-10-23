#ifndef H_ARETES
#define H_ARETES


typedef struct cellule{
    struct cellule * pre;
    struct cellule * succ;
    int u,v,poid;
}aretes;

void afficheFile(aretes * liste);
int estVide(aretes *liste);
aretes * nouvCell(int u,int v,int poid);
void insererCel(aretes *liste,int pos, aretes *cellule);
void suppCel(int pos, aretes ** liste);
aretes * defile(aretes ** liste);

#endif