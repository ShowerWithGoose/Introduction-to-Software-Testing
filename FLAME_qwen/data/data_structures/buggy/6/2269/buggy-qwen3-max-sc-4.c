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
            case 0:printf("%d ",pop());break; // @@ [When the stack is empty, pop() prints "error " but still returns an undefined value (since no return statement is executed in the error case), which is then printed by printf("%d ", ...). This leads to printing "error <garbage>" or undefined behavior instead of just "error ".]
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
    printf("error "); // @@ [This prints "error " but does not return a value. The function is declared to return int, so control reaches end of non-void function without returning a value when top == -1, leading to undefined behavior. Additionally, the calling code always prints the return value as an integer, so even if "error " is printed here, the caller will also print an undefined/garbage integer after it.]
    else
    return stack[top--];
}