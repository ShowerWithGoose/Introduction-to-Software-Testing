#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// ³õÊ¼»¯Õ»
void initStack(Stack *s) {
    s->top = -1;
}

// ÅÐ¶ÏÕ»ÊÇ·ñÎª¿Õ
int isEmpty(Stack *s) {
    return s->top == -1;
}

// ÅÐ¶ÏÕ»ÊÇ·ñÒÑÂú
int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// ÈëÕ»
void push(Stack *s, int element) {
    if (isFull(s)) {
        printf("error ");
        return;
    }
    s->data[++s->top] = element;
}

// ³öÕ»
int pop(Stack *s) {
    if (isEmpty(s)) { // @@ [Error: Missing check for empty stack before pop. When stack is empty, pop should print "error " and return a sentinel value, but the current code does not handle this case, leading to undefined behavior or incorrect output.]
        printf("error ");
        return -1; // @@ [Error: Returning -1 as a sentinel, but the main function's check `if (element != -1)` incorrectly treats -1 as an error indicator, which conflicts with valid pushed values like -56 or -45. This causes valid negative numbers to be suppressed or misidentified as errors.]
    }
    return s->data[s->top--];
}

int main() {
    Stack s;
    initStack(&s);

    int operation, element;
    while (1) {
        scanf("%d", &operation);
        if (operation == -1) {
            break;
        }
        switch (operation) {
            case 1:  
                scanf("%d", &element);
                push(&s, element);
                break;
            case 0:  
                element = pop(&s);
                if (element != -1) { // @@ [Error: This condition incorrectly filters out valid negative numbers (e.g., -56, -45) that are popped, causing them to be omitted from output. The check should not exclude -1 as a valid popped value.]
                    printf("%d ", element);
                }
                break;

        }
    }

    return 0;
}