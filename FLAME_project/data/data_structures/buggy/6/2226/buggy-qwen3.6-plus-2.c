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
                        printf("error "); // @@ The original code printed "error %d\n" which includes the element and a newline. The expected output format requires "error " followed by a space, and all outputs should be on a single line separated by spaces. The newline breaks the single-line requirement and the extra element is not part of the "error" token definition in the problem statement (which just says output string "error" followed by a space).
                    }  
                } else {  
                    printf("error "); // @@ The original code printed "error \n". Similar to above, the newline breaks the single-line output requirement. It should just be "error ".
                }  
                break;  
            case 0: // 出栈操作  
                if (pop(&stack, &element)) {  
                    printf("%d ", element); // 输出出栈元素  
                } else {  
                    printf("error "); // @@ The original code printed "error \n". The newline breaks the single-line output requirement. It should just be "error ".
                }  
                break;  
            default:  
                printf("error "); // @@ The original code printed "error \n". The newline breaks the single-line output requirement. It should just be "error ".
                break;  
        }  
    }  
  
    return 0;  
}