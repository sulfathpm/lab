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

void deleteDeepest(struct Node* root,struct Node* d_node){
    if(root==NULL) return NULL;

    if(root==d_node){
        free(root);
        root=NULL;
        return;

    }

    if(root->left){
        if(root->left==NULL){
            free(root->left);
            root->left=NULL;
            return;
        }
    }else {
            deleteDeepest(root->left,d_node);

    }
    if(root->right){
        if(root->right==NULL){
            free(root->right);
            root->right=NULL;
            return;
        }
    }else{
            deleteDeepest(root->right,d_node);
    }
}
struct Node* deleteNode(struct Node* root,int key){
    if(root==NULL) return NULL;

    if(root->left==NULL&&root->right==NULL){
        if(root->data==key){
            free(root);
            return NULL;
        }else{
            return root;
        }
    }
    struct Node* key_node=NULL;
    struct Node* last_node=NULL;
    struct Node* temp;

    struct Node* queue[1000];
    int front=0,rear=0;

    queue[rear++]=root;

    while(front<rear){
        temp=queue[front++];

        if(temp->data==key){
            key_node=temp;
        }
        if(temp->left) queue[rear++]=temp->left;
        if(temp->right) queue[rear++]=temp->right;

        last_node=temp;
    }
    if(key_node!=NULL){
        key_node->data=last_node->data;
        deleteDeepest(root,last_node);
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
                    root=deleteNode(root,val);
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

