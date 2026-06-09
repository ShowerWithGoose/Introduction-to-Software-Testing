#include <stdio.h>
#include <stdlib.h>
int rop[100];
int top=-1,k=0;

void pu(int s[],int n)
{
    if(k==1)
    {
        s[++top]=n;k=0;
    }
    if(n==1)
    {
        if(top==99)
            printf("error ");
        else
            k=1;
    }
    if(n==0)
    {
        if(top==-1)
            printf("error ");
        else
        {
            printf("%d ",s[top]);
            return s[top--]; // @@ [Error: 'return' statement with expression in a void function; should be just 's[top--];' without return]
        }
    }
}

int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        pu(rop,n);
        if(n==-1)
            break;
    }
    return 0;
}