#include <stdio.h>
#define MAX_VERTICES 100

struct Graph {
    int vertices;
    int adjMatrix[MAX_VERTICES][MAX_VERTICES];
};

void addEdge(struct Graph* graph, int u, int v) {
    graph->adjMatrix[u][v] = 1;
    graph->adjMatrix[v][u] = 1;
}

void welshPowell(struct Graph* graph) {
    //initialisation de la liste des degres de chaque sommet i
    int degree[MAX_VERTICES] = {0};
    int i, j, current_color,nb_couleurs = 1,k,reuse_color;
    int used_colors[MAX_VERTICES] = {0};

    // Calcule le degre de chaque sommet
    for (i = 0; i < graph->vertices; i++) {
        for (j = 0; j < graph->vertices; j++) {
            if (graph->adjMatrix[i][j] == 1)
                degree[i]++;
        }
    }

    int sorted_vertices[MAX_VERTICES];

    //on initialise la liste des degres en ordre decroissant
    for (i = 0; i < graph->vertices; i++)
        sorted_vertices[i] = i;
    
    // On utilise le tri a bule pour trier la liste des degres en ordre decroissant
    for (i = 0; i < graph->vertices - 1; i++) {
        for (j = 0; j < graph->vertices - i - 1; j++) {
            if (degree[sorted_vertices[j]] < degree[sorted_vertices[j + 1]]) {
                int temp = sorted_vertices[j];
                sorted_vertices[j] = sorted_vertices[j + 1];
                sorted_vertices[j + 1] = temp;
            }
        }
    }
    //affichage des sommets tries
    printf("\nLISTE DES DEGRES EN ORDRE DECROISSANT\n");
    for(int l=0;l<graph->vertices;l++){
        printf(" %d ",sorted_vertices[l]);
    }

    int color[MAX_VERTICES] = {0};

    current_color = 0;

    for(int l=0;l<graph->vertices;l++){
        color[l] = -1;
    }

    color[sorted_vertices[0]] = current_color;

    // on attribue des couleurs aux sommets
    for (i = 1; i < graph->vertices; i++) {
        //on recupere le sommet qu'on veut colorer dans la variable vertex
        int vertex = sorted_vertices[i];
        //si le sommet n'a pas ete colore on verifie si l'un de ses voisins a la couleur courante
        if (color[vertex] == -1) {
            int uncolored_adjacent = 1;
            //on verifie les voisins du sommet en cour
            for (j = 0; j < graph->vertices; j++) {
                //on sauvegarde les couleurs des voisins
                if (graph->adjMatrix[vertex][j] == 1 && (color[j] != -1)) {
                    used_colors[color[j]] = 1;
                }
            }

            reuse_color = 0;
            //on choisit la couleur non utilisee par les voisins
            for(k=0;k<nb_couleurs;k++){
                if(!used_colors[k]){
                    reuse_color = k+1;
                    break;
                }
            }
            //si ya une couleur qui n'a pas ete utilisee
            if(reuse_color){
                color[vertex] = reuse_color-1;
                for(k=0;k<nb_couleurs;k++){
                    used_colors[k] = 0;
                }
            }
            else{
                color[vertex] = nb_couleurs;
                for(k=0;k<nb_couleurs;k++){
                    used_colors[k] = 0;
                }
                nb_couleurs++;
            }
            
        }
    }

    printf("\nGraph colored using %d colors: \n", nb_couleurs);
    for (i = 0; i < graph->vertices; i++) {
        printf("Vertex %d: Color %d\n", i, color[i]);
    }
    
}

int main() {
    struct Graph graph;
    graph.vertices = 5;

    // Add edges
    //2 colorable
    /*addEdge(&graph, 0, 1);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 4);
    addEdge(&graph, 4, 5);
    addEdge(&graph,5,0);*/
   
   //jsp combien colorable
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 4);

    welshPowell(&graph);

    return 0;
}