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
    if(FULLS(top) == 1) // @@ Logical error: pop operation should check if the stack is empty using EMPTYS(top), not FULLS(top)
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
}

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
            pop(); // @@ Compilation error: function 'pop' is called before its definition/declaration, causing an implicit declaration error in C99 and later standards.
            continue;
        }
        else if(op == -1)
        {
            break;
        }
        else
        {
            scanf("%d",&num);
            push(num); // @@ Compilation error: function 'push' is called before its definition/declaration, causing an implicit declaration error in C99 and later standards.
        }        
    } 
    return 0;
 }