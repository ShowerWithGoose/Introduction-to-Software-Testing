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
    a->top=-1; // @@ [Using uninitialized pointer 'a' leads to undefined behavior; 'a' should point to a valid Stack instance, e.g., by declaring 'Stack a;' and using '&a']
    int i=0,j=0;
    while(scanf("%d",&str[j])!=EOF&&str[j]!=-1)
    {   
        if(str[j]==1)
       {a->top++; // @@ [Incrementing top before checking if stack is full may cause overflow; also, 'a' is still uninitialized]
        scanf("%d",&b);
        ru(a,b);
        if(full(a)) // @@ [The check for full stack happens after push, but error should be printed if push fails due to full stack; logic is inverted]
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
{    if(a->top<100) // @@ [This condition allows top to be 100, which is beyond the valid index range (0-99) for a 100-element stack; should be a->top < 100 before assignment, but top was already incremented in main]
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
    return a->top==100; // @@ [Stack is full when top == 99 (for 100 elements, indices 0-99); returning true at top==100 is too late—it means 101 elements were pushed]
}