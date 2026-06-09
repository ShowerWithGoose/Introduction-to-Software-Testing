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
int pop(int s[])
{
    if(isempty())
        printf("error ");
    else
        return s[top--]; // @@ The pop function prints "error " when empty but does not return a value in that case, leading to undefined behavior. Additionally, the main function calls pop and then prints stack[top+1], which duplicates the pop logic and causes an extra element to be printed when the stack is empty (the previous top+1 value is printed incorrectly).
}
int main()
{
    int m,n;
    while(scanf("%d",&m)!=-1)
    {
        if(m==1)
        {
            scanf("%d",&n);
            push(stack,n);
        }
        else if(m==0)
        {
            pop(stack); // @@ This line calls pop which prints "error " if empty, but then the next line always prints stack[top+1], which for an empty stack prints an incorrect value (the previous element or garbage). The correct approach is to handle the pop and print in one place, not separately.
            printf("%d ",stack[top+1]); // @@ This line prints the element at top+1 after pop, but when pop fails (empty stack), top remains -1, so top+1 is 0, printing stack[0] which is incorrect. Also, when pop succeeds, this duplicates the pop logic; the pop function already returns the popped value, so it should be printed directly from pop's return value.
        }
        else
            break;
    }
    return 0;
}