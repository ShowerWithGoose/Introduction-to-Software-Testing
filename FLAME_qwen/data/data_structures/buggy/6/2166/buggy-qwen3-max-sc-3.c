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
       {a->top++; // @@ [Incrementing top before checking if stack is full; also uses uninitialized pointer]
        scanf("%d",&b);
        ru(a,b); // @@ [Passing uninitialized pointer to function; leads to undefined behavior]
        if(full(a)) // @@ [full() checks if top == 100, but push already incremented top and wrote beyond valid index if stack was full]
        printf("error ");
       }
       else if(str[j]==0)
       {if(empty(a)) // @@ [Using uninitialized pointer in empty(); undefined behavior]
        printf("error ");
        else
        chu(a); // @@ [Using uninitialized pointer in chu(); undefined behavior]
       }
       i++;
       j++;
    }
    return 0;
}
void ru(Stack *a,int b)
{    if(a->top<100) // @@ [Condition allows writing at index 100 when top==100, which is out of bounds for array of size 105 (valid indices 0-104)]
     a->data[a->top]=b;
}
void chu(Stack *a)
{ 
    printf("%d ",a->data[a->top]); // @@ [If stack is empty, this accesses invalid memory; but empty() check is done in main, however pointer is still uninitialized]
    a->data[a->top]=-1;
    a->top--;
}
int empty(Stack *a)
{
    return a->top==-1;
}
int full(Stack *a)
{
    return a->top==100; // @@ [Stack is full when top == 99 (since size is 105 but max capacity should be 100); returning true at top==100 means one extra element was allowed]
}