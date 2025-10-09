#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left,*right;

};

struct Node* create(int value){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->left=newNode->right=NULL;
    return newNode;

}

struct Node* insert(struct Node *root,int value){
    if(root==NULL) return create(value);
    if(value<root->data){
        root->left=insert(root->left,value);
    }
    if(value>root->data){
        root->right=insert(root->right,value);
    }
    return root;
}

struct Node* search(struct Node* root,int key){
    if(root==NULL||root->data==key) return root;
    if(key<root->data) return search(root->left,key);
    if(key>root->data) return search(root->right,key);
}

struct Node* minn(struct Node* root){
    while(root&&root->left!=NULL)
        root=root->left;
    return root;
}

struct Node* deletee(struct Node* root,int value){
    if(root==NULL) return root;
    if(value<root->data){
        root->left=deletee(root->left,value);
    }
    else if(value>root->data){
        root->right=deletee(root->right,value);
    }
    else{ //node with 1 child/none
        if(root->left==NULL){
            struct Node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct Node* temp=root->left;
            free(root);
            return temp;
        }
        //node with 2 childrn
        struct Node* temp=minn(root->right);
        root->data=temp->data;
        root->right=deletee(root->right,temp->data);
    }
    return root;
}

void preorder(struct Node* root){
    if(root!=NULL){
        printf("%d",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d",root->data);
    }
}

void inorder(struct Node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d",root->data);
        inorder(root->right);
    }
}

void main(){
    struct Node* root=NULL;
    int ch,val,key;
    while(1){
        printf("\nBinary Search Tree\n\n1.insert. \n2.delete. \n3.inorder.\n4.preorder.\n5.postorder.\n6.search. \n0.exit.\n Enter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1 :printf("\nEnter a value to insert : ");
                    scanf("%d",&val);
                    root=insert(root,val);
                    break;
            case 2 :printf("\nEnter a value to delete : ");
                    scanf("%d",&val);
                    root=deletee(root,val);
                    break;
            case 3 :printf("\ninorder traversal : ");
                    inorder(root);
                    break;
            case 4 :printf("\npreorder traversal : ");
                    preorder(root);
                    break;
            case 5 :printf("\npostorder traversal : ");
                    postorder(root);
                    break;
            case 6 :printf("\nEnter an element to search : ");
                    scanf("%d",&key);
                    struct Node* found=search(root,key);
                    if(found) printf("\nFound %d",key);
                    else printf("%d isn't found",key);
                    break;
            case 0 :printf("\nExiting.......\n\n\n");
                    exit(0);
            default:printf("\nInvalid choice!\n");
        }
    }
}