#define _CRT_SECURE_NO_WARNINGS
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stacknode {
    int data;
    struct stacknode* next;
} node;

typedef struct stacktop {
    node* top;
    int count;
} top;

top stack; // @@ [Global variable 'stack' is not initialized, so 'stack.top' and 'stack.count' have undefined values, leading to undefined behavior during push/pop operations.]

node* create(int data) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void push(int data) {
    node* newnode = create(data);
    if (stack.top == NULL) {
        stack.top = newnode;
    }
    else {
        newnode->next = stack.top;
        stack.top = newnode;
    }
    stack.count++; // @@ [No check for stack overflow (max capacity 100). Pushing beyond 100 elements should print "error ", but this is missing.]
}

void pop() {
    if (stack.top == NULL) {
        printf("error ");
    }
    else {
        node* temp = stack.top;
        printf("%d ", temp->data);
        stack.top = stack.top->next;
        free(temp);
        stack.count--;
    }
}

int main() {
    int n;
    int data;
    scanf("%d", &n);
    while (n != -1) {
        if (n) { // @@ [Condition 'if (n)' treats any non-zero value as a push operation, but according to the problem only '1' should trigger a push. Input like '2 100' would incorrectly be treated as push.]
            scanf("%d", &data);
            push(data);
        }
        else {
            pop();
        }
        scanf("%d", &n); // @@ [Missing input read at the end of the loop. The loop condition checks 'n != -1', but 'n' is never updated inside the loop after the first read, causing an infinite loop (Time Limit Exceeded).]
    }
}