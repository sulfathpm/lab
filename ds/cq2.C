#include<stdio.h>
#include<stdlib.h>

#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;

void create() {
    int n, val;
    front = -1;
    rear = -1;

    printf("\nN = ?\n");
    scanf("%d", &n);
    if (n > MAX || n <= 0) {
        printf("Invalid size");
        return;
    }

    printf("\nElements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        // if ((front == (rear + 1) % MAX)) {
        //     printf("\nQueue Overflow");
        //     return;
        // }
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        queue[rear] = val;
    }
}

void enqueue(int val) {
    if ((front == (rear + 1) % MAX)) {
        printf("\nQueue Overflow");
        return;
    }
    if (front == -1) front = 0;
    rear = (rear + 1) % MAX;
    queue[rear] = val;
    printf("\nInserted %d", val);
}

void dequeue() {
    int item;
    if (front == -1) {
        printf("\nQueue Underflow. Cannot delete.\n");
        return;
    }
    item = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    printf("\nDeleted %d from queue", item);
}

void display() {
    if (front == -1) {
        printf("\nQueue is empty.\n");
        return;
    }
    printf("\nElements of circular queue are: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

void count() {
    if (front == -1) {
        printf("\nCount = 0\n");
        return;
    }
    int c = 0;
    int i = front;
    while (1) {
        c++;
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\nCount = %d\n", c);
}

int main() {
    int ch, val;
    while (1) {
        printf("\nCircular Queue Menu\n");
        printf("1. Create\n2. Insert\n3. Delete\n4. Display\n5. Count\n0. Exit\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: create(); break;
            case 2: 
                printf("Value = ? ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 3: dequeue(); break;
            case 4: display(); break;
            case 5: count(); break;
            case 0:
                printf("\nExiting...\n");
                exit(0);
            default:
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}
