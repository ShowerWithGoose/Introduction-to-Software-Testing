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
            case 0:printf("%d ",pop());break; // @@ The pop function prints "error " directly when the stack is empty but does not return a valid integer. Using printf("%d ", pop()) in this case leads to undefined behavior or printing garbage values (like 6 in the buggy output) because the return value is undefined when the error path is taken. The logic should handle the error message printing inside pop without expecting a return value for formatting, or pop should return a status code and the value separately.
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
    printf("error "); // @@ When the stack is empty, this function prints "error " but then proceeds to execute the return statement implicitly (or falls through). Since the function is declared to return an int, failing to return a value in all control paths results in undefined behavior. In the context of the caller `printf("%d ", pop())`, this undefined return value is printed as a number (e.g., 6), causing the Wrong Answer.
    else
    return stack[top--];
}