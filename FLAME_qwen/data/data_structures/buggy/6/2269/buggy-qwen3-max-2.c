#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define maxsize 100
int top=-1;
int stack[maxsize];
void push(int a);
int pop();
int main()
{
    int a,op;
    scanf("%d",&op);
    while(op!=-1){
        switch(op)
        {
            case 1:scanf("%d",&a);push(a);break;
            case 0:printf("%d ",pop());break; // @@ [When the stack is empty, pop() prints "error " but still returns an undefined value (since no return statement is executed in that path), which is then printed by printf("%d ", ...). This leads to printing "error " followed by garbage or undefined behavior. Additionally, even if "error " is printed inside pop(), the caller still tries to print the return value as an integer, causing incorrect output format.]
            //default:printf("error1");
        }
        scanf("%d",&op);
    }
    return 0;
}
void push(int a)
{
    if(top==maxsize-1)
    printf("error ");
    else
    stack[++top]=a;
}
int pop()
{
    if(top==-1)
    printf("error "); // @@ [This prints "error " but does not return any value, leading to undefined behavior when the calling function tries to use the return value. The function is declared to return int, so all control paths must return an int. Moreover, the error message should be handled entirely in one place to avoid mixing error strings with numeric outputs.]
    else
    return stack[top--];
}