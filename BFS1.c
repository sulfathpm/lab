#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue overflow!\n");
        return;
    }
    if (front == -1)
        front = 0;
        rear++;
    queue[rear] = value;
}

int dequeue() {
    int value;
    if (front == -1 || front > rear) {
        printf("Queue underflow!\n");
        return -1;
    }
    value = queue[front];
    front++;
    return value;
}

int isEmpty() {
    return (front == -1 || front > rear);
}

void bfs(int adj[MAX][MAX], int vertices, int start) {
    int visited[MAX] = {0};

    enqueue(start);
    visited[start] = 1;

    printf("BFS Traversal: ");

    while (!isEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < vertices; i++) {
            if (adj[current][i] == 1 && visited[i] == 0) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int vertices, start;
    int adj[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter adjacency matrix (%dx%d):\n", vertices, vertices);
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter starting vertex (0 - %d): ", vertices - 1);
    scanf("%d", &start);

    bfs(adj, vertices, start);

    return 0;
}
