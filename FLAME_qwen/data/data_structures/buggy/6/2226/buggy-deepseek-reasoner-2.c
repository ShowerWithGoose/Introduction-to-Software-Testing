#include <stdio.h>  
#include <stdlib.h>  
#include <stdbool.h>  
  
#define MAX_STACK_SIZE 100  
  
typedef struct {  
    int top;  
    int data[MAX_STACK_SIZE];  
} Stack;  
  
// 初始化栈  
void initStack(Stack *s) {  
    s->top = -1;  
}  
  
// 检查栈是否满  
bool isStackFull(Stack *s) {  
    return s->top == MAX_STACK_SIZE - 1;  
}  
  
// 检查栈是否为空  
bool isStackEmpty(Stack *s) {  
    return s->top == -1;  
}  
  
// 入栈操作  
bool push(Stack *s, int item) {  
    if (isStackFull(s)) {  
        return false; // 栈满，返回失败  
    }  
    s->data[++(s->top)] = item;  
    return true; // 入栈成功  
}  
  
// 出栈操作  
bool pop(Stack *s, int *item) {  
    if (isStackEmpty(s)) {  
        return false; // 栈空，返回失败  
    }  
    *item = s->data[(s->top)--];  
    return true; // 出栈成功  
}  
  
int main() {  
    Stack stack;  
    initStack(&stack);  
    int operation, element;  
  
    // 读取操作序列直到遇到-1  
    while (1) {  
        scanf("%d", &operation);  
        if (operation == -1) {  
            break; // 结束操作  
        }  
  
        switch (operation) {  
            case 1: // 入栈操作  
                if (scanf("%d", &element) == 1 && element != 1 && element != 0 && element != -1) {  // @@ The condition unnecessarily restricts valid push values and deviates from the reference program; the check for element not being 1,0,-1 is not required and could cause incorrect behavior if input violates the assumed constraint.
                    if (!push(&stack, element)) {  
                        printf("error %d\n", element);  // @@ The output format is incorrect: should print "error " (with space, no newline, no number). The reference program prints "error " for a full stack push.
                    }  
                } else {  
                    printf("error \n");  // @@ The output format is incorrect: should print "error " without newline. Also, this case is not defined in the problem specification.
                }  
                break;  
            case 0: // 出栈操作  
                if (pop(&stack, &element)) {  
                    printf("%d ", element); // 输出出栈元素  
                } else {  
                    printf("error \n");  // @@ The output format is incorrect: should print "error " (with space, no newline). The reference program prints "error " for an empty stack pop.
                }  
                break;  
            default:  
                printf("error \n");  // @@ The default case is not specified in the problem; if executed, the output format is incorrect (newline) and may break the required output.
                break;  
        }  
    }  
  
    return 0;  
}