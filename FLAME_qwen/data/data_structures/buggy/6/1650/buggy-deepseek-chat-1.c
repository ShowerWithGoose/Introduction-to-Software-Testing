#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
char stack[MAX]; // @@ [Error: stack is declared as char array, but it should store integers. Use int stack[MAX] instead.]
int top=-1;
int main()
{
    int a,b;
    scanf("%d",&a);
    while(a!=-1)
    {
        if(a==1)
        {
            scanf("%d",&b);
            if(top==100) // @@ [Error: The condition should be top == MAX-1 (i.e., top == 99) to check if the stack is full, not top == 100. Also, the stack size is MAX (100), so the maximum index is 99.]
            printf("error ");
            else
            {
                stack[++top]=b; // @@ [Error: stack is char array, cannot store integer b properly. Also, if top is -1, ++top becomes 0, which is correct, but the array type is wrong.]
            }
        }
        else if(a==0)
        {
            if(top==-1)
            printf("error ");
            else
            {
                printf("%d ",stack[top]); // @@ [Error: stack[top] is char, but %d expects int. This will print ASCII value or cause undefined behavior.]
                top--;    
            }
        }
    scanf("%d",&a);    
    }    
    return 0;
}