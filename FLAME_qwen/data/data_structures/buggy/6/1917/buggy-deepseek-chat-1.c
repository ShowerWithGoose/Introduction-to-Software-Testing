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
                scanf("%d ",&a[i]); // @@ The format string has a trailing space, which may cause input issues; should be "%d" without space.
                i++;
            }
            else if(i==100)
            {
                printf("error ");
                i++; // @@ After printing error for full stack, incrementing i makes it 101, which breaks the stack size logic and causes subsequent operations to misbehave.
            }
        }
        else if(y==0)
        {
            if(i==101)
            i--; // @@ This attempts to fix an out-of-bounds index but does not handle the error condition properly; the stack should not allow pop when empty.
            if(i!=0)
            {
                i--;
                if(i<0) // @@ This condition is never true because i is decremented only when i!=0, so i will be >=0; the error check for empty stack is misplaced.
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