#include<stdio.h>
#include<stdlib.h>
#define MAX 10 

void prims(graph[MAX][MAX],n){
    
}

void main(){
    int n;
    int graph[MAX][MAX];
    printf("\nEnter no. the vertices : ");
    scanf("%d",&n);
    printf("\nEnter the adjacency matrix(0 if no edge) : ");
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&graph[i][j]);

    prims(graph,n);
}