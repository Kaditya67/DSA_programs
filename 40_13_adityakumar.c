#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int x) {
    if ((front == 0 && rear == MAX - 1) || (rear == (front - 1) % (MAX - 1))) {
        printf("Queue is Overflow\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = x;
    } else if (rear == MAX - 1 && front != 0) {
        rear = 0;
        queue[rear] = x;
    } else {
        rear++;
        queue[rear] = x;
    }
}

void dequeue() {
    if (front == -1) {
        printf("Queue is Underflow\n");
    } else {
        printf("Element dequeued: %d\n", queue[front]);
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
    }
}

void display() {
    if (front == -1) {
        printf("Queue is Underflow\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        if (front <= rear) {
            while (i <= rear) {
                printf("%d ", queue[i]);
                i++;
            }
        } else {
            while (i < MAX) {
                printf("%d ", queue[i]);
                i++;
            }
            i = 0;
            while (i <= rear) {
                printf("%d ", queue[i]);
                i++;
            }
        }
        printf("\n");
    }
}

int main() {
    int choice, data;

    while (1) {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
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
                exit(0);
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
