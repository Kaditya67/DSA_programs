#include <stdio.h>
#include <stdlib.h>

struct node {
    int info;
    struct node *next;
};

struct node *getnode(void) {
    return (struct node *)malloc(sizeof(struct node));
}

void freenode(struct node *p) {
    free(p);
}

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int x) {
    struct node *newnode = getnode();
    newnode->info = x;
    newnode->next = NULL;
    
    if (rear == NULL) {
        front = rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
}

int dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return -1;
    }
    
    struct node *temp = front;
    int value = temp->info;
    
    if (front == rear) {
        front = rear = NULL;
    } else {
        front = front->next;
    }
    
    freenode(temp);
    return value;
}

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

int count() {
    struct node *temp = front;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    int choice, x;

    while (1) {
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Count\n");
        printf("5. Exit\n");
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
                printf("Number of elements in the queue: %d\n", count());
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
