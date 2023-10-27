import networkx as nx
import matplotlib.pyplot as plt
"""
LES SOMMETS DES GRPAHES SONT NUMEROTES DE  A NBSOMMET-
"""
class Graph:
    def __init__(self, vertices):
        self.vertices = vertices
        self.adjMatrix = [[0] * vertices for _ in range(vertices)]

    def add_edge(self, u, v):
        self.adjMatrix[u][v] = 1
        self.adjMatrix[v][u] = 1

    def welsh_powell(self):
        # On initialise le degre de chaque sommet
        degree = [sum(row) for row in self.adjMatrix] 
        print("Degre des sommets ",degree)
        # Create une liste de tuples (sommet,degre)
        vertices_degrees = [(i, degree[i]) for i in range(self.vertices)]
        print("Tuples des sommets et leurs degres",vertices_degrees)
        #Tri de la liste des (sommets, degre)
        sorted_vertices = sorted(vertices_degrees, key=lambda x: x[1], reverse=True)
        print("Liste des degres trie : ",sorted_vertices)
        color = [-1] * self.vertices
        current_color = 0

        #On donne la premiere couleur au premier sommet (celui qui a l plus grand nombre d'aretes)
        color[sorted_vertices[0][0]] = current_color

        #On colorie le reste des sommets
        for vertex, _ in sorted_vertices[1:]: #pour un sommet dans la liste des sommets ordonnees
            #si le sommet n'est pas colore on entre dans la boucle
            if color[vertex] == -1:
                # Trouver les sommets adjacents non colores
                uncolored_adjacent = [adj_vertex for adj_vertex in range(self.vertices) if (self.adjMatrix[vertex][adj_vertex] == 1 and color[adj_vertex] == -1)]
                # Donner une couleur differente au sommet adjacent du sommet en cour
                #pour tout sommet adjacent non colore
                for adj_vertex in uncolored_adjacent:
                    #si aucun des visins du voisin n'a la couleur courante
                    if not any(self.adjMatrix[adj_vertex][v] == 1 and color[v] == current_color for v in range(self.vertices)):
                        #alors la couleur du sommet 
                        color[vertex] = current_color
                        break
                #si un sommet non adjacent n'a pas la couleur courante on lui assignie une autre couleur
                if color[vertex] == -1:
                    current_color += 1
                    color[vertex] = current_color

        num_colors = max(color) + 1

        print("Graph colored using {} colors:".format(num_colors))
        for i in range(self.vertices):
            print("Vertex {}: Color {}".format(i, color[i]))

        return num_colors
    
def createGraph():
    nbSommet = int(input("Entrez le nombre de sommets du graphe : "))
    tmpG = Graph(nbSommet)
    # Create an empty graph

    nbAretes = int(input("Entrez le nombre d'aretes du graphe : "))
    aretes = []

    for i in range(nbAretes):
        inputSommets = input("Entrez les 2 sommets adjacents, separes par un espace :  ")
        u , v = map(int, inputSommets.split())
        tmpG.add_edge(u,v)
        aretes.append((u,v))

    """
    GRAPHIQUE
    """
    # Add edges to the graph
    G = nx.Graph()

    # Add vertices (nodes) to the graph
    G.add_nodes_from([i for i in range(0,tmpG.vertices)])
    G.add_edges_from(aretes)

    # Draw the graph
    nx.draw(G, with_labels=True, node_color='lightblue', edge_color='red')

    # Show the graph
    plt.show()
    return tmpG


graph = createGraph()
print(graph.welsh_powell())