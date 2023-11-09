#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = newNode; // Circular reference
    return newNode;
}

Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    newNode->next = head;
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    return newNode;
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head;
    return head;
}

Node* insertAtLocation(Node* head, int data, int position) {
    if (position == 0) {
        return insertAtBeginning(head, data);
    }
    Node* newNode = createNode(data);
    Node* temp = head;
    for (int i = 0; i < position - 1; ++i) {
        if (temp->next == head) {
            printf("Invalid position\n");
            return head;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

Node* deleteAtBeginning(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (head->next == head) {
        free(head);
        return NULL;
    }
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = head->next;
    free(head);
    return temp->next;
}

Node* deleteAtEnd(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (head->next == head) {
        free(head);
        return NULL;
    }
    Node* temp = head;
    Node* prev = NULL;
    while (temp->next != head) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = head;
    free(temp);
    return head;
}

Node* deleteAtLocation(Node* head, int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (position == 0) {
        return deleteAtBeginning(head);
    }
    Node* temp = head;
    Node* prev = NULL;
    for (int i = 0; i < position; ++i) {
        if (temp->next == head) {
            printf("Invalid position\n");
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    free(temp);
    return head;
}

void display(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf(" (Head)\n");
}

int search(Node* head, int key) {
    if (head == NULL) {
        return -1;
    }
    int position = 0;
    Node* temp = head;
    do {
        if (temp->data == key) {
            return position;
        }
        temp = temp->next;
        position++;
    } while (temp != head);
    return -1;
}

int count(Node* head) {
    if (head == NULL) {
        return 0;
    }
    int count = 0;
    Node* temp = head;
    do {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}

Node* reverse(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    Node* prev = NULL;
    Node* current = head;
    Node* nextNode = NULL;
    do {
        nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    } while (current != head);
    head->next = prev;
    return prev;
}

int main() {
    Node* head = NULL;
    int choice, data, position, key;
    
    while (1) {
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Location\n");
        printf("4. Delete at Beginning\n");
        printf("5. Delete at End\n");
        printf("6. Delete at Location\n");
        printf("7. Display\n");
        printf("8. Search\n");
        printf("9. Count\n");
        printf("10. Reverse\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                head = insertAtBeginning(head, data);
                break;
            case 2:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                head = insertAtEnd(head, data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                head = insertAtLocation(head, data, position);
                break;
            case 4:
                head = deleteAtBeginning(head);
                break;
            case 5:
                head = deleteAtEnd(head);
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                head = deleteAtLocation(head, position);
                break;
            case 7:
                printf("Circular Linked List: ");
                display(head);
                break;
            case 8:
                printf("Enter key to search: ");
                scanf("%d", &key);
                position = search(head, key);
                if (position != -1) {
                    printf("Key found at position %d\n", position);
                } else {
                    printf("Key not found in the list\n");
                }
                break;
            case 9:
                printf("Number of nodes in the list: %d\n", count(head));
                break;
            case 10:
                head = reverse(head);
                printf("List reversed\n");
                break;
            case 0:
                // Free memory before exiting the program (not implemented in this code)
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
