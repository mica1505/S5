#ifndef H_FILES
#define H_FILES


typedef struct cellule{
    struct cellule * pre;
    struct cellule * succ;
    int sommet;
}cel;

cel * file();
void afficheFile(cel * liste);
int estVide(cel *liste);
cel * nouvCell(int u);
void insererCel(cel *liste,int pos, cel *cellule);
void suppCel(int pos, cel ** liste);
int defile(cel ** liste);

#endif