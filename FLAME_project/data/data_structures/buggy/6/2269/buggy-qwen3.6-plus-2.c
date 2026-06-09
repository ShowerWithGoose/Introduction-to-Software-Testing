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
            case 0:printf("%d ",pop());break; // @@ The pop function prints "error " directly when the stack is empty but returns an undefined value (likely garbage or 0 from previous state) which is then printed by printf. This causes extra output like '6' in the buggy output. The pop function should handle the printing entirely or return a status code, not mix returning a value for printing with side-effect printing of errors.
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
    printf("error "); // @@ When the stack is empty, this prints "error " but does not return a valid integer. The caller in main still executes printf("%d ", ...), printing whatever garbage value is returned. This leads to incorrect output format and content.
    else
    return stack[top--];
}