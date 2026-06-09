#include <stdio.h>
#include <stdlib.h>
#define MAX_CAPACITY 100

struct DATA{
    int data[MAX_CAPACITY];
    int top;
};

void init(struct DATA* stack) {
    stack->top = -1;
}

int is_empty(struct DATA* stack) {
    return stack->top == -1;
}

int is_full(struct DATA* stack) {
    return stack->top == MAX_CAPACITY - 1;
}

int main() {
    struct DATA stack;
    init(&stack);
    int op;
    int data;
    while ((scanf_s("%d",&op))!=EOF&&op!=-1) { // @@ [使用非标准函数scanf_s，应改为scanf，否则会导致编译错误]
        if (op == 1) {
            scanf_s("%d",&data); // @@ [同上，应使用scanf而非scanf_s]
            //可堆栈
            if (data == -1) // @@ [逻辑错误：data==-1不应导致退出循环，且问题描述明确数据不会被压入-1，此判断多余且错误]
                break;
            if (!is_full(&stack)) {
                stack.data[++stack.top] = data;
            }
            else
                printf("error ");
        }
        //出栈
        else if(op==0){
            //可删去元素
            if (!is_empty(&stack)) {
                printf("%d ", stack.data[stack.top]);
                stack.top--;
            }
            else
                printf("error ");
        }
    }
    return 0;
}