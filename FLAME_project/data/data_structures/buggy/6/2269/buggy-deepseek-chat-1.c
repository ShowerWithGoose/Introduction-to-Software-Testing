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
            case 0:printf("%d ",pop());break; // @@ [Error: pop() returns an int, but when the stack is empty, it prints "error " and then does not return a value, causing undefined behavior. Additionally, the function always prints the return value, so when pop() prints "error " internally, this line will also print an extra integer (garbage or uninitialized value) after "error ". The correct behavior is to only print the popped value when successful, and print "error " without an extra number when the stack is empty.]
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
    printf("error "); // @@ [Error: When the stack is empty, this prints "error " but does not return a value. The function is declared to return int, so this leads to undefined behavior. The caller then prints the undefined return value, causing an extra number to appear in the output.]
    else
    return stack[top--];
}