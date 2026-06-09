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
            case 0:printf("%d ",pop());break; // @@ [This line always prints the return value of pop, but pop may not return a valid value when the stack is empty (undefined behavior). The correct behavior is to not print any number if pop fails.]
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
    if(top==-1) // @@ [When the stack is empty, the function prints "error " but does not return a value, causing undefined behavior in the calling code. This leads to an extra number being printed after "error".]
    printf("error ");
    else
    return stack[top--];
}