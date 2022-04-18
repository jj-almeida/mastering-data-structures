#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *firstNode = NULL;

void create(int A[], int n) {
    struct Node *newNode, *lastNode;

    firstNode = (struct Node *)malloc(sizeof(struct Node));
    firstNode->data = A[0];
    firstNode->next = NULL;

    lastNode = firstNode;

    for (int i = 1; i < n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = A[i];
        newNode->next = NULL;
        
        lastNode->next = newNode;
        lastNode = newNode;
    }
}

void display(struct Node *p) {
    while(p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}

void recursiveDisplay(struct Node *p) {
    if(p) {
        printf("%d ", p->data);
        recursiveDisplay(p->next);
    }
}

int count(struct Node *p) {
    int length = 0;

    while(p) {
        length++;
        p = p->next;
    }
    return length;
}

int recursiveCount(struct Node *p) {
    if(!p)
        return 0;
    else
        return recursiveCount(p->next) + 1;
}

int sum(struct Node *p) {
    int sum = 0;

    while(p) {
        sum += p->data;
        p = p->next;
    }

    return sum;
}

int recursiveSum(struct Node *p) {
    int sum = 0;

    if(!p)
        return 0;
    else
        return recursiveSum(p->next) + p->data;
}

int max(struct Node *p) {
    int max = INT_MIN;

    while(p) {
        if(p->data > max)
            max = p->data;
        p = p->next;
    }

    return max;
}

int recursiveMax(struct Node *p) {
    int max = INT_MIN;

    if (!p)
        return INT_MIN;

    max = recursiveMax(p->next);

    if(max > p->data)
        return max;
    else
        return p->data;
}

struct Node * linearSearch(struct Node *p, int key) {
    while(p && key != p->data)
        p = p->next;

    return p;
}

struct Node * recursiveSearch(struct Node *p, int key) {
    if(!p)
        return NULL;
    if(key == p->data)
        return p;
    return recursiveSearch(p->next, key);
}

void insert(struct Node *p, int index, int data) {
    struct Node *newNode;
    
    if (index < 0 || index > count(p))
        return;
    
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;

    if (index == 0) {
        newNode->next = firstNode;
        firstNode = newNode;
    }
    else {
        for (int i = 0; i < index-1; i++)
            p= p->next;
        
        newNode->next = p->next;
        p->next = newNode;
    }
}

void sortedInsert(struct Node *p, int data) {
    struct Node *newNode, *q = NULL;

    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (!firstNode)
        firstNode = newNode;
    else {
        while(p && p->data < data) {
            q = p;
            p = p->next;
        }
        if (p == firstNode) {
            newNode->next = firstNode;
            firstNode = newNode;
        } else {
            newNode->next = q->next;
            q->next = newNode;
        }
    }
}

int delete(struct Node *p, int index) {
    struct Node *q = NULL;
    int x = -1;

    if (index < 1 || index > count(p))
        return -1;
    if (index == 1) {
        q = firstNode;
        x = firstNode->data;
        firstNode = firstNode->next;
        
        free(q);

        return x;
    }
    else {
        for (int i = 0; i < index-1; i++) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        
        free(p);
        
        return x;
    }
}

int main() {
    struct Node *tmp;
    int A[] = {3, 5, 7, 10, 12, 15, 20};

    create(A, 7);

    printf("\n***********************************************************\n");
    printf("** \t\t\t Linked List \t\t\t **");
    printf("\n***********************************************************\n");

    printf("\n\t\t Display \n");
    printf("[Iterative] ");
    display(firstNode);
    printf("\n[Recursive] ");
    recursiveDisplay(firstNode);

    printf("\n\n\n\t\t Length \n");
    printf("[Iterative]Length is: %d \n", count(firstNode));
    printf("[Recursive]Length is: %d \n", recursiveCount(firstNode));

    printf("\n\n\t\t Sum \n");
    printf("[Iterative]Sum is: %d\n", sum(firstNode));
    printf("[Recursive]Sum is: %d\n", recursiveSum(firstNode));

    printf("\n\t\t Max\n");
    printf("[Iterative]Max is: %d\n", max(firstNode));
    printf("[Recursive]Max is: %d\n", recursiveMax(firstNode));

    printf("\n\t\t Linear Search\n");
    tmp = linearSearch(firstNode, 15);
    if(tmp)
        printf("[Iterative]Key found: %d\n", tmp->data);
    else
        printf("[Iterative]Key not found\n");

    tmp = recursiveSearch(firstNode, 15);
    if(tmp)
        printf("[Recursive]Key found: %d\n", tmp->data);
    else
        printf("[Recursive]Key not found\n");

    printf("\n\t\t Insert \n");
    printf("[Before Insert] ");
    display(firstNode);
    insert(firstNode, 4, 2);
    printf("\n[After Insert] ");
    display(firstNode);

    printf("\n\n\t\t Sorted Insert\n");
    printf("[Before Sorted Insert] ");
    display(firstNode);
    sortedInsert(firstNode, 25);
    printf("\n[After Sorted Insert] ");
    display(firstNode);

    printf("\n\n\t\t Delete\n");
    printf("[Before Delete] ");
    display(firstNode);
    delete(firstNode, 2);
    printf("\n[AfterDelete] ");
    display(firstNode);

    return 0;
}