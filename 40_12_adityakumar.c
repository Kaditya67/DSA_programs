#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

int queue[MAX_SIZE];
int front = -1, rear = -1;


void enqueue(int data) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is Overflow\n");
    }

    if (front == -1 && rear == -1) {
        front = rear = 0;
    } else {
        rear++;
    }

    queue[rear] = data;
    printf("%d Enqueued successfully.\n", data);
}

void dequeue() {
    if (front == -1 && rear == -1) {
        printf("Queue is Underflow\n");
    }

    printf("%d Dequeued successfully.\n", queue[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void display() {
    if (front == -1 && rear == -1) {
        printf("Queue is Underflow\n");
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, data;

    while(1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting...\n");
                exit(1);
            default:
                printf("Invalid choice, Please enter a valid option.\n");
        }
    }

    return 0;
}

