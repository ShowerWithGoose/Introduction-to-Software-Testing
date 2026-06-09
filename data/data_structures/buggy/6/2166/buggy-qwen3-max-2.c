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
    a->top=-1; // @@ [Using uninitialized pointer 'a'; it points to invalid memory, leading to undefined behavior]
    int i=0,j=0;
    while(scanf("%d",&str[j])!=EOF&&str[j]!=-1)
    {   
        if(str[j]==1)
       {a->top++; // @@ [Incrementing top before checking if stack is full; also uses uninitialized pointer]
        scanf("%d",&b);
        ru(a,b);
        if(full(a)) // @@ [Checking full condition after push; should check before pushing to avoid overflow]
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
{    if(a->top<100) // @@ [Condition allows top to be 100, but array index max is 104; however logic error: should check before incrementing top in main]
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
    return a->top==100; // @@ [Stack size is 105, but max capacity should be 100 as per problem; also, top==100 means 101 elements (0..100), which exceeds capacity]
}