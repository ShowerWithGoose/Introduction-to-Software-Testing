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
            case 0:printf("%d ",pop());break; // @@ [Error: When pop() returns -1 due to empty stack, it prints -1 instead of "error". The pop() function prints "error " but then returns an undefined value (stack[top--] when top is -1), causing the printf to output an extra number. The correct behavior is to print "error " and not print any popped value.]
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
    printf("error "); // @@ [Error: This prints "error " but then the function does not return a proper value. Since the return type is int, it will return garbage (or whatever is in the register), and the caller prints that garbage value. The correct implementation should not return a value when the stack is empty, or should handle the error differently.]
    else
    return stack[top--];
}