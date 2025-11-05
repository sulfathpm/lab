#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define INF 9999

int parent[MAX];

int find(int i){
    while(parent[i]!=i){
        i=parent[i];
    }
    return i;
}

void union_set(int i,int j){
    int a=find(i);
    int b=find(j);
    parent[a]=b;
}

void kruskal(int cost[MAX][MAX],int n){
    int mincost=0;
    int edges=0;
    for(int i=1;i<=n;i++){
        parent[i]=i;
    }
    printf("\nMinimum cost spanning tree edges : \n");
    while(edges<n-1){
        int min=INF;
        int u=-1,v=-1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(find(i)!=find(j)&&cost[i][j]<min){
                    min=cost[i][j];
                    u=i;
                    v=j;
                }
            }
        }
        if(u==-1||v==-1) break;
        union_set(u,v);
        printf("edge %d : (%d - %d) cost : %d\n",edges+1,u,v,min);
        mincost+=min;
        edges++;
        cost[u][v]=cost[v][u]=INF;
    }
    printf("Total minimum cost = %d\n",mincost);
}

int main(){
    int n;
    int cost[MAX][MAX];
    printf("\nEnter number of vertices : ");
    scanf("%d",&n);
    printf("\nEnter cost adjacency matrix : \n");
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&cost[i][j]);
        }
    }
    kruskal(cost,n);
    return 0;
}