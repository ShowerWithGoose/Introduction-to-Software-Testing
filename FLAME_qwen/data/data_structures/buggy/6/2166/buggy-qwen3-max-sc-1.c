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
    a->top=-1; // @@ [Using uninitialized pointer 'a' leads to undefined behavior; 'a' is declared as a pointer but never allocated memory]
    int i=0,j=0;
    while(scanf("%d",&str[j])!=EOF&&str[j]!=-1)
    {   
        if(str[j]==1)
       {a->top++; // @@ [Incrementing 'top' before checking if stack is full may cause overflow; also uses uninitialized pointer 'a']
        scanf("%d",&b);
        ru(a,b); // @@ [Passing uninitialized pointer 'a' to function causes undefined behavior]
        if(full(a)) // @@ [Calling 'full' after push instead of before; should check before pushing, and uses uninitialized pointer]
        printf("error ");
       }
       else if(str[j]==0)
       {if(empty(a)) // @@ [Using uninitialized pointer 'a' in 'empty' function]
        printf("error ");
        else
        chu(a); // @@ [Using uninitialized pointer 'a' in 'chu' function]
       }
       i++;
       j++;
    }
    return 0;
}
void ru(Stack *a,int b)
{    if(a->top<100) // @@ [Condition allows writing to index 100 which is out of bounds for array size 105? Actually max index should be 99 for capacity 100; also no handling when condition fails (should print error)]
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
    return a->top==100; // @@ [Stack is full when top == 99 for 100 elements (0..99); returning true at 100 means one extra element was already written]
}