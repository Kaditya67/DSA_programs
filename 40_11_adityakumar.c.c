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
    newNode->next = NULL;
    return newNode;
}

Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

Node* insertAtEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
}

Node* insertAtLocation(Node* head, int data, int position) {
    if (position == 0) {
        return insertAtBeginning(head, data);
    }
    Node* newNode = createNode(data);
    Node* temp = head;
    for (int i = 0; i < position - 1; ++i) {
        if (temp == NULL) {
            printf("Invalid position\n");
            return head;
        }
        temp = temp->next;
    }
    newNode->next = temp->next; // newnode links to next node of temp
    temp->next = newNode;
    return head;
}

Node* deleteAtBeginning(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    Node* temp = head;
    head = head->next; // save the address of 2nd element
    free(temp);
    return head;
}

Node* deleteAtEnd(Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    Node* temp = head;
    while (temp->next->next != NULL) { // in order to delete the last node, you need a reference to the node that precedes it
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

Node* deleteAtLocation(Node* head, int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return head;
    }
    if (position == 0) {
        return deleteAtBeginning(head);
    }
    Node* temp = head;
    for (int i = 0; i < position - 1; ++i) {
        if (temp == NULL || temp->next == NULL) {
            printf("Invalid position\n");
            return head;
        }
        temp = temp->next;
    }
    Node* toDelete = temp->next;
    temp->next = temp->next->next; // skip the middle node
    free(toDelete); // free middle node
    return head;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
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
    Node* temp = head;
    int count = 0;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

Node* reverse(Node* head) {
    Node* prev = NULL;
    Node* current = head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
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
                printf("Linked List: ");
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

               
