class Graph:
    def __init__(self, vertices):
        self.vertices = vertices
        self.adjMatrix = [[0] * vertices for _ in range(vertices)]

    def add_edge(self, u, v):
        self.adjMatrix[u][v] = 1
        self.adjMatrix[v][u] = 1

    def is_safe(self, v, color, c):
        for i in range(self.vertices):
            if self.adjMatrix[v][i] == 1 and color[i] == c:
                return False
        return True

    def graph_coloring_util(self, m, color, v):
        if v == self.vertices:
            return True

        for c in range(1, m+1):
            if self.is_safe(v, color, c):
                color[v] = c
                if self.graph_coloring_util(m, color, v+1):
                    return True
                color[v] = 0

    def graph_coloring(self, m):
        color = [0] * self.vertices
        if not self.graph_coloring_util(m, color, 0):
            return False

        print("Graph can be colored using {} colors:".format(m))
        for i in range(self.vertices):
            print("Vertex {}: Color {}".format(i, color[i]))

        return True

'''
To use this code, you can create a `Graph` object, add edges, and call the `graph_coloring` method to find a valid graph coloration. Here's an example usage:
'''

g = Graph(5)

g.add_edge(0, 1)
g.add_edge(0, 2)
g.add_edge(1, 2)
g.add_edge(1, 3)
g.add_edge(2, 3)
g.add_edge(3, 4)

m = 3  # Number of colors
g.graph_coloring(m)