#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    int pr;
    struct node *next;
};

struct node *list = NULL;// start of linked list

// Function to allocate memory to a new node
struct node* getnode(void) {
    return (struct node*)malloc(sizeof(struct node));
}

// Function to free memory of node
void freenode(struct node *p) {
    free(p);
}

// Enqueue an element with its priority
void enqueue(int x, int pr) {
    struct node *temp, *nn;
    nn = getnode();
    nn->info = x;
    nn->pr = pr;
    nn->next = NULL;

    if (list == NULL || pr < list->pr) {
        nn->next = list;
        list = nn;
    } else {
        temp = list;
        while (temp->next != NULL && nn->pr > temp->pr) {
            temp = temp->next;
        }
        nn->next = temp->next;
        temp->next = nn;
    }
}

// Dequeue the element with the highest priority
int dequeue() {
    if (list == NULL) {
        printf("Queue is empty\n");
        return -1; // indicating an empty queue
    }

    struct node *temp = list;
    int data = temp->info;
    list = list->next;
    freenode(temp);
    return data;
}

int main() {
    int num_elements;
    printf("Enter the number of elements: ");
    scanf("%d", &num_elements);

    for (int i = 0; i < num_elements; i++) {
        int data, priority;
        printf("Enter element %d and its priority: ", i + 1);
        scanf("%d %d", &data, &priority);
        enqueue(data, priority);
    }

    printf("\nDequeueing elements in priority order:\n");
    while (list != NULL) {
        int data = dequeue();
        printf("Dequeued: %d\n", data);
    }

    return 0;
}
