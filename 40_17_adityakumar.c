#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

// Function to allocate memory for a new node
struct node *getnode(void) {
    return (struct node *)malloc(sizeof(struct node));
}

// Function to free memory for a given node
void freenode(struct node *p) {
    free(p);
}

struct node *front = NULL; // Initialize the front of the queue
struct node *rear = NULL;  // Initialize the rear of the queue

// Function to enqueue (insert) an element at the rear of the queue
void enqueue(int x) {
    struct node *newnode = getnode();
    newnode->info = x;
    newnode->next = NULL;
    
    if (rear == NULL) {
        // If the queue is empty, set both front and rear to the new node
        front = rear = newnode;
    } else {
        // Otherwise, add the new node to the rear of the queue
        rear->next = newnode;
        rear = newnode;
    }
}

// Function to dequeue (remove) an element from the front of the queue
int dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return -1; // or some error code
    }
    
    struct node *temp = front;
    int value = temp->info; // This value is dequeued
    
    if (front == rear) {
        // If there is only one element in the queue, set both front and rear to NULL
        front = rear = NULL;
    } else {
        // Otherwise, move front to the next node in the queue
        front = front->next;
    }
    
    freenode(temp);
    return value; // It will be displayed
}

// Function to display the elements in the queue
void display() {
    struct node *temp = front;
    if (temp == NULL) {
        printf("Queue is empty\n");
        return;
    }
    
    printf("Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, x;

    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &x);
                enqueue(x);
                break;
            case 2:
                x = dequeue();
                if (x != -1) {
                    printf("Dequeued element: %d\n", x);
                }
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
