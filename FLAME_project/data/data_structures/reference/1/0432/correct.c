#include <stdio.h>
int n;
int vis[10];
void qpl(int a,int b)
{
	int i;
	if(a>n)
	{
		int c[10];
		for(i=0;i<n;i++)
            c[i]=0;
		for(i=0;i<n;i++,b/=10)
		{
		    c[i]=b%10;
		}
		i--;
		for(;i>=0;i--)
        {
            if(c[i]!=0)
            printf("%d ",c[i]);
        }
        printf("\n");
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			vis[i]=1;
			qpl(a+1,b*10+i);
			vis[i]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	qpl(1,0);
}



