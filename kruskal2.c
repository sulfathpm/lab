#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 9999

int parent[MAX];

int find(int i) {
    while (parent[i] != i) {
        i = parent[i];
    }
    return i;
}

void union_set(int i, int j) {
    int a = find(i);
    int b = find(j);
    parent[a] = b;
}

void kruskal(int cost[MAX][MAX], int n, int t[MAX][2]) {
    int mincost = 0;
    int edges = 0;

    // Initialize each vertex as its own parent
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }

    while (edges < n - 1) {
        int min = INF;
        int u = -1, v = -1;

        // Find the minimum edge that connects two different components
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (find(i) != find(j) && cost[i][j] < min) {
                    min = cost[i][j];
                    u = i;
                    v = j;
                }
            }
        }

        if (u == -1 || v == -1)
            break;

        union_set(u, v);

        // Store edge in t array (like in Prim's)
        edges++;
        t[edges][0] = u;
        t[edges][1] = v;

        mincost += min;

        // Mark edge as used
        // cost[u][v] = cost[v][u] = INF;
    }

    // Print MST edges and total cost (just like Prim's)
    printf("\nMinimum cost spanning tree edges:\n");
    for (int i = 1; i < n; i++) {
        int u = t[i][0];
        int v = t[i][1];
        printf("edge %d : ( %d , %d ) cost : %d\n", i, u, v, cost[u][v]);
    }
    printf("Total minimum cost : %d\n", mincost);
}

int main() {
    int n;
    int cost[MAX][MAX];
    int t[MAX][2];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix (9999 for no edge):\n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &cost[i][j]);
        }
    }

    kruskal(cost, n, t);

    return 0;
}
