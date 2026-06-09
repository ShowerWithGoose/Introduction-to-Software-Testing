#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
typedef struct {
    int data[100];
    int top;
    int bottom;
}stack;
stack* StackCreate() {
    stack* p = (stack*)malloc(sizeof(stack));//分配新空间 
    if (p == NULL)//分配失败 
        return 0;
    p->bottom = 0;
    p->top =-1;//分配成功 
    return p;
}
int POP(stack *p)
{
    int str;
    if(p->top>=p->bottom)
    {
        str = p->data[p->top];
        (p->top)--;
        return str;
    }
    
} // @@ Compilation error: The non-void function 'POP' does not return a value on all control paths. A return statement is missing when the stack is empty.
void PUSH(stack* p, int str)
{
    (p->top)++;
    p->data[p->top] = str;
}
int main()
{
    stack* p = StackCreate();
    int n,x,ans;
    scanf("%d", &n);
    while (n != -1)
    {
        if (n == 1)
        {
            scanf("%d", &x);
            if (p->top + 1 < 100)
            {
                PUSH(p, x);
            }
            else
            {
                printf("error ");
            }
        }
        else if(n==0)
        {
            if (p->top >= p->bottom)
            {
                ans = POP(p);
                printf("%d ", ans);
            }
            else
            {
                printf("error"); // @@ Logical error: The output format specification requires a space after "error", but it is missing here.
            }
        }    
        
        scanf("%d", &n);
    }
}