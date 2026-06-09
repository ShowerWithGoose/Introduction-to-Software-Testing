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
            case 0:printf("%d ",pop());break; // @@ The pop function may print "error " and then return an undefined value, causing incorrect output. The function should not print inside pop() when returning a value; instead, handle the error separately.
            //default:printf("error1");
        }
        scanf("%d",&op);
    }
    return 0;
}
void push(int a)
{
    if(top==maxsize-1)
    printf("error "); // @@ Missing newline or space handling; should print "error " and not push, but the function returns void so no issue, but the error message should be consistent with expected output.
    else
    stack[++top]=a;
}
int pop()
{
    if(top==-1)
    printf("error "); // @@ The function is declared to return int, but when the stack is empty, it prints "error " and does not return a value, leading to undefined behavior. It should either return a dummy value or handle the error differently.
    else
    return stack[top--];
}