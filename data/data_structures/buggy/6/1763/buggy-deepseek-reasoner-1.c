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

top stack;

node* create(int data) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void push(int data) {
    node* newnode = create(data); // @@ missing check if stack is full (count >= 100)
    if (stack.top == NULL) {
        stack.top = newnode;
    }
    else {
        newnode->next = stack.top;
        stack.top = newnode;
    }
    stack.count++; // @@ should only increment if push succeeded; also missing overflow check
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
        if (n) {
            scanf("%d", &data);
            push(data);
        }
        else {
            pop();
        }
    } // @@ missing scanf to read next operation, causing infinite loop
}