#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* createNode(int value){
    struct Node* newNode=(struct Node*) malloc(sizeof(struct Node));
    newNode->data=value;
    newNode->next=NULL;
}

void insertAtBeg(struct Node* *head,int value){
    struct Node* newNode=createNode(value);
    newNode->next=*head;
    *head=newNode;
}

void insertAtEnd(struct Node* *head,int value){
     struct Node* newNode=createNode(value);
     if(*head==NULL){
        *head=newNode;
     }
     else{
        struct Node* temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newNode;
     }
}

void insertAfterPos(struct Node* *head,int value){
    struct Node* newNode=createNode(value);
     if(*head==NULL){
        *head=newNode;
     }
     else{
        struct Node* temp=*head;
        while(temp!=NULL){
            temp=temp->next;
        }
        if(temp==NULL){
            printf("\nposition not found.");
            free(newNode);
            return;
        }
        newNode->next=temp->next;
        temp->next=newNode;
    }
}

void deleteFromBeg(struct Node* *head){
    if(*head==NULL){
        printf("\nlist is empty.");
    }
    else{
        temp=*head;
        *head=(*head)->next;
        free(temp);
    }
}

void deleteFromEnd(struct Node* *head){
     if(*head==NULL){
        printf("\nlist is empty.");
    }
    else{
        struct Node* temp=*head;
        struct Node* prev=NULL;
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }
        // if(temp==NULL){
        //     printf("\nposition not found");
        // }
        if(prev==NULL){
            *head=NULL
        }else{
            prev->next=NULL
        }
    }
}

void deleteVal(struct Node* *head,int val){
    if(*head==NULL){
        printf("\nlist is empty.");
    }
    else{
        struct Node* temp=*head;
        struct Node* prev=NULL;
        while(temp!=NULL&&temp->data==val){
            prev=temp;
            temp=temp->next;
        }
        if(temp==NULL){
            printf("\nNot found");
        }
        prev->next=temp->next;
        free(temp);
    }
}
