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
                element = pop(&s); // @@ [The pop function does not check if the stack is empty before popping. When the stack is empty, s->top is -1, so accessing s->data[-1] is undefined behavior. Additionally, the code checks if the popped element is -1 to decide whether to print "error", but -1 could be a valid value pushed onto the stack, leading to incorrect output.]
                if (element != -1) { // @@ [This condition incorrectly assumes that a popped value of -1 indicates an empty stack. However, -1 can be a legitimate value pushed by the user (as in the test case: "1 -56", "1 -45"), so this logic fails to detect actual underflow and misinterprets valid -1 values as errors.]
                    printf("%d ", element);
                }
                break;

        }
    }

    return 0;
}