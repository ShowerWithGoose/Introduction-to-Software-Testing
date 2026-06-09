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
    a->top=-1; // @@ [Using uninitialized pointer 'a'; it does not point to a valid Stack object, leading to undefined behavior]
    int i=0,j=0;
    while(scanf("%d",&str[j])!=EOF&&str[j]!=-1)
    {   
        if(str[j]==1)
       {a->top++; // @@ [Incrementing top before checking if stack is full; also uses uninitialized pointer 'a']
        scanf("%d",&b);
        ru(a,b); // @@ [Passing uninitialized pointer 'a' to function]
        if(full(a)) // @@ [Calling full() after push; should check before push. Also uses uninitialized pointer 'a']
        printf("error ");
       }
       else if(str[j]==0)
       {if(empty(a)) // @@ [Using uninitialized pointer 'a']
        printf("error ");
        else
        chu(a); // @@ [Passing uninitialized pointer 'a' to function]
       }
       i++;
       j++;
    }
    return 0;
}
void ru(Stack *a,int b)
{    if(a->top<100) // @@ [Condition allows top=100, but array index 100 is out of bounds for data[105] when top starts at -1; also logic error: should check before incrementing top in main]
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
    return a->top==100; // @@ [Stack is full when top == 99 (since size is 100 and top starts at -1), so this condition is off-by-one]
}