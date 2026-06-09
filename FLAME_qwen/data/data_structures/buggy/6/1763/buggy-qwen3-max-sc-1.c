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

top stack; // @@ [Global variable 'stack' is not initialized, leading to undefined behavior when checking 'stack.top == NULL' or accessing 'stack.count']

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
    stack.count++; // @@ [If 'stack' is uninitialized, 'stack.count' may contain garbage, causing incorrect count and potential overflow beyond MAXSIZE=100]
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
        stack.count--; // @@ [Same issue: uninitialized 'stack.count' leads to undefined behavior during decrement]
    }
}

int main() {
    int n;
    int data;
    scanf("%d", &n);
    while (n != -1) {
        if (n) {
            scanf("%d", &data);
            push(data);
        }
        else {
            pop();
        }
        scanf("%d", &n); // @@ [Missing this line causes infinite loop because 'n' is never updated after the first read; the loop condition 'n != -1' will never change]
    }
}