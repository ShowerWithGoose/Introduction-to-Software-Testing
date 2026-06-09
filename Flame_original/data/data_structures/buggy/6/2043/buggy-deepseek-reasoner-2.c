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
            if(isFull(Stack)){ // @@ 函数isFull在使用前未声明，需在main前添加函数声明或将其定义移到main之前
                printf("error ");
            }else{
                Stack[++top] = data;
            }
        }
        else{//出栈 
            if(isEmpty(Stack)){ // @@ 函数isEmpty在使用前未声明，需在main前添加函数声明或将其定义移到main之前
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
    return (top == 0); // @@ 空栈条件应为top == -1，而非top == 0；初始top = -1，栈空时top应为-1
}