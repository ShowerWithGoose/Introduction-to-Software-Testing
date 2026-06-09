#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a[101]={0};
    int x,y,i=0;
    while(1)
    {
        scanf("%d",&y);
        if(y==1)
        {
            if(i==-1)
            i++;
            if(i<100)
            {
                scanf("%d ",&a[i]); // @@ The trailing space in the format string causes scanf to consume all trailing whitespace and wait for non-whitespace input, breaking normal input parsing.
                i++;
            }
            else if(i==100)
            {
                printf("error ");
                i++; // @@ Incrementing the stack index when the stack is full corrupts the pointer; it should remain unchanged to correctly reflect the full state.
            }
        }
        else if(y==0)
        {
            if(i==101)
            i--;
            if(i!=0) // @@ This condition fails to handle the empty stack case. When i==0, it should print "error ", but currently it silently ignores the operation.
            {
                i--; // @@ Decrementing the index before checking bounds or printing disrupts the logical flow and makes the subsequent underflow check unreachable.
                if(i<0) // @@ This condition is unreachable because i was guaranteed to be >0 before the decrement, rendering the error check ineffective.
                printf("error ");
                else
                {
                     printf("%d ",a[i]);
                       a[i]=0;
                } 
            }
        }
        else if(y==-1)
        break; 
    }
    return 0;
}