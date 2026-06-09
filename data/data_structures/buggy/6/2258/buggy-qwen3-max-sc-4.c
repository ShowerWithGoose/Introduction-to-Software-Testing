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
    if (isEmpty(s)) { // @@ [The pop function does not check if the stack is empty before popping, which can lead to undefined behavior and incorrect output when popping from an empty stack. According to the problem, "error " should be printed in this case.]
        printf("error ");
        return -1; // @@ [Returning -1 here is necessary to signal an error, but the original code just returns the popped value without any check.]
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
                if (element != -1) { // @@ [This condition assumes that -1 only comes from an error, but if the user actually pushes -1 onto the stack, this logic will incorrectly suppress printing it. However, according to the problem description, pushed integers are "not 1, 0, or -1", so -1 will never be a valid pushed value. Thus, this check is acceptable ONLY because of that constraint. But the real issue is that the pop() function above doesn't handle empty stack correctly, so this line may receive -1 even when no error occurred if -1 were allowed—but per problem, it's not. The core bug is missing empty check in pop().]
                    printf("%d ", element);
                }
                break;

        }
    }

    return 0;
}