#include <stdio.h>
struct line
{
	int x1;
	int x2;
	int y1;
	int y2;
}lines[100];
void f1(struct line lines[],int a[],int m,int flag, int k,int n)
{
	if(m==n-1)
	{
		return;
	}
	int i;
	int j;
	if(flag==0)
	for(i=m;i<=n-2;i++)
	{
		for(j=i+1;j<=n-1;j++)
		{
			if(lines[i].x2==lines[j].x1)
			{
				if(lines[i].y2==lines[j].y1)
				{
					k=i;
					a[k]++;
					f1(lines,a,j,1,k,n);
				}
			}
		}
	}
	else
	{
		i=m;
		for(j=i+1;j<=n-1;j++)
		{
			if(lines[i].x2==lines[j].x1)
			{
				if(lines[i].y2==lines[j].y1)
				{
					a[k]++;
					f1(lines,a,j,1,k,n);
					break;
				}
			}
		}
	}
	return;
}
int main()
{
	int n;
	scanf("%d",&n);
	int i;
	int j;
	for(i=0;i<=n-1;i++)
	{
		scanf("%d",&lines[i].x1);
		scanf("%d",&lines[i].y1);
		scanf("%d",&lines[i].x2);
		scanf("%d",&lines[i].y2);
	}
	struct line c;
	int a[100];
    for(i=0;i<=n-1;i++)
	{
		a[i]=1;
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<=n-2;j++)
		{
			if(lines[j].x1>lines[j+1].x1)
			{
				c=lines[j];
				lines[j]=lines[j+1];
				lines[j+1]=c;
			}
		}
		
	}
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<=n-2;j++)
		{
			if(lines[j].x2>lines[j+1].x2)
			{
				c=lines[j];
				lines[j]=lines[j+1];
				lines[j+1]=c;
			}
		}
		
	}
    f1(lines,a,0,0,0,n);
    int max=a[0];
    int k=0;
    for(i=1;i<=n-1;i++)
    {
    	if(max<a[i])
    	{
    	max=a[i];	
    	k=i;
		}
	}
	printf("%d ",max);
	printf("%d %d",lines[k].x1,lines[k].y1);
	return 0;
}

