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
     a->data[a->top]=b; // @@ [Error: The top index was already incremented in main, so this stores at the correct position, but the full check in main is after the push, which is logically incorrect. Also, the condition should be a->top < 100 to allow index 99, but the full function checks a->top==100, which is inconsistent.]
}
void chu(Stack *a)
{ 
    printf("%d ",a->data[a->top]);
    a->data[a->top]=-1; // @@ [Error: Setting the popped element to -1 is unnecessary and may cause confusion; it does not affect correctness but is not part of the required logic.]
    a->top--;
}
int empty(Stack *a)
{
    return a->top==-1;
}
int full(Stack *a)
{
    return a->top==100; // @@ [Error: The condition should be a->top == Maxsize-1 (i.e., 99) to indicate full, since top is the index of the last element. With top==100, the stack can hold 101 elements, exceeding the capacity of 100.]
}