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
            case 0:printf("%d ",pop());break; // @@ [This line always prints an integer from pop(), but pop() may print "error " and not return a valid integer, resulting in undefined behavior and incorrect output format. Instead, pop() should handle error printing internally without returning a value that is printed here.]
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
    printf("error "); // @@ [When the stack is empty, this prints "error " but does not return a value, causing the caller to print an undefined integer. The function should either return a dummy value or the caller should not print after an error.]
    else
    return stack[top--];
}