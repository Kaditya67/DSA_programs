#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation error\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = newNode->prev = newNode;
    return newNode;
}

// Function to insert node at the beginning
void insertAtBeginning(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
        head = newNode;
    }
    printf("Node inserted at the beginning\n");
}

// Function to insert node at the end
void insertAtEnd(int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        newNode->prev = head->prev;
        head->prev->next = newNode;
        head->prev = newNode;
    }
    printf("Node inserted at the end\n");
}

// Function to insert node at a specific location
void insertAtLocation(int data, int pos) {
    if (pos <= 0) {
        printf("Invalid position\n");
        return;
    }
    struct Node* newNode = createNode(data);
    if (head == NULL && pos == 1) {
        head = newNode;
    } else {
        struct Node* temp = head;
        int i;
        for (i = 1; i < pos - 1 && temp != head; i++){
            temp = temp->next;
        }
        if (i < pos - 1) {
            printf("Invalid position\n");
            return;
        }
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next->prev = newNode;
        temp->next = newNode;
    }
    printf("Node inserted at position %d\n", pos);
}

// Function to delete node at the beginning
void deleteAtBeginning() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        if (head->next == head) {
            free(head);
            head = NULL;
        } else {
            struct Node* temp = head;
            head->prev->next = head->next;
            head->next->prev = head->prev;
            head = head->next;
            free(temp);
        }
        printf("Node deleted from the beginning\n");
    }
}

// Function to delete node at the end
void deleteAtEnd() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        if (head->next == head) {
            free(head);
            head = NULL;
        } else {
            struct Node* temp = head->prev;
            temp->prev->next = head;
            head->prev = temp->prev;
            free(temp);
        }
        printf("Node deleted from the end\n");
    }
}

// Function to delete node at a specific location
void deleteAtLocation(int pos) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        if (pos <= 0) {
            printf("Invalid position\n");
            return;
        }
        if (pos == 1) {
            deleteAtBeginning();
        } else {
            struct Node* temp = head;
            int i;
            for (i = 1; i < pos && temp->next != head; i++) {
                temp = temp->next;
            }
            if (i < pos) {
                printf("Invalid position\n");
                return;
            }
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
            free(temp);
            printf("Node deleted from position %d\n", pos);
        }
    }
}

// Function to display the list
void display() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node* temp = head;
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
        printf("\n");
    }
}

// Function to search for a node with given data
void search(int data) {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node* temp = head;
        int pos = 1;
        do {
            if (temp->data == data) {
                printf("Node found at position %d\n", pos);
                return;
            }
            temp = temp->next;
            pos++;
        } while (temp != head);
        printf("Node not found in the list\n");
    }
}

// Function to count the number of nodes in the list
void countNodes() {
    int count = 0;
    if (head != NULL) {
        struct Node* temp = head;
        do {
            count++;
            temp = temp->next;
        } while (temp != head);
    }
    printf("Number of nodes in the list: %d\n", count);
}

// Function to reverse the list
void reverse() {
    if (head == NULL) {
        printf("List is empty\n");
    } else {
        struct Node *current = head, *temp;
        do {
            temp = current->next;
            current->next = current->prev;
            current->prev = temp;
            current = temp;
        } while (current != head);
        head = head->prev;
        printf("List reversed\n");
    }
}

int main() {
    int choice, data, position;
    while (1) {
        printf("1. CREATE\n");
        printf("2. INSERT AT BEGINNING\n");
        printf("3. INSERT AT END\n");
        printf("4. INSERT AT LOCATION\n");
        printf("5. DELETE AT BEGINNING\n");
        printf("6. DELETE AT END\n");
        printf("7. DELETE AT LOCATION\n");
        printf("8. DISPLAY\n");
        printf("9. SEARCH\n");
        printf("10. COUNT\n");
        printf("11. REVERSE\n");
        printf("12. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                // CREATE
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 2:
                // INSERT AT BEGINNING
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 3:
                // INSERT AT END
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 4:
                // INSERT AT LOCATION
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtLocation(data, position);
                break;
            case 5:
                // DELETE AT BEGINNING
                deleteAtBeginning();
                break;
            case 6:
                // DELETE AT END
                deleteAtEnd();
                break;
            case 7:
                // DELETE AT LOCATION
                printf("Enter position: ");
                scanf("%d", &position);
                deleteAtLocation(position);
                break;
            case 8:
                // DISPLAY
                display();
                break;
            case 9:
                // SEARCH
                printf("Enter data to search: ");
                scanf("%d", &data);
                search(data);
                break;
            case 10:
                // COUNT
                countNodes();
                break;
            case 11:
                // REVERSE
                reverse();
                break;
            case 12:
                // EXIT
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
