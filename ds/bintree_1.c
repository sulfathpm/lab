#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left,*right;
};

struct Node *root;

struct Node* create(){
    int x;
    struct Node *newNode;

    printf("\nenter value(-1 for no node) : ");
    scanf("%d",&x);

    if(x==-1){
        return NULL;
    }

    newNode=(struct Node*) malloc(sizeof(struct Node));

    newNode->data=x;

    printf("\nenter the left child(%d) : ",x);
    newNode->left=create();

    printf("\nenter the right child(%d) : ",x);
    newNode->right=create();

    return newNode;
}
void deleteDeepest(struct Node* root, struct Node* d_node) {
    if (root == NULL) return;

    if (root->left) {
        if (root->left == d_node) {
            free(root->left);
            root->left = NULL;
            return;
        } else {
            deleteDeepest(root->left, d_node);
        }
    }

    if (root->right) {
        if (root->right == d_node) {
            free(root->right);
            root->right = NULL;
            return;
        } else {
            deleteDeepest(root->right, d_node);
        }
    }
}
#include <stdbool.h>
#include <string.h>

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return NULL;

    // If the tree has only one node.
    if (root->left == NULL && root->right == NULL) {
        if (root->data == key) {
            free(root);
            return NULL;
        } else {
            return root;
        }
    }

    // Level order traversal to find key node and deepest node.
    struct Node* key_node = NULL;
    struct Node* temp;
    struct Node* last_node = NULL;

    // Use a queue for level order traversal.
    struct Node* queue[1000];
    int front = 0, rear = 0;

    queue[rear++] = root;

    while (front < rear) {
        temp = queue[front++];

        if (temp->data == key) {
            key_node = temp;
        }

        if (temp->left) queue[rear++] = temp->left;
        if (temp->right) queue[rear++] = temp->right;

        last_node = temp;
    }

    if (key_node != NULL) {
        // Replace key_node's data with deepest node's data
        key_node->data = last_node->data;

        // Delete the deepest node
        deleteDeepest(root, last_node);
    }

    return root;
}

void inorder(struct Node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("\t%d\t",root->data);
        inorder(root->right);
    }

}
void preorder(struct Node* root){
    if(root!=NULL){
        printf("\t%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("\t%d\t",root->data);
    }
}

int main(){
    int val,choice;
    struct Node* root=NULL;
    while(1){
        printf("\nBINARY TREE \n1.create.\n2.delete.\n3.inorder traversal.\n4.preorder traversal.\n5.postorder traversal.\n0.exit.\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){
        case 1  :   
                    root=create();
                    break;
        case 2  :   printf("value=?");
                    scanf("%d",&val);
                    deleteNode(root,val);
                    break;
        case 3  :   printf("\nInorder traversal : ");
                    inorder(root);
                    printf("\n");
                    break;
        case 4  :   printf("\nPreorder traversal : ");
                    preorder(root);
                    printf("\n");
                    break;
        case 5  :   printf("\nPostorder traversal : ");
                    postorder(root);
                    printf("\n");
                    break;
        case 0  :   printf("\nexiting.......\n");
                    exit(0);
                    break;
        default :   printf("\ninvalid choice!\n");
                    break;
        }
    }
    return 0;
}

// BINARY TREE 
// 1.create.
// 2.delete.
// 3.inorder traversal.
// 4.preorder traversal.
// 5.postorder traversal.
// 0.exit.
// Enter your choice : 1

// enter value(-1 for no node) : 2

// enter the left child(2) : 
// enter value(-1 for no node) : 3

// enter the left child(3) : 
// enter value(-1 for no node) : 4

// enter the left child(4) : 
// enter value(-1 for no node) : 5

// enter the left child(5) : 
// enter value(-1 for no node) : 6

// enter the left child(6) : 
// enter value(-1 for no node) : -1

// enter the right child(6) : 
// enter value(-1 for no node) : 11

// enter the left child(11) : 
// enter value(-1 for no node) : -1

// enter the right child(11) : 
// enter value(-1 for no node) : 13

// enter the left child(13) : 
// enter value(-1 for no node) : -1

// enter the right child(13) : 
// enter value(-1 for no node) : -1

// enter the right child(5) : 
// enter value(-1 for no node) : -1

// enter the right child(4) : 
// enter value(-1 for no node) : 44

// enter the left child(44) : 
// enter value(-1 for no node) : -1

// enter the right child(44) : 
// enter value(-1 for no node) : -1

// enter the right child(3) : 
// enter value(-1 for no node) : -1

// enter the right child(2) : 
// enter value(-1 for no node) : -1

// BINARY TREE 
// 1.create.
// 2.delete.
// 3.inorder traversal.
// 4.preorder traversal.
// 5.postorder traversal.
// 0.exit.
// Enter your choice : 3

// Inorder traversal :     6               11              13              5               4               44              3               2

// BINARY TREE 
// 1.create.
// 2.delete.
// 3.inorder traversal.
// 4.preorder traversal.
// 5.postorder traversal.
// 0.exit.
// Enter your choice : 4

// Preorder traversal :    2               3               4               5               6               11              13              44

// BINARY TREE 
// 1.create.
// 2.delete.
// 3.inorder traversal.
// 4.preorder traversal.
// 5.postorder traversal.
// 0.exit.
// Enter your choice : 5

// Postorder traversal :   13              11              6               5               44              4               3               2

// BINARY TREE 
// 1.create.
// 2.delete.
// 3.inorder traversal.
// 4.preorder traversal.
// 5.postorder traversal.
// 0.exit.
// Enter your choice : ^C


//         2
//        / \
//       3   NULL
//      / \
//     4   NULL
//    / \
//   5   44
//  / \
// 6  NULL
// / \
// NULL 11
//     /  \
//    NULL 13
//        /  \
//     NULL NULL
