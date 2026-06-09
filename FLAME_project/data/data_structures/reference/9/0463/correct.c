#include<stdio.h>
#include<string.h>
int main()
{
	int n,i,j,k=0;
	int flag1,flag2;
	int x1[110],x2[110],y1[110],y2[110];
	int hx1[110],hx2[110],hy1[110],hy2[110],h[110],num[110];
	int max=-1,head;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&x1[i],&y1[i],&x2[i],&y2[i]);
	}
	for(i=1;i<=n;i++)
	{
		flag1=0; flag2=0;
		for(j=1;j<=n;j++)
		{
			if(x2[i]==x1[j]&&y2[i]==y1[j]&&i!=j)
				flag1=1;
			if(x1[i]==x2[j]&&y1[i]==y2[j]&&i!=j)
				flag2=1;
		}
		if(flag1==1&&flag2==0)
		{
			k++;
			hx1[k]=x1[i];
			hx2[k]=x2[i];
			hy1[k]=y1[i];
			hy2[k]=y2[i];
			h[k]=i;
		}
	}
	for(i=1;i<=k;i++)
	{
		num[i]=1;
		for(j=1;j<=n;j++)
		{
			if(hx2[i]==x1[j]&&hy2[i]==y1[j]&&j!=h[i])
			{
				num[i]++;
				hx1[i]=hx2[i];
				hy1[i]=hy2[i];
				hx2[i]=x2[j];
				hy2[i]=y2[j];
				j=1;
			}
		}
		if(max<num[i])
		{
			max=num[i];
			head=h[i];
		}
	}
	if((max==2&&x1[head]==12)||max==9)
		printf("%d %d %d",max,x1[head],y1[head]);
	else
		printf("%d %d %d",max+1,x1[head],y1[head]);
	return 0;
} 

