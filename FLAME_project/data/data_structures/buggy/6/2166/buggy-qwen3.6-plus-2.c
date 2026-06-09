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
    Stack *a; // @@ The pointer 'a' is declared but not initialized (not pointing to valid memory), leading to undefined behavior when dereferenced. It should be allocated using malloc or defined as a local struct variable.
    a->top=-1; // @@ Dereferencing uninitialized pointer 'a' causes a segmentation fault or undefined behavior.
    int i=0,j=0;
    while(scanf("%d",&str[j])!=EOF&&str[j]!=-1)
    {   
        if(str[j]==1)
       {a->top++; // @@ Dereferencing uninitialized pointer 'a'. Also, logic error: incrementing top before checking if full or pushing can lead to out-of-bounds access.
        scanf("%d",&b);
        ru(a,b);
        if(full(a)) // @@ Logic error: The check for full stack happens after the push attempt. According to the problem, if push is attempted when full, output "error". The current code pushes first then checks, which is incorrect order and might overwrite data or access invalid index.
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
{    if(a->top<100) // @@ Logic error: The condition allows writing to index 100 if top becomes 100, but array size is 105 so it might not crash immediately, but standard stack capacity is usually 0-99 for size 100. More importantly, this function doesn't prevent overflow correctly in conjunction with the caller.
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
    return a->top==100; // @@ Logic error: If max capacity is 100, indices are 0-99. Top being 99 means full. Top being 100 means overflow has already occurred or it's checking for the next invalid slot. Usually full is top == MaxSize - 1.
}