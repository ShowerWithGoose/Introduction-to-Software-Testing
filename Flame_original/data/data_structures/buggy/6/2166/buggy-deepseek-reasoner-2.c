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
    a->top=-1; // @@ [Uninitialized pointer 'a' used; must allocate memory for Stack or declare a Stack variable.]
    int i=0,j=0;
    while(scanf("%d",&str[j])!=EOF&&str[j]!=-1)
    {   
        if(str[j]==1)
       {a->top++; // @@ [Push operation increments top before checking if stack is full; should check full first.]
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
    return a->top==100;
}