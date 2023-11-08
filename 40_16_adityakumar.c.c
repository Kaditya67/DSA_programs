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

struct node *stack = NULL;

void push(int x) {
    struct node *newnode = getnode();
    newnode->info = x;
    newnode->next = stack;
    stack = newnode;
}

int pop() {
    if (stack == NULL) {
        printf("Stack is empty\n");
        return -1;
    }
    struct node *temp = stack;
    int value = temp->info;
    stack = temp->next;
    freenode(temp);
    return value;
}

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

int count() {
    int count = 0;
    struct node *temp = stack;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
    int choice, x;

    while (1) {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Count\n");
        printf("5. Exit\n");
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
                printf("Number of elements in the stack: %d\n", count());
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
