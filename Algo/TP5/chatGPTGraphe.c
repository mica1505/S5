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
    int degree[MAX_VERTICES] = {0};
    int i, j, current_color;

    // Calculate the degree of each vertex
    for (i = 0; i < graph->vertices; i++) {
        for (j = 0; j < graph->vertices; j++) {
            if (graph->adjMatrix[i][j] == 1)
                degree[i]++;
        }
    }

    int sorted_vertices[MAX_VERTICES];

    // Initialize vertices in sorted order of degrees
    for (i = 0; i < graph->vertices; i++)
        sorted_vertices[i] = i;
    
    // Sort vertices in decreasing order of degree using bubble sort
    for (i = 0; i < graph->vertices - 1; i++) {
        for (j = 0; j < graph->vertices - i - 1; j++) {
            if (degree[sorted_vertices[j]] < degree[sorted_vertices[j + 1]]) {
                int temp = sorted_vertices[j];
                sorted_vertices[j] = sorted_vertices[j + 1];
                sorted_vertices[j + 1] = temp;
            }
        }
    }

    int color[MAX_VERTICES] = {-1};

    current_color = 0;
    color[sorted_vertices[0]] = current_color;

    // Assign colors to the remaining vertices
    for (i = 1; i < graph->vertices; i++) {
        int vertex = sorted_vertices[i];
        if (color[vertex] == -1) {
            int uncolored_adjacent = 1;
            for (j = 0; j < graph->vertices; j++) {
                if (graph->adjMatrix[vertex][j] == 1 && color[j] == current_color) {
                    uncolored_adjacent = 0;
                    break;
                }
            }
            // Assign a different color to the uncolored adjacent vertices
            if (uncolored_adjacent) {
                color[vertex] = current_color;
            } else {
                current_color++;
                color[vertex] = current_color;
            }
        }
    }

    int num_colors = current_color + 1;

    printf("Graph colored using %d colors:\n", num_colors);
    for (i = 0; i < graph->vertices; i++) {
        printf("Vertex %d: Color %d\n", i, color[i]);
    }
}

int main() {
    struct Graph graph;
    graph.vertices = 5;

    // Add edges
    addEdge(&graph, 0, 1);
    addEdge(&graph, 0, 2);
    addEdge(&graph, 1, 2);
    addEdge(&graph, 1, 3);
    addEdge(&graph, 2, 3);
    addEdge(&graph, 3, 4);

    welshPowell(&graph);

    return 0;
}