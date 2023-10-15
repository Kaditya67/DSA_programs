#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int queue[MAX];
int rear = -1, front = -1;

void EnQFront(int x)
{
    if ((rear == MAX - 1 && front == 0) || (front == rear + 1))
    {
        printf("Queue is Overflow\n");
    }
    else if (front == -1 && rear == -1)
    {
        rear = front = 0;
        queue[front] = x;
    }
    else if (front == 0)
    {
        front = MAX - 1;
        queue[front] = x;
    }
    else
    {
        front--;
        queue[front] = x;
    }
}

void EnQRear(int x)
{
    if ((rear == MAX - 1 && front == 0) || (front == rear + 1))
    {
        printf("Queue is Overflow\n");
    }
    else if (front == -1 && rear == -1)
    {
        rear = front = 0;
        queue[rear] = x;
    }
    else
    {
        rear = (rear + 1) % MAX;
        queue[rear] = x;
    }
}

void DeQFront()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is Underflow\n");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

void DeQRear()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue is Underflow\n");
    }
    else if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        if (rear == 0)
        {
            rear = MAX - 1;
        }
        else
        {
            rear--;
        }
    }
}

void display()
{
    if (front == -1 && rear == -1)
    {
        printf("Queue Is Underflow\n");
    }
    else
    {
        printf("Queue elements: ");
        int i = front;
        do
        {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX;
        } while (i != (rear + 1) % MAX);
        printf("\n");
    }
}

int main()
{
    int choice, data;

    while (1)
    {
        printf("\n1. Enqueue from rear\n2. Enqueue from front\n3. Dequeue from front\n4. Dequeue from rear\n5. Display\n6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to enqueue from rear: ");
            scanf("%d", &data);
            EnQRear(data);
            break;
        case 2:
            printf("Enter data to enqueue from front: ");
            scanf("%d", &data);
            EnQFront(data);
            break;
        case 3:
            DeQFront();
            break;
        case 4:
            DeQRear();
            break;
        case 5:
            display();
            break;
        case 6:
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}
