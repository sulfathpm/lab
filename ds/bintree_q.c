#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node definition
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Inorder traversal
void inorderTraversal(struct Node* root) {
    if (root == NULL) return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

// Function to find the deepest rightmost node and its parent
void findDeepestRightmostNode(struct Node* root, struct Node** deepestNode, struct Node** parent) {
    if (root == NULL) return;

    struct Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    *deepestNode = NULL;
    *parent = NULL;

    while (front < rear) {
        struct Node* current = queue[front++];

        if (current->left) {
            *parent = current;
            queue[rear++] = current->left;
        }

        if (current->right) {
            *parent = current;
            queue[rear++] = current->right;
        }

        *deepestNode = current;
    }
}

// Function to delete the deepest rightmost node
void deleteDeepestRightmostNode(struct Node* root, struct Node* delNode) {
    if (root == NULL) return;

    struct Node* queue[1000];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];

        if (current->left) {
            if (current->left == delNode) {
                free(current->left);
                current->left = NULL;
                return;
            } else {
                queue[rear++] = current->left;
            }
        }

        if (current->right) {
            if (current->right == delNode) {
                free(current->right);
                current->right = NULL;
                return;
            } else {
                queue[rear++] = current->right;
            }
        }
    }
}

// Function to delete a node with given key in binary tree
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return NULL;

    if (root->left == NULL && root->right == NULL) {
        if (root->data == key) {
            free(root);
            return NULL;
        } else {
            return root;
        }
    }

    struct Node* keyNode = NULL;
    struct Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* current = queue[front++];

        if (current->data == key) {
            keyNode = current;
        }

        if (current->left) queue[rear++] = current->left;
        if (current->right) queue[rear++] = current->right;
    }

    if (keyNode != NULL) {
        struct Node* deepestNode = NULL;
        struct Node* parent = NULL;

        findDeepestRightmostNode(root, &deepestNode, &parent);

        if (deepestNode != NULL) {
            keyNode->data = deepestNode->data;  // Replace data
            deleteDeepestRightmostNode(root, deepestNode);  // Delete deepest node
        }
    }
    return root;
}

int main() {
    /*
          10
         /  \
        11   9
       / \   /
      7  12 15
    */

    struct Node* root = createNode(10);
    root->left = createNode(11);
    root->right = createNode(9);
    root->left->left = createNode(7);
    root->left->right = createNode(12);
    root->right->left = createNode(15);

    printf("Inorder before deletion:\n");
    inorderTraversal(root);
    printf("\n");

    root = deleteNode(root, 11);

    printf("Inorder after deletion of 11:\n");
    inorderTraversal(root);
    printf("\n");

    return 0;
}
