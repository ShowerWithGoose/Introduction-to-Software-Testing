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
            case 0:printf("%d ",pop());break; // @@ [When the stack is empty, pop() prints "error " but still returns an undefined value (due to missing return in error case), which is then printed by printf("%d ", ...), leading to undefined behavior and incorrect output format.]
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
    printf("error "); // @@ [This function is expected to return an int, but in the error case (stack empty), it does not return any value, causing undefined behavior when the caller tries to use the return value. Additionally, the calling code prints the return value regardless, so "error " gets printed followed by garbage from the undefined return value.]
    else
    return stack[top--];
}