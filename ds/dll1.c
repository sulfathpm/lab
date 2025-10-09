#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next, *prev;
};

struct Node *start = NULL;

// Create doubly linked list
void create() {
    int i, n, val;
    struct Node *ptr, *t;

    printf("N=? ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Data(%d): ", i + 1);
        scanf("%d", &val);

        ptr = (struct Node*) malloc(sizeof(struct Node));
        ptr->data = val;
        ptr->next = NULL;
        ptr->prev = NULL;

        if (start == NULL) {
            start = ptr;
            t = ptr;
        } else {
            t->next = ptr;
            ptr->prev = t;
            t = ptr;
        }
    }
    printf("\nCreated doubly linked list with %d elements.\n", n);
}

// Insert at a given position
void insert_pos(int pos, int val) {
    int i;
    struct Node *ptr, *temp;
    ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr->data = val;
    ptr->next = ptr->prev = NULL;

    if (pos <= 0) {
        printf("\nInvalid position\n");
        free(ptr);
        return;
    }

    if (pos == 1) {
        ptr->next = start;
        if (start != NULL)
            start->prev = ptr;
        start = ptr;
        printf("\nElement %d inserted at position %d\n", val, pos);
        return;
    }

    temp = start;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nPosition out of range\n");
        free(ptr);
        return;
    }

    ptr->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = ptr;
    ptr->prev = temp;
    temp->next = ptr;

    printf("\nElement %d inserted at position %d\n", val, pos);
}

// Delete at position
void delete_pos(int pos) {
    int i;
    struct Node *temp;

    if (start == NULL || pos <= 0) {
        printf("\nInvalid position or empty list\n");
        return;
    }

    temp = start;
    if (pos == 1) {
        start = start->next;
        if (start != NULL)
            start->prev = NULL;
        printf("\nDeleted element: %d\n", temp->data);
        free(temp);
        return;
    }

    for (i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nPosition out of range\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    printf("\nDeleted element: %d\n", temp->data);
    free(temp);
}

// Display list
void display() {
    struct Node *ptr = start;
    if (ptr == NULL) {
        printf("\nList is empty\n");
        return;
    }
    printf("\nList: ");
    while (ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

// Count nodes
void count() {
    int cnt = 0;
    struct Node *ptr = start;
    while (ptr != NULL) {
        cnt++;
        ptr = ptr->next;
    }
    printf("\nCount = %d\n", cnt);
}

int main() {
    int val, pos, choice;
    while (1) {
        printf("\nDoubly linked list\n");
        printf("1. Create list\n2. Insert\n3. Delete\n4. Display list\n5. Count\n0. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: create(); break;
            case 2:
                printf("\nValue=? ");
                scanf("%d", &val);
                printf("Position=? ");
                scanf("%d", &pos);
                insert_pos(pos, val);
                break;
            case 3:
                printf("Position=? ");
                scanf("%d", &pos);
                delete_pos(pos);
                break;
            case 4: display(); break;
            case 5: count(); break;
            case 0: exit(0);
            default: printf("\nInvalid choice!\n");
        }
    }
    return 0;
}

