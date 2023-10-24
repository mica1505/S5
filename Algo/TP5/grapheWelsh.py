import networkx as nx
import matplotlib.pyplot as plt

# Create an empty graph
G = nx.Graph()

# Add vertices (nodes) to the graph
G.add_nodes_from([1, 2, 3, 4, 5])

# Add edges to the graph
G.add_edges_from([(1, 2), (2, 3), (3, 4), (4, 5), (5, 1)])

# Draw the graph
nx.draw(G, with_labels=True, node_color='lightblue', edge_color='gray')

# Show the graph
plt.show()

class Graph:
    def __init__(self, vertices):
        self.vertices = vertices
        self.adjMatrix = [[0] * vertices for _ in range(vertices)]

    def add_edge(self, u, v):
        self.adjMatrix[u][v] = 1
        self.adjMatrix[v][u] = 1

    def welsh_powell(self):
        # Initialize the degree of each vertex
        degree = [sum(row) for row in self.adjMatrix]
        # Create a list of (vertex, degree) tuples
        vertices_degrees = [(i, degree[i]) for i in range(self.vertices)]
        # Sort the vertices in decreasing order of degrees
        sorted_vertices = sorted(vertices_degrees, key=lambda x: x[1], reverse=True)

        color = [-1] * self.vertices
        current_color = 0

        # Assign the first color to the first vertex
        color[sorted_vertices[0][0]] = current_color

        # Color the remaining vertices
        for vertex, _ in sorted_vertices[1:]:
            if color[vertex] == -1:
                # Find an uncolored adjacent vertex
                uncolored_adjacent = [adj_vertex for adj_vertex in range(self.vertices) if
                                      self.adjMatrix[vertex][adj_vertex] == 1 and color[adj_vertex] == -1]
                # Assign a different color to the uncolored adjacent vertices
                for adj_vertex in uncolored_adjacent:
                    if not any(self.adjMatrix[adj_vertex][v] == 1 and color[v] == current_color for v in
                               range(self.vertices)):
                        color[vertex] = current_color
                        break
                # If no adjacent vertex has the current color, assign the next color
                if color[vertex] == -1:
                    current_color += 1
                    color[vertex] = current_color

        num_colors = max(color) + 1

        print("Graph colored using {} colors:".format(num_colors))
        for i in range(self.vertices):
            print("Vertex {}: Color {}".format(i, color[i]))

        return num_colors