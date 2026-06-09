#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
int n;
int ch[15];
int s[15]={0};
void f(int num)
{
    int i;
    if(num>=n)
    {
        for(i=0;i<n;i++)
        {
            if(i==n-1)
                printf("%d\n",ch[i]);
            else if(i!=n)
                printf("%d ",ch[i]);
        }
        return;
    }
    else
    {
        for(i=1;i<=n;i++)
        {
            if(s[i]==0)
            {
                s[i]=1;
                ch[num]=i;
                f(num+1);
                s[i]=0;
            }

        }
    }
}
int main()
{
    scanf("%d",&n);
    f(0);
    return 0;
}

