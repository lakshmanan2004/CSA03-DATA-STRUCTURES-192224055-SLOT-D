#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Edge data structure
typedef struct {
    int src, dest, weight;
} Edge;

// Graph data structure
typedef struct {
    int vertices, edges;
    Edge edge[MAX_VERTICES];
} Graph;

// Initialize a graph with 'vertices' number of vertices and 'edges' number of edges
void initGraph(Graph* graph, int vertices, int edges) {
    graph->vertices = vertices;
    graph->edges = edges;
}

// Compare function used for sorting edges based on weights
int compareEdges(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

// Find the parent of a vertex in the disjoint-set
int findParent(int parent[], int vertex) {
    if (parent[vertex] == -1) {
        return vertex;
    }
    return findParent(parent, parent[vertex]);
}

// Union of two sets of vertices
void unionSets(int parent[], int x, int y) {
    int xRoot = findParent(parent, x);
    int yRoot = findParent(parent, y);
    parent[xRoot] = yRoot;
}

// Kruskal's algorithm for finding Minimum Spanning Tree
void kruskalMST(Graph* graph) {
    Edge result[MAX_VERTICES];
    int parent[MAX_VERTICES];

    qsort(graph->edge, graph->edges, sizeof(graph->edge[0]), compareEdges);

    for (int i = 0; i < graph->vertices; i++) {
        parent[i] = -1;
    }

    int mstEdges = 0;
    int i = 0;

    while (mstEdges < graph->vertices - 1) {
        Edge currentEdge = graph->edge[i];

        int x = findParent(parent, currentEdge.src);
        int y = findParent(parent, currentEdge.dest);

        if (x != y) {
            result[mstEdges++] = currentEdge;
            unionSets(parent, x, y);
        }

        i++;
    }

    printf("Edges in the Minimum Spanning Tree:\n");
    for (int i = 0; i < mstEdges; i++) {
        printf("%d - %d, Weight: %d\n", result[i].src, result[i].dest, result[i].weight);
    }
}

int main() {
    int vertices, edges;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    Graph graph;
    initGraph(&graph, vertices, edges);

    for (int i = 0; i < edges; i++) {
        printf("Enter edge %d (source destination weight): ", i + 1);
        scanf("%d %d %d", &graph.edge[i].src, &graph.edge[i].dest, &graph.edge[i].weight);
    }

    kruskalMST(&graph);

    return 0;
}
