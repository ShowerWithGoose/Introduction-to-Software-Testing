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
    return s->data[s->top--]; // @@ [The pop function does not check if the stack is empty before popping. According to the problem, attempting to pop from an empty stack should output "error ". The current implementation will access invalid memory (s->data[-1]) when the stack is empty, leading to undefined behavior and failing to print "error ".]
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
                element = pop(&s); // @@ [Because the pop function does not handle the empty stack case, this line may receive garbage or undefined values when popping from an empty stack. Additionally, the condition `if (element != -1)` assumes that -1 indicates an error, but the pop function never returns -1—it always returns a value from the stack, even when invalid. This leads to incorrect output instead of "error ".]
                if (element != -1) {
                    printf("%d ", element);
                }
                break;

        }
    }

    return 0;
}