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
                scanf("%d ",&a[i]); // @@ The trailing space in the format string causes scanf to wait for non-whitespace input, leading to incorrect parsing or program hanging.
                i++;
            }
            else if(i==100)
            {
                printf("error ");
                i++; // @@ Incrementing the stack pointer i on a push error corrupts the stack state; i should remain unchanged when the stack is full.
            }
        }
        else if(y==0)
        {
            if(i==101)
            i--;
            if(i!=0) // @@ This condition fails to handle the empty stack case (i==0); an else clause is needed to print "error " when popping from an empty stack.
            {
                i--;
                if(i<0)
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