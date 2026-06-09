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
            case 0:printf("%d ",pop());break; // @@ [When the stack is empty, pop() prints "error " but still returns an undefined value (since no return statement is executed in the error case), which is then printed by printf("%d ", ...). This leads to printing both "error " and a garbage number.]
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
    printf("error "); // @@ [This prints "error " but does not return a value. The calling code expects an int to be returned for printf("%d ", pop()). When top == -1, this function reaches the end without returning a value, causing undefined behavior. Additionally, even if it returned a dummy value, the caller would still print "%d " after "error ", which is incorrect output format.]
    else
    return stack[top--];
}