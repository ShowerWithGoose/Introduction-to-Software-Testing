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
    a->top=-1; // @@ Pointer 'a' was not allocated memory (missing malloc) – dereferencing uninitialized pointer causes undefined behavior/crash.
    int i=0,j=0;
    while(scanf("%d",&str[j])!=EOF&&str[j]!=-1)
    {   
        if(str[j]==1)
       {a->top++; // @@ Incrementing top before checking if stack is full; can lead to index out of bounds. Also full condition (top==100) is incorrect.
        scanf("%d",&b); // @@ 'b' is read from stdin, but input has already been fully read into 'str' array. This will cause desynchronization or waiting for extra input.
        ru(a,b);
        if(full(a)) // @@ Full check should be performed before push, not after; also full condition is wrong (should be top==99).
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
{    if(a->top<100) // @@ Condition should be a->top < 100 (since indices 0-99), but top has already been incremented, so if top==99, it should allow; but when top==100, this fails and no assignment, yet top remains 100 (invalid). Proper check should be before increment.
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
    return a->top==100; // @@ Incorrect full condition: maximum index is 99, so top==99 indicates full. top==100 is out-of-range.
}