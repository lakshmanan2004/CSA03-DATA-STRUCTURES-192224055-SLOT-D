#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_VERTICES 100

// Graph data structure
typedef struct {
    int vertices;
    int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Initialize a graph with 'vertices' number of vertices
void initGraph(Graph* graph, int vertices) {
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->adjacencyMatrix[i][j] = (i == j) ? 0 : INT_MAX;
        }
    }
}

// Add an edge between two vertices with weight 'weight'
void addEdge(Graph* graph, int src, int dest, int weight) {
    graph->adjacencyMatrix[src][dest] = weight;
}

// Find the vertex with the minimum distance value
int minDistance(int dist[], bool visited[], int vertices) {
    int min = INT_MAX, minIndex;

    for (int v = 0; v < vertices; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}

// Print the shortest paths from source vertex to all vertices
void printShortestPaths(int dist[], int vertices, int source) {
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < vertices; i++) {
        printf("%d\t%d\n", i, dist[i]);
    }
}

// Dijkstra's algorithm for finding shortest paths
void dijkstra(Graph* graph, int source) {
    int dist[MAX_VERTICES];
    bool visited[MAX_VERTICES];

    for (int i = 0; i < graph->vertices; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[source] = 0;

    for (int count = 0; count < graph->vertices - 1; count++) {
        int u = minDistance(dist, visited, graph->vertices);

        visited[u] = true;

        for (int v = 0; v < graph->vertices; v++) {
            if (!visited[v] && graph->adjacencyMatrix[u][v] != INT_MAX && dist[u] != INT_MAX &&
                dist[u] + graph->adjacencyMatrix[u][v] < dist[v]) {
                dist[v] = dist[u] + graph->adjacencyMatrix[u][v];
            }
        }
    }

    printShortestPaths(dist, graph->vertices, source);
}

int main() {
    int vertices, edges;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    Graph graph;
    initGraph(&graph, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int src, dest, weight;
        printf("Enter edge %d (source destination weight): ", i + 1);
        scanf("%d %d %d", &src, &dest, &weight);
        addEdge(&graph, src, dest, weight);
    }

    int source;
    printf("Enter the source vertex: ");
    scanf("%d", &source);

    dijkstra(&graph, source);

    return 0;
}
