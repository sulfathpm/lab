#include<stdio.h>
#define MAX 10
int parent[MAX];
void makeSet(int n){
    for(int i=1;i<=n;i++)
        parent[i]=i;
}

int findSet(int u){
    if(parent[u]!=u)
        parent[u]=findSet(parent[u]);
    return parent[u];
}

void unionn(int u,int v){
    int parent_u=findSet(u);
    int parent_v=findSet(v);
    if(parent_u==parent_v)
        printf("\nCycle detected.\n");
    parent[parent_v]=parent_u;
}
void display(int n){
    printf("elements : parent \n");
    for(int i=1;i<=n;i++)
        printf("     %d   :   %d   \n",i,findSet(i));
}

void main(){
    int count,i,u,v,n;
    printf("\nN=?");
    scanf("%d",&n);
    printf("\nNo. of times union operation to be executed : \n");
    scanf("%d",&count);
    makeSet(n);

    for(i=0;i<count;i++)
    {
        printf("\nEnter pair to join : ");
        scanf("%d%d",&u,&v);
        unionn(u,v);
        display(n);

    }
}
