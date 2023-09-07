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

struct node *list = NULL; // Initialize the linked list

// Function to insert an element at the beginning of the linked list
void insertbeg(int x) {
    struct node *newnode = getnode();
    newnode->info = x;
    newnode->next = list;
    list = newnode;
}

// Function to insert an element at the end of the linked list
void insertend(int x) {
    if (list == NULL) {
        insertbeg(x);
    } else {
        struct node *nn, *temp;
        nn = getnode();
        nn->info = x;
        nn->next = NULL;
        temp = list;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nn;
    }
}

// Function to display the linked list
void display() {
    struct node *temp = list;
    if (temp == NULL) {
        printf("The list is empty\n");
        return;
    }
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to search for an element in the linked list
int search(int key) {
    struct node *temp = list;
    int position = 1;
    while (temp != NULL) {
        if (temp->info == key) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1; // Element not found
}

// Function to insert an element at a specific location in the linked list
void insertatlocation(int p, int x) {
    if (p <= 0) {
        printf("Invalid position\n");
        return;
    }
    
    struct node *nn, *temp;
    nn = getnode();
    nn->info = x;

    if (p == 1) {
        nn->next = list;
        list = nn;
    } else {
        temp = list;
        for (int i = 1; i < p - 1 && temp != NULL; i++) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Invalid position\n");
            freenode(nn); // Free the allocated node
        } else {
            nn->next = temp->next;
            temp->next = nn;
        }
    }
}

// Function to delete an element at a specific location in the linked list
void deleteatlocation(int p) {
    struct node *temp, *t2;
    if (list == NULL) {
        printf("List Is Empty\n");
    } else {
        if (p == 1) {
            t2 = list;
            list = list->next;
            freenode(t2);
        } else {
            temp = list;
            for (int i = 1; i < p - 1 && temp != NULL; i++) {
                temp = temp->next;
            }
            if (temp == NULL || temp->next == NULL) {
                printf("Invalid position\n");
            } else {
                t2 = temp->next;
                temp->next = t2->next;
                freenode(t2);
            }
        }
    }
}

int main() {
    int choice, x, position;

    while (1) {
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at location\n");
        printf("4. Display\n");
        printf("5. Search\n");
        printf("6. Delete at location\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert at the beginning: ");
                scanf("%d", &x);
                insertbeg(x);
                break;
            case 2:
                printf("Enter element to insert at the end: ");
                scanf("%d", &x);
                insertend(x);
                break;
            case 3:
                printf("Enter position to insert: ");
                scanf("%d", &position);
                printf("Enter element to insert: ");
                scanf("%d", &x);
                insertatlocation(position, x);
                break;
            case 4:
                display();
                break;
            case 5:
                printf("Enter element to search: ");
                scanf("%d", &x);
                position = search(x);
                if (position == -1) {
                    printf("Element not found in the list\n");
                } else {
                    printf("Element found at position %d\n", position);
                }
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteatlocation(position);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
