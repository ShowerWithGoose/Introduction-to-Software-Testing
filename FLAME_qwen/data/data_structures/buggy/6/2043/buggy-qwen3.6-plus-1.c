#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX 100

int Stack[MAX] = {0};//栈初始化为全0（入栈数字不可能为0，似乎不是十足重要）
int top = -1;

int main()
{
    int op, data;

    scanf("%d", &op);
    while(op != -1){
        if(op == 1){//入栈
            scanf("%d", &data);
            if(isFull(Stack)){ // @@ Function 'isFull' is called before its definition without a prior declaration, causing a compilation error in C99 and later standards.
                printf("error ");
            }else{
                Stack[++top] = data;
            }
        }
        else{//出栈
            if(isEmpty(Stack)){ // @@ Function 'isEmpty' is called before its definition without a prior declaration, causing a compilation error in C99 and later standards.
                printf("error ");
            }else{
                printf("%d ", Stack[top]);
                top--;
            }
        }
        scanf("%d", &op);
    }

    return 0;
}
/*判断是否满栈*/
int isFull(int Stack[])
{
    return (top == (MAX - 1));
}
/*判断是否空栈*/
int isEmpty(int Stack[])
{
    return (top == 0); // @@ Logical error: The stack is empty when 'top' equals -1, not 0. This condition will incorrectly report the stack as empty when it contains one element.
}