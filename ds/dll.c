#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *next,*prev;
};

struct Node *start=NULL;

void create(){
	int i,n,val;
	struct Node *newNode,*t;
	printf("N=?");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("\nData(%d) : ",i+1);
		scanf("%d",&val);
		newNode=(struct Node*) malloc(sizeof(struct Node));
		newNode->data=val;
		newNode->next=NULL;
		newNode->prev=NULL;
		if(start==NULL){
			start=newNode;
			t=newNode;
		}
		else{
			t->next=newNode;
			newNode->prev=t;
			t=newNode;
		}
	}
	printf("\ncreated doubly linked list with %d elements.",n);
	
}
void insert_beg(int val) {
    struct Node *newNode;
    newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = start;
    newNode->prev = NULL;
    
    if (start != NULL)
        start->prev = newNode;
    start = newNode;

    printf("\nInserted %d at beginning.\n", val);
}
void insert_end(int val) {
    struct Node *newNode, *t;
    newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (start == NULL) {
        start = newNode;
        printf("\nInserted %d as first element.\n", val);
        return;
    }

    t = start;
    while (t->next != NULL)
        t = t->next;

    t->next = newNode;
    newNode->prev = t;

    printf("\nInserted %d at end.\n", val);
}

void insert_pos(int pos,int val){
	struct Node *newNode,*t;
	int i;
	newNode=(struct Node*)malloc(sizeof(newNode));
	newNode->data=val;
	newNode->next=NULL;
	newNode->prev=NULL;
	if(pos<=0){
		printf("\ninvalid position\n");
		return;
	}
		if(pos==1){
			newNode->next=start;
			if(start!=NULL) start->prev=newNode;
			start=newNode;
		}else{	
			t=start;
			for(i=1;i<pos-1&&t!=NULL;i++){
				t=t->next;
			}
			if(t==NULL){
				printf("\nPosition out of range.\n");
				return;
			}
			newNode->next=t->next;
			newNode->prev=t;
			 if(t->next != NULL)
            t->next->prev = newNode;
        t->next = newNode;
    }

	printf("\nElement %d inserted at position %d",val,pos);
}
void delete_beg() {
    struct Node *t;
    if (start == NULL) {
        printf("\nList is empty.\n");
        return;
    }

    t = start;
    start = start->next;

    if (start != NULL)
        start->prev = NULL;

    printf("\nDeleted %d from beginning.\n", t->data);
    free(t);
}
void delete_end(){
    struct Node *t;
    if (start == NULL){
        printf("\nList is empty.\n");
        return;
    }

    t = start;
    while (t->next != NULL)
        t = t->next;

    if (t->prev != NULL)
        t->prev->next = NULL;
    else
        start = NULL;  // only one element

    printf("\nDeleted %d from end.\n", t->data);
    free(t);
}

void delete_pos(int pos){
	struct Node *t;
	int i;
	if(pos<=0||start==NULL){
		printf("\ninvalid position / empty list");
		return;
	}
	t=start;
	if(pos==1){
		start=start->next;
		if(start!=NULL){
			start->prev=NULL;
		}
		printf("\ndeleted %d from %d",t->data,pos);
	}
	for(i=1; i<pos && t!=NULL; i++) {
        t = t->next;
    }
    if(t == NULL) {
        printf("\nPosition out of range\n");
        return;
    }

    if(t->prev != NULL)
        t->prev->next = t->next;
    if(t->next != NULL)
        t->next->prev = t->prev;
    free(t);
    printf("\nDeleted element at position %d\n", pos);

}

void display(){
	    struct Node *newNode = start;

	if(newNode==NULL){
		printf("\nempty list");
		return;
	}
	printf("\nlist : ");
	while(newNode!=NULL){
		printf("\t%d\t",newNode->data);
		newNode=newNode->next;
	}
}

void count(){
	    struct Node *newNode = start;

	int count=0;
	while(newNode!=NULL){
		count++;
		newNode=newNode->next;
	}
	printf("count = %d",count);
}

int main(){
	int i,val,pos,choice;
	while(1){
		printf("\nDoubly linked list\n1. create list \n2. insert \n3. delete \n4. display list \n5. count \n0. exit \n Enter your choice : ");
		scanf("%d",&choice);
		switch(choice){
			case 1	:	create();
						break;
			case 2	: 	printf("\nValue=?");
						scanf("%d",&val);
						printf("\nPosition=?");
						scanf("%d",&pos);
						insert_pos(pos,val);
						break;
			case 3	:	printf("\nPosition=?");
						scanf("%d",&pos);
						delete_pos(pos);
						break;
			case 4	:	display();
						break;
			case 5	:	count();
						break;
			case 0	:	exit(0);
						break;
			default	:	printf("\nInvalid choice!");
						break;

		}
	}
	return 0;
}
