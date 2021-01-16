#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *firstNode = NULL;

void create(int A[], int n) {
    int i;
    struct Node *newNode, *lastNode;

    firstNode = (struct Node *)malloc(sizeof(struct Node));
    firstNode->data = A[0];
    firstNode->next = NULL;

    lastNode = firstNode;

    for (i = 1; i < n; i++) {
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

int main() {
    int A[] = {3, 5, 7, 10, 15, 8, 12, 20};

    create(A, 8);

    printf("\n************ Display Linked List ************\n");
    printf("[Iterative] ");
    display(firstNode);
    printf("\n[Recursive] ");
    recursiveDisplay(firstNode);

    printf("\n\n************ Length Linked List ************\n");
    printf("[Iterative]Length is: %d \n", count(firstNode));
    printf("[Recursive]Length is: %d \n", recursiveCount(firstNode));

    printf("\n************ Sum Linked List ************\n");
    printf("[Iterative]Sum is: %d\n", sum(firstNode));
    printf("[Recursive]Sum is: %d\n", recursiveSum(firstNode));

    printf("\n************ Max Linked List ************\n");
    printf("[Iterative]Max is: %d\n", max(firstNode));
    printf("[Recursive]Max is: %d\n", recursiveMax(firstNode));

    return 0;
}