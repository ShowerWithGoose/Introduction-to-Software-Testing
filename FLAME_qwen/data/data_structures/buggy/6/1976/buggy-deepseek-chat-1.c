#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
int stack[100];
int top=-1;
int isempty()
{
    return top==-1;
}
int isfull()
{
    return top==99;
}
void push(int s[],int item)
{
    if(isfull())
        printf("error ");
    else
        s[++top]=item;
}
int pop(int s[]) // @@ [Error: The function is declared to return int, but when the stack is empty it prints "error " and does not return a value, leading to undefined behavior. It should either return a dummy value or be changed to void.]
{
    if(isempty())
        printf("error ");
    else
        return s[top--];
}
int main()
{
    int m,n;
    while(scanf("%d",&m)!=-1) // @@ [Error: scanf returns the number of items read, not -1 on end-of-file. It should check for EOF, e.g., while(scanf("%d",&m)!=EOF).]
    {
        if(m==1)
        {
            scanf("%d",&n);
            push(stack,n);
        }
        else if(m==0)
        {
            pop(stack);
            printf("%d ",stack[top+1]); // @@ [Error: After pop, top has already been decremented, so stack[top+1] is the popped element, but if pop printed "error " due to empty stack, this line will still print an invalid value. Also, the pop function prints "error " but does not return a value in that case, causing undefined behavior.]
        }
        else
            break;
    }
    return 0;
}