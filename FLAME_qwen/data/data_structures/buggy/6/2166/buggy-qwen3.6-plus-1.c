#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
int str[105];
typedef struct Stack{
    int data[105];
    int top;
} Stack;
void ru(Stack *a,int b);
void chu(Stack *a);
int empty(Stack *a);
int full(Stack *a);
int main() {
    int b;
    Stack *a;
    a->top=-1; // @@ Uninitialized pointer 'a' is dereferenced, causing undefined behavior or crash.
    int i=0,j=0;
    while(scanf("%d",&str[j])!=EOF&&str[j]!=-1)
    {
        if(str[j]==1)
       {a->top++; // @@ Top is incremented before checking if the stack is full, which can cause out-of-bounds access.
        scanf("%d",&b);
        ru(a,b);
        if(full(a)) // @@ Checks for full stack after the push operation, so the error is reported too late and the invalid push is not prevented.
        printf("error ");
       }
       else if(str[j]==0)
       {if(empty(a))
        printf("error ");
        else
        chu(a);
       }
       i++;
       j++;
    }
    return 0;
}
void ru(Stack *a,int b)
{    if(a->top<100)
     a->data[a->top]=b;
}
void chu(Stack *a)
{ 
    printf("%d ",a->data[a->top]);
    a->data[a->top]=-1;
    a->top--;
}
int empty(Stack *a)
{
    return a->top==-1;
}
int full(Stack *a)
{
    return a->top==100; // @@ The maximum capacity is 100, so valid indices are 0-99. Since 'top' points to the top element, the stack is full when top == 99.
}