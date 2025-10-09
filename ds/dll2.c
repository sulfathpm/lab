#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node *next, *prev;
};

struct Node *start = NULL;

void create() {
    int i, n, val;
    struct Node *ptr, *t;
    printf("N=? ");
    scanf("%d", &n);

    for(i=0; i<n; i++) {
        printf("Data(%d): ", i+1);
        scanf("%d", &val);
        ptr = (struct Node*) malloc(sizeof(struct Node));
        ptr->data = val;
        ptr->next = NULL;
        ptr->prev = NULL;

        if(start == NULL) {
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

void insert_pos(int pos, int val) {
    struct Node *ptr, *t;
    int i;
    ptr = (struct Node*) malloc(sizeof(struct Node));
    ptr->data = val;
    ptr->next = NULL;
    ptr->prev = NULL;

    if(pos <= 0) {
        printf("\nInvalid position\n");
        return;
    }

    if(pos == 1) { // Insert at beginning
        ptr->next = start;
        if(start != NULL)
            start->prev = ptr;
        start = ptr;
    } else {
        t = start;
        for(i=1; i<pos-1 && t!=NULL; i++) {
            t = t->next;
        }
        if(t == NULL) {
            printf("\nPosition out of range\n");
            free(ptr);
            return;
        }
        ptr->next = t->next;
        ptr->prev = t;
        if(t->next != NULL)
            t->next->prev = ptr;
        t->next = ptr;
    }
    printf("\nElement %d inserted at position %d\n", val, pos);
}

void delete_pos(int pos) {
    struct Node *t;
    int i;

    if(start == NULL || pos <= 0) {
        printf("\nInvalid position or empty list\n");
        return;
    }

    t = start;

    if(pos == 1) { // delete first node
        start = start->next;
        if(start != NULL)
            start->prev = NULL;
        free(t);
        printf("\nDeleted element at position 1\n");
        return;
    }

    for(i=1; i<pos && t!=NULL; i++) {
        t = t->next;
    }
    if(t == NULL) {
        printf("\nPosition out of range\n");
        return;
    }

    if(t->prev != NULL)
        t->prev->next = t->next;
    if(t->next != NULL)
        t->next->prev = t->prev;
    free(t);
    printf("\nDeleted element at position %d\n", pos);
}

void display() {
    struct Node *ptr = start;
    printf("\nList: ");
    if(ptr == NULL) {
        printf("Empty\n");
        return;
    }
    while(ptr != NULL) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

void count() {
    struct Node *ptr = start;
    int c = 0;
    while(ptr != NULL) {
        c++;
        ptr = ptr->next;
    }
    printf("\nCount = %d\n", c);
}

int main() {
    int val, pos, choice;
    while(1) {
        printf("\nDoubly linked list\n");
        printf("1. Create list\n2. Insert\n3. Delete\n4. Display list\n5. Count\n0. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1: create(); break;
            case 2: 
                printf("Value=? ");
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

