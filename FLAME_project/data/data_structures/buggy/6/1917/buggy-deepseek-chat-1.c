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
                scanf("%d ",&a[i]); // @@ The format string "%d " has a trailing space, which may cause input issues; also, the push should increment i after storing, but here it stores at a[i] then increments, which is correct for a 0-based index, but the stack logic is flawed overall.
                i++;
            }
            else if(i==100)
            {
                printf("error ");
                i++; // @@ This increments i to 101 when stack is full, which is incorrect; it should not change i when error occurs.
            }
        }
        else if(y==0)
        {
            if(i==101)
            i--;
            if(i!=0)
            {
                i--;
                if(i<0) // @@ This condition is never true because i is decremented before the check; the pop should check for empty stack before decrementing.
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