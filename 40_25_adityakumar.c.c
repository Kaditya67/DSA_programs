#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define Vertices 100

// Structure for the queue used in BFS
struct Queue {
    int items[Vertices];
    int front;
    int rear;
};

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = -1;
    queue->rear = -1;
    return queue;
}

// Function to check if the queue is empty
bool isEmpty(struct Queue* queue) {
    return queue->rear == -1;
}

// Function to add an item to the queue
void enqueue(struct Queue* queue, int value) {
    if (queue->rear == Vertices - 1)
        printf("Queue is full");
    else {
        if (queue->front == -1)
            queue->front = 0;
        queue->rear++;
        queue->items[queue->rear] = value;
    }
}

// Function to remove an item from the queue
int dequeue(struct Queue* queue) {
    int item;
    if (isEmpty(queue)) {
        printf("Queue is empty");
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

// Structure to represent the graph
struct Graph {
    int vertices;
    int matrix[Vertices][Vertices];
};

// Function to create a new graph with given number of vertices
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;

    // Initialize the adjacency matrix with zeros
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph->matrix[i][j] = 0;
        }
    }
    return graph;
}

// Function to add an edge between two vertices in the graph
void addEdge(struct Graph* graph, int src, int dest) {
    graph->matrix[src][dest] = 1;
    graph->matrix[dest][src] = 1;
}

// Function to perform BFS traversal starting from a given vertex
void BFS(struct Graph* graph, int startVertex) {
    struct Queue* queue = createQueue();
    bool visited[Vertices];

    // Mark all vertices as not visited
    for (int i = 0; i < graph->vertices; i++) {
        visited[i] = false;
    }

    // Mark the current vertex as visited and enqueue it
    visited[startVertex] = true;
    printf("BFS Traversal starting from vertex %d: ", startVertex);
    enqueue(queue, startVertex);

    while (!isEmpty(queue)) {
        // Dequeue a vertex from the queue and print it
        int currentVertex = dequeue(queue);
        printf("%d ", currentVertex);

        // Enqueue all adjacent vertices of the dequeued vertex that have not been visited yet
        for (int i = 0; i < graph->vertices; i++) {
            if (graph->matrix[currentVertex][i] == 1 && !visited[i]) {
                enqueue(queue, i);
                visited[i] = true;
            }
        }
    }
}

// Main function to test the BFS traversal
int main() {
    // Create a graph with 5 vertices
    struct Graph* graph = createGraph(5);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    int startVertex = 0;
    BFS(graph, startVertex); // Perform BFS traversal starting from vertex 0

    return 0;
}