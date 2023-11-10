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


// #include <stdio.h>
// #include <stdbool.h>
// #include <stdlib.h>

// #define Vertices 100

// struct Graph {
//     int vertices;
//     int matrix[Vertices][Vertices];
// };

// bool visited[Vertices];

// struct Stack {
//     int items[Vertices];
//     int top;
// };

// // Function to initialize a stack
// struct Stack* createStack() {
//     struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
//     stack->top = -1;
//     return stack;
// }

// // Function to check if the stack is empty
// bool isEmpty(struct Stack* stack) {
//     return stack->top == -1;
// }

// // Function to push an item onto the stack
// void push(struct Stack* stack, int value) {
//     stack->top++;
//     stack->items[stack->top] = value;
// }

// // Function to pop an item from the stack
// int pop(struct Stack* stack) {
//     int item;
//     if (isEmpty(stack)) {
//         printf("Stack is empty");
//         item = -1;
//     } else {
//         item = stack->items[stack->top];
//         stack->top--;
//     }
//     return item;
// }

// // Function to create a new graph with given number of vertices
// struct Graph* createGraph(int vertices) {
//     struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
//     graph->vertices = vertices;

//     // Initialize the adjacency matrix with zeros
//     for (int i = 0; i < vertices; i++) {
//         for (int j = 0; j < vertices; j++) {
//             graph->matrix[i][j] = 0;
//         }
//     }
//     return graph;
// }

// // Function to add an edge between two vertices in the graph
// void addEdge(struct Graph* graph, int start, int end) {
//     graph->matrix[start][end] = 1;
//     graph->matrix[end][start] = 1;
// }

// // Function to perform DFS traversal starting from a given vertex
// void DFS(struct Graph* graph, int sVertex) {
//     struct Stack* stack = createStack();

//     printf("DFS Traversal starting from vertex %d: ", sVertex);
//     push(stack, sVertex);

//     while (!isEmpty(stack)) {
//         int currentVertex = pop(stack);

//         if (!visited[currentVertex]) {
//             printf("%d ", currentVertex);
//             visited[currentVertex] = true;
//         }

//         for (int i = 0; i < graph->vertices; i++) {
//             if (graph->matrix[currentVertex][i] == 1 && !visited[i]) {
//                 push(stack, i);
//             }
//         }
//     }
// }

// int main() {
//     // Create a graph with 5 vertices
//     struct Graph* graph = createGraph(5);

//     // Add edges to the graph
//     addEdge(graph, 0, 1);
//     addEdge(graph, 0, 2);
//     addEdge(graph, 1, 3);
//     addEdge(graph, 2, 4);

//     // Initialize visited array
//     for (int i = 0; i < graph->vertices; i++) {
//         visited[i] = false;
//     }

//     DFS(graph, 0);

//     return 0;
// }
