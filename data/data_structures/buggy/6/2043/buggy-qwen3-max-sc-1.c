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
int isEmpty(int Stack[]) // @@ [The condition `top == 0` is incorrect for checking an empty stack. Since `top` is initialized to -1, an empty stack should satisfy `top == -1`. This causes pop operations on an empty stack to not be detected correctly, leading to undefined behavior or wrong output.]
{
    return (top == 0);
}