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
                scanf("%d ",&a[i]);
                i++;
            }
            else if(i==100)
            {
                printf("error ");
                i++; // @@ Error: After printing error on full stack, incrementing i beyond capacity will corrupt subsequent push attempts. Should not increment i.
            }
        }
        else if(y==0)
        {
            if(i==101)
            i--;
            if(i!=0) // @@ Error: Condition should check for empty stack (i==0) to print error, but currently skips pop from empty stack, causing missing "error" output.
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