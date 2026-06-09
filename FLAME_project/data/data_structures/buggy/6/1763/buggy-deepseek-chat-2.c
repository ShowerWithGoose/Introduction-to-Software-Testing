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
    node* newnode = create(data);
    if (stack.top == NULL) {
        stack.top = newnode;
    }
    else {
        newnode->next = stack.top;
        stack.top = newnode;
    }
    stack.count++;
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
        if (n) { // @@ Error: The condition `if (n)` treats 0 as false and any non-zero as true, but the problem specifies that operation 1 is push and 0 is pop. Since 1 is non-zero, this correctly identifies push, but the logic is fragile. More critically, the input format uses "1" followed by data for push, but the code reads the first integer as the operation, then inside the loop reads data only when n is non-zero. However, the main issue is that after reading data for a push, the next iteration reads the next operation, but the loop does not read the next operation correctly because the scanf for n is only at the beginning. This causes an infinite loop or incorrect parsing.
            scanf("%d", &data);
            push(data);
        }
        else {
            pop();
        }
    }
}