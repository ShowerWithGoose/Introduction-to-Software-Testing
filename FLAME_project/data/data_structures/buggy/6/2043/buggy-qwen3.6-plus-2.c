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
            if(isFull(Stack)){
                printf("error ");
            }else{
                Stack[++top] = data;
            }
        }
        else{//出栈 
            if(isEmpty(Stack)){
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
int isEmpty(int Stack[]) // @@ The condition for an empty stack is incorrect. Since `top` is initialized to -1, an empty stack corresponds to `top == -1`. The current code checks `top == 0`, which means the stack is considered empty only when it has one element (index 0) or is truly empty if logic was consistent, but here it fails to identify the initial empty state (-1) as empty, causing "error" to be printed incorrectly or logic to fail. Specifically, with `top = -1`, `isEmpty` returns false (0), so the code tries to pop from an empty stack.
{
    return (top == 0);
}