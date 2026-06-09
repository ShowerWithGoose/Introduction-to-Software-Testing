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
    a->top=-1; // @@ [Error: 'a' is an uninitialized pointer; dereferencing it causes undefined behavior. Must allocate memory for the stack first.]
    int i=0,j=0;
    while(scanf("%d",&str[j])!=EOF&&str[j]!=-1)
    {   
        if(str[j]==1)
       {a->top++; // @@ [Error: 'a' is still uninitialized; also, incrementing top before calling ru() causes the push to use an incorrect index. The push function should handle the index increment.]
        scanf("%d",&b);
        ru(a,b);
        if(full(a))
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
     a->data[a->top]=b; // @@ [Error: This does not check if the stack is full before pushing; it only checks after incrementing top in main. Also, the condition should be a->top < 99 for a 0-indexed array of size 100.]
}
void chu(Stack *a)
{ 
    printf("%d ",a->data[a->top]);
    a->data[a->top]=-1; // @@ [Error: Setting the popped element to -1 is unnecessary and may cause confusion if -1 is a valid data value.]
    a->top--;
}
int empty(Stack *a)
{
    return a->top==-1;
}
int full(Stack *a)
{
    return a->top==100; // @@ [Error: Since top is 0-indexed, the maximum valid index is 99, so full should be a->top == 99.]
}