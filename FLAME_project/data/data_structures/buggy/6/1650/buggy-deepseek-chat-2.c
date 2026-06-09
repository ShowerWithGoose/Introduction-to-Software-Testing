#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100
char stack[MAX]; // @@ [Error: stack is declared as char, but the pushed values are integers (e.g., 567). This causes truncation or incorrect storage when assigning an integer to a char element.]
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
            if(top==100) // @@ [Error: The condition should be top == MAX-1 (i.e., top == 99) to check if the stack is full, since MAX is 100 and indices go from 0 to 99. Using top==100 will never be true, so push operations will not detect overflow correctly.]
            printf("error ");
            else
            {
                stack[++top]=b; // @@ [Error: stack is of type char, but b is an int. Assigning an int to a char truncates the value, causing incorrect output (e.g., 567 becomes 55).]
            }
        }
        else if(a==0)
        {
            if(top==-1)
            printf("error ");
            else
            {
                printf("%d ",stack[top]); // @@ [Error: stack[top] is a char, but %d expects an int. This prints the ASCII value or truncated value, not the original integer.]
                top--;    
            }
        }
    scanf("%d",&a);    
    }    
    return 0;
}