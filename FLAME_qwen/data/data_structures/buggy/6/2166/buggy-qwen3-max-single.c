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
       {a->top++; // @@ [Incrementing 'top' before checking if stack is full and before actually pushing; also uses uninitialized pointer]
        scanf("%d",&b);
        ru(a,b);
        if(full(a)) // @@ [Checking 'full' after push; should check before push to prevent overflow]
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
{    if(a->top<100) // @@ [Condition allows writing to index 100 when top==100, but array size is 105 so logic is inconsistent with full() which checks top==100; also, no action if condition fails (should handle error)]
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
    return a->top==100; // @@ [Stack is full when top == 99 (0-based index for 100 elements), so this should be top == 99 or >=100]
}