#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 100
int z[MAXSIZE];
int top=-1;
int ru(int a)
{
    if(top<=MAXSIZE-1)
    {
        top++;
        z[top]=a;
    }
    else
    printf("error ");
}
int chu()
{
    if(top>-1)
    {
        printf("%d ",z[top]);
        top--;
    }

    else
    printf("error ");
}
int main()
{
    int a,b,flag;
    while(scanf("%d",&flag)!=EOF)
    {
        if(flag==1)
        {
            scanf("%d",&a);
             ru(a);
        }

        else if(flag==0)
            chu();
    }
    return 0;



}

