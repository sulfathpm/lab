#include <stdio.h>
#define MAX 10

int parent[MAX];
int n;  // Number of elements in the set

// Initialize sets: each element is its own parent
void makeSet(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }
}

// Find the representative (root) of the set that element u belongs to
int findSet(int u) {
    if (parent[u] != u) {
        parent[u] = findSet(parent[u]);  // Path compression
    }
    return parent[u];
}

// Union operation to merge sets containing u and v
void unionSet(int u, int v) {
    int parent_u = findSet(u);
    int parent_v = findSet(v);

    if (parent_u == parent_v) {
        printf("Cycle detected when trying to union %d and %d.\n", u, v);
    } else {
        parent[parent_u] = parent_v;
        printf("Union done for %d and %d.\n", u, v);
    }
}

int main() {
    int count, u, v;

    printf("Enter number of elements (max %d): ", MAX);
    scanf("%d", &n);

    if (n > MAX) {
        printf("Number of elements exceeds max limit.\n");
        return 1;
    }

    makeSet(n);

    printf("Enter number of union operations: ");
    scanf("%d", &count);

    for (int i = 0; i < count; i++) {
        printf("Enter pair to union (u v): ");
        scanf("%d %d", &u, &v);

        if (u >= n || v >= n || u < 0 || v < 0) {
            printf("Invalid elements. Try again.\n");
            i--;  // retry this iteration
            continue;
        }

        unionSet(u, v);
    }

    printf("Final parents array:\n");
    for (int i = 0; i < n; i++) {
        printf("Element %d -> Parent %d\n", i, findSet(i));
    }

    return 0;
}
