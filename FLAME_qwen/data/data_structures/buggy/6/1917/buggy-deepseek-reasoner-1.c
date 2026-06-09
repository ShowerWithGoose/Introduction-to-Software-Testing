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
                scanf("%d ",&a[i]); // @@ The trailing space in scanf format causes the program to block waiting for non-whitespace after reading the integer, leading to incorrect input synchronization.
                i++;
            }
            else if(i==100)
            {
                printf("error ");
                i++; // @@ After a push on a full stack, i is incremented to 101, corrupting the stack pointer and causing subsequent push operations to be ignored without error.
            }
        }
        else if(y==0)
        {
            if(i==101) // @@ This condition attempts to handle the corrupted stack pointer but is logically incorrect; it allows popping from a stack that reported full, and the decrement here may incorrectly simulate a pop.
            i--;
            if(i!=0) // @@ This condition does not print "error" when the stack is empty (i==0), violating the requirement to output "error " on an empty pop.
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