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
                scanf("%d ",&a[i]); // @@ The format string has a trailing space, which may cause input issues; also, the push should increment i after storing, but here it stores at a[i] then increments, which is correct for a 0-indexed stack, but the problem expects a 1-indexed or different logic. More critically, the condition i<100 allows push when i==99, but the stack capacity is 100, so i should be <100 for a 0-indexed stack (indices 0-99). However, the error handling for full stack is incorrect.
                i++;
            }
            else if(i==100)
            {
                printf("error ");
                i++; // @@ This increments i beyond 100, causing the stack to be considered full incorrectly and breaking subsequent operations. When the stack is full (i==100), it should not increment i; it should just print error and continue without changing i.
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