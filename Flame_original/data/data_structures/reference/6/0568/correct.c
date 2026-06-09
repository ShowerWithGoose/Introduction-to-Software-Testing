#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 105
int Top=-1;
int isempty()
{
    return Top==-1;
}
int isfull()
{
    return Top==MAX-1;
}
int stack[MAX]={0};
int main ()
{
    int a,b;
    while(scanf("%d",&a)!=-1)
    {
        if(a==0)
        {
            if(isempty())
            {
                printf("error ");
            }
            else
            {
                printf("%d ",stack[Top]);
                Top--;
            }
        }
        if(a==1)
        {   scanf("%d",&b);
            if(isfull())
            {
                printf("error ");
            }
            else
            {
                Top++;
                stack[Top]=b;
            }
        }
    }
return 0;}

