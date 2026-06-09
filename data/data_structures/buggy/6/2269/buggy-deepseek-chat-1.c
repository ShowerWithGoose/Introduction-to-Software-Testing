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
            case 0:printf("%d ",pop());break; // @@ The pop() function may print "error " and then return an undefined value, causing incorrect output. The function should not print inside pop() when returning a value; instead, handle the error case separately.
            //default:printf("error1");
        }
        scanf("%d",&op);
    }
    return 0;
}
void push(int a)
{
    if(top==maxsize-1)
    printf("error "); // @@ Missing return statement after printing error; the function should not proceed to push when stack is full.
    else
    stack[++top]=a;
}
int pop()
{
    if(top==-1)
    printf("error "); // @@ Missing return statement after printing error; the function should return a sentinel value or handle the error without returning an undefined value.
    else
    return stack[top--];
}