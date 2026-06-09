#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>

char aa[10000],bb[10000];
int xa[1000],xb[1000],ya[1000],yb[1000],ansx[1000],ansy[1000],outx[1000],outy[1000];

int main()
{
	gets(aa);
	gets(bb);
	int i=0,ta=0,tb=0,j;
	while(aa[i]!='\0')
	{
		if(aa[i]!=' ')
		{
			xa[ta]=xa[ta]*10+aa[i]-'0';
		}
		else
		{
			ta++;
		}
		i++;
	}
	i=0;
	while(bb[i]!='\0')
	{
		if(bb[i]!=' ')
		{
			xb[tb]=xb[tb]*10+bb[i]-'0';
		}
		else
		{
			tb++;
		}
		i++;
	}
	int t=0,ans;
	for(i=0;i<ta;i=i+2)
	{
		for(j=0;j<tb;j=j+2)
		{
			ansx[t]=xa[i]*xb[j];
			ansy[t]=xa[i+1]+xb[j+1];
			t++;
		}
	}
	for(i=0;i<t-1;i++)
	{
		for(j=0;j<t-i-1;j++)
		{
			if(ansy[j]<ansy[j+1])
			{
				ans=ansx[j];
				ansx[j]=ansx[j+1];
				ansx[j+1]=ans;
				ans=ansy[j];
				ansy[j]=ansy[j+1];
				ansy[j+1]=ans;
			}
		}
	}
	j=0;
	outx[0]=ansx[0];
	outy[0]=ansy[0];
	for(i=1;i<t;i++)
	{
		if(outy[j]==ansy[i])
		{
			outx[j]+=ansx[i];
		}
		else
		{
			j++;
			outy[j]=ansy[i];
			outx[j]=ansx[i];
		}
	}
	for(i=0;i<=j;i++)
	{
		printf("%d %d ",outx[i],outy[i]);
	}
}



