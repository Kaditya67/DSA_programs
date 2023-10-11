#include <stdio.h>
#include <stdlib.h>

// Structure of node
struct node
{
    int data;
    struct node *left, *right;
};

// Function to create a new node
struct node *new_node(int x)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = x;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Function to insert a node in the BST
struct node *insert(struct node *root, int x)
{
    if (root == NULL)
    {
        return new_node(x);
    }
    else if (x > root->data)
    {
        root->right = insert(root->right, x);
    }
    else
    {
        root->left = insert(root->left, x);
    }
    return root;
}

// Function to count nodes in the BST
int count_nodes(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + count_nodes(root->left) + count_nodes(root->right);
}

// Function to count leaf nodes in the BST
int count_leaves(struct node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    if (root->left == NULL && root->right == NULL)
    {
        return 1;
    }
    return count_leaves(root->left) + count_leaves(root->right);
}

int main()
{
    struct node *root = NULL;
    int choice, value;
    struct node *searchResult;

    do
    {
        printf("\n------------------------------------------------------\n");
        printf("\nBinary Search Tree Menu:\n");
        printf("1. Insert a node\n");
        printf("2. Delete a node\n");
        printf("3. Search for a node\n");
        printf("4. Display tree\n");
        printf("5. Count nodes and leaf nodes\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to Insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            printf("Enter value to Delete: ");
            scanf("%d", &value);
            printf("\nSearching...");
            root = delete(root, value);
            if (root == NULL)
            {
                printf("Not Found");
            }
            break;
        case 3:
            printf("Enter value to Search: ");
            scanf("%d", &value);
            searchResult = search(root, value);
            if (searchResult != NULL)
            {
                printf("\n #Node with value %d found in the tree.\n", value);
            }
            else
            {
                printf("\n #Node with value %d not found in the tree.\n", value);
            }
            break;
        case 4:
            printf("Binary Search Tree:");
            inorder(root);
            printf("\n");
            break;
        case 5:
            {
                int nodes_count = count_nodes(root);
                int leaves_count = count_leaves(root);
                printf("Number of nodes in the BST: %d\n", nodes_count);
                printf("Number of leaf nodes in the BST: %d\n", leaves_count);
            }
            break;
        case 6:
            printf("Exiting the program. Goodbye!\n");
            break;
        default:
            printf("Invalid Option, Try Again ...!");
        }
    } while (choice != 6);
    return 0;
}

