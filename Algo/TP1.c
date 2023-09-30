//listes doublement chainees
#include <stdio.h>
#include <stdlib.h>

typedef struct point{
    float x,y;
}point;

typedef struct poly{
    float* pre;
    float* succ;
    point p;
}poly;


int main(){
    
    return EXIT_SUCCESS;
}