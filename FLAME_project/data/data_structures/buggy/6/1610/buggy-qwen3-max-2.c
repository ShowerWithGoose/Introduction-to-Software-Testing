#include <stdio.h>

#define M 100

int stack[M];
int top = -1;

int EMPTYS(int top)//空则返回1 
{
    return top == -1;
}

int FULLS(int top)//满了则返回1 
{
    return top == M - 1;
} 

int pop()
{
    int item;
    if(FULLS(top) == 1)
    {
        printf("error ");
        return 0;
    }
    else
    {
        item = stack[top--];
        printf("%d ",item);
    }
    return 0;
} // @@ [The pop function checks for FULLS instead of EMPTYS. It should check if the stack is empty before popping, not full.]

int push(int item)
{
    if(FULLS(top) == 1)
    {
        printf("error ");
        return 0;
    }
    else
    {
        stack[++top] = item;
        return 1;
    }
}
int main()
{
    int op,num;
    
    while(scanf("%d",&op) != EOF)
    {
        if(op == 0)
        {
            pop();
            continue;
        }
        else if(op == -1)
        {
            break;
        }
        else
        {
            scanf("%d",&num);
            push(num);
        }        
    } 
    return 0;
 }