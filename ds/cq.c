#include<stdio.h>
#include<stdlib.h>

#define MAX 10
int queue[MAX];

int rear=-1;
int front=-1;

void create(){
    int queue[MAX];
    int front,rear,val;
    front=-1;
    rear=-1;
    int i,n;
    printf("\nN=?\n");
    scanf("%d",&n);
    if(n>MAX||n<=0){
        printf("invalid size");
        return;
    }
    printf("\nElements  : \n");
    // i=front;
    for(i=0;i<n;i++){
        scanf("%d",&val);
            if(front==-1)front=0;

        rear=(rear+1)%MAX;
        queue[rear]=val;
        
    }
}

void enqueue(int val){
    int queue[MAX];
    int front,rear;
    front=-1;
    rear=-1;
    if(front==(rear+1)%MAX){
        printf("\nQueue Overflow");
        return;
    }
       if(front==-1) front=0;

    rear=(rear+1)%MAX; 
    queue[rear]=val;
    printf("\ninserted %d",val);
}

void dequeue(){
     int item;
    int queue[MAX];
    int front,rear;
    if(front==-1){
        printf("\nqueue underflow.\nCannot insert.\n");
        
    } 
    item=queue[front];

    if(front==rear){
        front=-1;
        rear=-1;
    } else{
    front=(front+1)%MAX;
    
    }
        printf("\nDeleted %d from queue",item);

}

void display(){
            int queue[MAX];

     int front,rear,i;
    if(front==-1){
        printf("\nqueue underflow.\nNothing to display!\n");
        return;
    }
    printf("\nElements of cq are : ");
    i=front;
    while(1){
        printf("%d",queue[i]);
        if(i==rear)break;
        i=(i+1)%MAX;
    }
    printf("\n");
}

void count(){
        int queue[MAX];
    int c,i,front,rear;
    if(front==-1){
        printf("\nCount = 0\n");
        return;
    }
    i=front;
    while(1){
        c++;
        if(i==rear)break;
        i=(i+1)%MAX;
    }
    printf("\n Count =  ",c);

}

int main(){
    int ch,val;
    while(1){
        printf("\ncircular Queue\n1.Create. \n2.Insert. \n3.Delete. \n4.display. \n5.count. \n0.exit. \nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1  :   create();
                        break;
            case 2  :   printf("value=?");
                        scanf("%d",&val);
                        enqueue(val);
                        break;
            case 3  :   dequeue();
                        break;
            case 4  :   display();
                        break;
            case 5  :   count();
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