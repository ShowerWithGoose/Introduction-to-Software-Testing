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
    Stack *a; // @@ [Pointer 'a' is declared but not initialized or allocated memory, leading to undefined behavior when dereferenced.]
    a->top=-1; // @@ [Dereferencing uninitialized pointer 'a' causes a segmentation fault.]
    int i=0,j=0;
    while(scanf("%d",&str[j])!=EOF&&str[j]!=-1)
    {   
        if(str[j]==1)
       {a->top++; // @@ [Increments top before checking stack capacity, which corrupts the stack state on overflow.]
        scanf("%d",&b);
        ru(a,b);
        if(full(a)) // @@ [Checks for full stack after attempting to push; should be checked before to prevent overflow and correctly output error.]
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
{    if(a->top<100) // @@ [Inconsistent capacity check; with top starting at -1, valid indices are 0-99, so condition should be < 99 or rely on full().]
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
    return a->top==100; // @@ [Off-by-one error: stack capacity is 100, so with top initialized to -1, full condition should be top == 99.]
}