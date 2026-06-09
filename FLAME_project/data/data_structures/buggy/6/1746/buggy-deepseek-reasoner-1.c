#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int stack[110];
int main()
{
    int top=0;
    int op,num;
    while(1)
    {
        scanf("%d",&op);
        if(op==1)
        {
            scanf("%d",&num);
            if(top==99) // @@ Incorrect full check: stack has 100 slots (0..99), when top==99 there is still one free slot. Should be top==100.
            printf("error ");
            else
            {
                stack[top]=num;
                top++;
            }
        }
        else if(op==0)
        {
            if(top==0)
            printf("error ");
            else
            {
                printf("%d ",stack[top]); // @@ Prints the next empty slot instead of the top element. Should use stack[top-1] or decrement first.
                top--; 
            }
        }
        else if(op==-1)
        break;
    }
    return 0;
}