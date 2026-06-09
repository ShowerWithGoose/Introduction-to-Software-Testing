#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

int sx[200],sy[200],ex[200],ey[200],n,ans;

void dg(int t)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(ex[t]==sx[i]&&ey[t]==sy[i])
		{
			ans++;
			dg(i);
			break;
		}
	}
	if(i==n)
	{
		return;
	}
}

int main()
{
	int i,max=0,ansx,ansy;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&sx[i],&sy[i],&ex[i],&ey[i]);
	}
	for(i=0;i<n;i++)
	{
		ans=1;
		dg(i);
		if(ans>max)
		{
			max=ans;
			ansx=sx[i];
			ansy=sy[i];
		}
	}
	printf("%d %d %d",max,ansx,ansy);
}



