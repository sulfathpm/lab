#include <stdio.h>
#include <limits.h>

#define MAX 20

int parent[MAX];

int find(int i) {
    if (parent[i] != i) {
        parent[i] = find(parent[i]);
    }
    return parent[i];
}

void unionSet(int u, int v) {
    int rootU = find(u);
    int rootV = find(v);
    parent[rootV] = rootU;
}

int main() {
    int adj[MAX][MAX];
    int n;
    int edgeCount = 0;
    int u, v;
    int minWeight;
    int minCost = 0;
    int i, j;
    
    printf("Enter total number of vertices: ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        parent[i] = i;
    }
    
    printf("Enter adjacency matrix (use 0 for no edge):\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
            
            if(adj[i][j] == 0 && i != j) {
                adj[i][j] = INT_MAX;
            }
        }
    }
    
    printf("\nMinimum Spanning Tree using Kruskal's Algorithm:\n");
    
    while(edgeCount < n - 1) {
        u = -1;
        v = -1;
        minWeight = INT_MAX;
        
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
                if(adj[i][j] < minWeight && find(i) != find(j)) {
                    minWeight = adj[i][j];
                    u = i;
                    v = j;
                }
            }
        }
        
        if(u != -1 && v != -1) {
            unionSet(u, v);
            
            printf("Edge %d: (%d-%d) cost = %d\n", 
                   edgeCount + 1, u, v, minWeight);
            
            minCost += minWeight;
            
            adj[u][v] = INT_MAX;
            adj[v][u] = INT_MAX;
            
            edgeCount++;
        } else {
            printf("Graph is disconnected. Cannot complete MST.\n");
            break;
        }
    }
    
    if(edgeCount == n - 1) {
        printf("\nTotal weight of Minimum Spanning Tree = %d\n", minCost);
    }
    
    return 0;
}
