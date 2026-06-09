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
int isEmpty(int Stack[])
{
    return (top == 0); // @@ [Error: The condition for an empty stack should be top == -1, not top == 0. With top initialized to -1, the first push sets top to 0, so top == 0 indicates one element in the stack, not empty. This causes the pop operation to incorrectly treat a non-empty stack as empty, leading to "error" output instead of popping the value.]
}