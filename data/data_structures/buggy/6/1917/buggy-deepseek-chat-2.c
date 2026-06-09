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
                scanf("%d ",&a[i]); // @@ The format string "%d " expects an extra space after the integer, which may cause input mismatch or skip next input. Should be "%d".
                i++;
            }
            else if(i==100)
            {
                printf("error ");
                i++; // @@ After printing "error " for a full stack, incrementing i makes i=101, which breaks the stack size logic and causes subsequent operations to misbehave.
            }
        }
        else if(y==0)
        {
            if(i==101)
            i--;
            if(i!=0)
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