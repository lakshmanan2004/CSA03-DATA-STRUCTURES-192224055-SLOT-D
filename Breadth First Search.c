#include <stdio.h>
#include <stdlib.h>

// Maximum number of vertices
#define MAX_VERTICES 100

// Queue data structure
typedef struct {
    int items[MAX_VERTICES];
    int front;
    int rear;
} Queue;

// Graph data structure
typedef struct {
    int vertices;
    int** adjacencyMatrix;
} Graph;

// Create a new queue
Queue* createQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Check if the queue is empty
int isEmpty(Queue* queue) {
    return queue->front == -1;
}

// Enqueue an item
void enqueue(Queue* queue, int item) {
    if (queue->rear == MAX_VERTICES - 1) {
        printf("Queue is full\n");
    } else {
        if (queue->front == -1) {
            queue->front = 0;
        }
        queue->rear++;
        queue->items[queue->rear] = item;
    }
}

// Dequeue an item
int dequeue(Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty\n");
        item = -1;
    } else {
        item = queue->items[queue->front];
        queue->front++;
        if (queue->front > queue->rear) {
            queue->front = queue->rear = -1;
        }
    }
    return item;
}

// Create a new graph with 'vertices' number of vertices
Graph* createGraph(int vertices) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->adjacencyMatrix = (int**)malloc(vertices * sizeof(int*));
    for (int i = 0; i < vertices; i++) {
        graph->adjacencyMatrix[i] = (int*)calloc(vertices, sizeof(int));
    }
    return graph;
}

// Add an edge between two vertices
void addEdge(Graph* graph, int src, int dest) {
    graph->adjacencyMatrix[src][dest] = 1;
    graph->adjacencyMatrix[dest][src] = 1;
}

// Breadth First Search traversal of the graph
void bfs(Graph* graph, int startVertex) {
    Queue* queue = createQueue();
    int visited[MAX_VERTICES] = {0};

    visited[startVertex] = 1;
    printf("Breadth First Search starting from vertex %d:\n", startVertex);

    enqueue(queue, startVertex);

    while (!isEmpty(queue)) {
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        for (int i = 0; i < graph->vertices; i++) {
            if (graph->adjacencyMatrix[currentVertex][i] == 1 && !visited[i]) {
                enqueue(queue, i);
                visited[i] = 1;
            }
        }
    }

    printf("\n");
}

int main() {
    int vertices, edges;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    Graph* graph = createGraph(vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int src, dest;
        printf("Enter edge %d (source destination): ", i + 1);
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int startVertex;
    printf("Enter the starting vertex for BFS: ");
    scanf("%d", &startVertex);

    bfs(graph, startVertex);

    return 0;
}

