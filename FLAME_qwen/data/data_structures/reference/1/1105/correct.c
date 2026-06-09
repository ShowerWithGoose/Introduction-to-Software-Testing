#include <stdio.h>

int a[15],b[15],n;
void f(int x)
{
    int i;
    if(x==n)
    {
        for(i=0;i<n-1;i++)
        printf("%d ",b[i]);
        printf("%d\n",b[i]);
    }
    else
    {
        for(i=0;i<n;i++)
        {
            if(!a[i])
            {
                a[i]=1;
                b[x]=i+1;
                f(x+1);
                a[i]=0;
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



