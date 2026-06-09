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

top stack; // @@ [Global variable 'stack' is not initialized, so 'stack.top' and 'stack.count' have undefined values, leading to incorrect behavior during push/pop checks]

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
    stack.count++; // @@ [No check for stack overflow (max capacity 100); violates problem constraints]
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
        if (n) { // @@ [Condition 'if (n)' treats any non-zero value as push, but problem specifies only '1' means push; e.g., input '567' after '1' is read correctly, but if an operation code other than 1/0/-1 appears, it will be misinterpreted]
            scanf("%d", &data);
            push(data);
        }
        else {
            pop();
        }
        scanf("%d", &n); // @@ [Missing this line causes infinite loop because 'n' is never updated inside the loop after the first read, leading to Time Limit Exceeded]
    }
}