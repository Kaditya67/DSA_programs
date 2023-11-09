#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* prev;
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
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        return head;
    }
}

Node* insertAtLocation(Node* head, int data, int position) {
    Node* newNode = createNode(data);
    if (position <= 0) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        return newNode;
    } else {
        Node* temp = head;
        for (int i = 1; i < position && temp != NULL; ++i) {
            temp = temp->next;
        }
        if (temp == NULL) {
            printf("Invalid position\n");
            free(newNode);
            return head;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        if (temp->next != NULL) {
            temp->next->prev = newNode;
        }
        temp->next = newNode;
        return head;
    }
}

Node* deleteAtBeginning(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    Node* temp = head->next;
    free(head);
    if (temp != NULL) {
        temp->prev = NULL;
    }
    return temp;
}

Node* deleteAtEnd(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        free(temp);
        return NULL;
    }
    free(temp);
    return head;
}

Node* deleteAtLocation(Node* head, int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    if (position <= 0) {
        Node* temp = head->next;
        free(head);
        if (temp != NULL) {
            temp->prev = NULL;
        }
        return temp;
    } else {
        Node* temp = head;
        for (int i = 1; i < position && temp != NULL; ++i) {
            temp = temp->next;
        }
        if (temp == NULL || temp->next == NULL) {
            printf("Invalid position\n");
            return head;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        if (temp->next != NULL) {
            temp->next->prev = temp;
        }
        free(toDelete);
        return head;
    }
}

void display(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    Node* temp = head;
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int search(Node* head, int key) {
    Node* temp = head;
    int position = 0;
    while (temp != NULL) {
        if (temp->data == key) {
            return position;
        }
        temp = temp->next;
        position++;
    }
    return -1;
}

int count(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

Node* reverse(Node* head) {
    Node* temp = NULL;
    Node* current = head;
    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    if (temp != NULL) {
        head = temp->prev;
    }
    return head;
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
                printf("Double Linked List: ");
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
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
