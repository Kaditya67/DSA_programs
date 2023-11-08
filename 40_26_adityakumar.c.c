#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define Vertices 100

struct Graph {
    int vertices;
    int matrix[Vertices][Vertices];
};

bool visited[Vertices];

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
void addEdge(struct Graph* graph, int start, int end) {
    graph->matrix[start][end] = 1;
    graph->matrix[end][start] = 1;
}

// Function to perform DFS traversal starting from a given vertex
void DFS(struct Graph* graph, int sVertex) {
    printf("%d ", sVertex);
    visited[sVertex] = true;

    // Visit all adjacent vertices of the current vertex
    for (int i = 0; i < graph->vertices; i++) {
        if (graph->matrix[sVertex][i] == 1 && !visited[i]) {
            DFS(graph, i);
        }
    }
}

int main() {
    // Create a graph with 5 vertices
    struct Graph* graph = createGraph(5);

    // Add edges to the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 4);

    // Initialize visited array
    for (int i = 0; i < graph->vertices; i++) {
        visited[i] = false;
    }

    printf("DFS Traversal starting from vertex 0: ");
    DFS(graph, 0);

    return 0;
}