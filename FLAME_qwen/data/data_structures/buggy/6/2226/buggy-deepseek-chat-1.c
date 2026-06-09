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
                if (scanf("%d", &element) == 1 && element != 1 && element != 0 && element != -1) { // @@ [错误：根据问题描述，push操作只检查操作码1，后面跟的整数可以是任何值（包括1、0、-1），不应排除这些值；且当栈满时应输出"error "（带空格），而不是"error %d\n"]  
                    if (!push(&stack, element)) {  
                        printf("error %d\n", element); // @@ [错误：输出格式应为"error "（带空格），而不是"error %d\n"]  
                    }  
                } else {  
                    printf("error \n"); // @@ [错误：输出格式应为"error "（带空格），而不是"error \n"]  
                }  
                break;  
            case 0: // 出栈操作  
                if (pop(&stack, &element)) {  
                    printf("%d ", element); // 输出出栈元素  
                } else {  
                    printf("error \n"); // @@ [错误：输出格式应为"error "（带空格），而不是"error \n"]  
                }  
                break;  
            default:  
                printf("error \n"); // @@ [错误：输出格式应为"error "（带空格），而不是"error \n"]  
                break;  
        }  
    }  
  
    return 0;  
}