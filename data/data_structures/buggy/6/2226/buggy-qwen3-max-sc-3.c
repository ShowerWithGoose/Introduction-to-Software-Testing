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
                if (scanf("%d", &element) == 1 && element != 1 && element != 0 && element != -1) {  
                    if (!push(&stack, element)) {  
                        printf("error %d\n", element); // @@ [According to the problem, when a push fails due to full stack, only "error " (with space, no newline, and without the element) should be printed. Also, printing the element is incorrect.]
                    }  
                } else {  
                    printf("error \n"); // @@ [The problem expects "error " followed by a space and no newline. Also, this branch handles invalid input format or disallowed values (1,0,-1), but the problem states that the pushed integer is guaranteed not to be 1,0,-1, so this check may be unnecessary and causes wrong output format with newline.]
                }  
                break;  
            case 0: // 出栈操作  
                if (pop(&stack, &element)) {  
                    printf("%d ", element); // 输出出栈元素  
                } else {  
                    printf("error \n"); // @@ [The problem requires "error " followed by a space, not a newline. Using \n instead of space breaks output format.]
                }  
                break;  
            default:  
                printf("error \n"); // @@ [The problem does not mention handling of invalid operations other than 1, 0, -1. However, if such input occurs, it should print "error " with space, not newline. Also, per problem description, operations are only 1, 0, or -1, so this may be unreachable, but output format is still wrong.]
                break;  
        }  
    }  
  
    return 0;  
}