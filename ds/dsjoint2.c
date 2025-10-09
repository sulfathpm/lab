#include <stdio.h>
#define MAX 10

int parent[MAX];

void makeSet(int n){
    for (int i=1;i<=n;i++)
        parent[i] = i;
}

int findSet(int u){
    if (parent[u]!=u)
        parent[u]=findSet(parent[u]); 
    return parent[u];
}

void unionn(int u,int v){
    int parent_u=findSet(u);
    int parent_v=findSet(v);

    if (parent_u==parent_v) {
        printf("\nCycle detected between %d and %d.\n", u, v);
    } else {
        parent[parent_v]=parent_u; 
    }
}

void display(int n){
    printf("\nElement : Parent\n");
    for (int i=1;i<=n;i++) {
        printf("   %d   :   %d\n", i, findSet(i));
    }
}

int main(){
    int count, i, u, v, n;

    printf("\nEnter number of elements (<= %d): ", MAX);
    scanf("%d", &n);

    makeSet(n);

    printf("\nHow many union operations? ");
    scanf("%d", &count);

    for (i = 0;i<count;i++){
        printf("\nEnter pair to join (u v): ");
        scanf("%d%d",&u,&v);
        unionn(u, v);
        display(n);
    }

    return 0;
}
