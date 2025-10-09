#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int queue[MAX];
int rear = -1;
int front = -1;

void create() {
    int n, i;
    front = rear = -1;  // reset queue
    printf("\nN=?\n");
    scanf("%d", &n);
    if (n > MAX || n <= 0) {
        printf("Invalid size\n");
        return;
    }
    printf("\nElements : \n");
    for (i = 0; i < n; i++) {
        int val;
        scanf("%d", &val);
        // if (rear == MAX - 1 && front == 0 || (rear + 1) % MAX == front) {
        //     printf("\nQueue Overflow\n");
        //     return;
        // }
        if (front == -1) front = 0;
        rear = (rear + 1) % MAX;
        queue[rear] = val;
    }
}

void enqueue(int val) {
    if (front == (rear + 1) % MAX) {
        printf("\nQueue Overflow\n");
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
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
    printf("\nDeleted %d from queue", item);
}

void display() {
    int i;
    if (front == -1) {
        printf("\nQueue is empty. Nothing to display!\n");
        return;
    }
    printf("\nElements of circular queue are : ");
    i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

void count() {
    int c = 0, i;
    if (front == -1) {
        printf("\nCount = 0\n");
        return;
    }
    i = front;
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
        printf("\nCircular Queue\n1.Create \n2.Insert \n3.Delete \n4.Display \n5.Count \n0.Exit \nEnter your choice : ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: create(); break;
            case 2: printf("Value=? "); scanf("%d", &val); enqueue(val); break;
            case 3: dequeue(); break;
            case 4: display(); break;
            case 5: count(); break;
            case 0: printf("\nExiting.......\n"); exit(0);
            default: printf("\nInvalid choice!\n");
        }
    }
    return 0;
}
