#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct node {
    int info;           // Data of the node
    struct node *next;  // Pointer to the next node
};

// Function to allocate memory for a new node
struct node *getnode(void) {
    return (struct node *)malloc(sizeof(struct node));
}

// Function to free memory for a given node
void freenode(struct node *p) {
    free(p);
}

struct node *stack = NULL; // Initialize the stack using the linked list

// Function to push an element onto the stack
void push(int x) {
    struct node *newnode = getnode();
    newnode->info = x;
    newnode->next = stack;
    stack = newnode;
}

// Function to pop an element from the stack
int pop() {
    if (stack == NULL) {
        printf("Stack is empty\n");
        return -1; // or some error code
    }
    struct node *temp = stack;
    int value = temp->info;
    stack = temp->next;
    freenode(temp);
    return value;
}

// Function to display the stack
void display() {
    struct node *temp = stack;
    if (temp == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack: ");
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, x;

    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &x);
                push(x);
                break;
            case 2:
                x = pop();
                if (x != -1) {
                    printf("Popped: %d\n", x);
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
