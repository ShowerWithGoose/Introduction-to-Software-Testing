#include <stdio.h>
int main()
{
	int n,t=1;
	int x1[105],y1[105],x2[105],y2[105];
	int temp1,temp2,temp3,temp4;
	int ans[100],temp;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d %d",&x1[i],&y1[i],&x2[i],&y2[i]);
	}
	memset(ans,0,sizeof(ans));
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(x1[i]>x1[j])
			{
				temp1=x1[i];
				x1[i]=x1[j];
				x1[j]=temp1;
				temp2=y1[i];
				y1[i]=y1[j];
				y1[j]=temp2;
				temp3=x2[i];
				x2[i]=x2[j];
				x2[j]=temp3;
				temp4=y2[i];
				y2[i]=y2[j];
				y2[j]=temp4;
			}
		}
	}
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(x1[i]==x1[j]&&y1[i]>y1[j])
			{
				temp1=x1[i];
				x1[i]=x1[j];
				x1[j]=temp1;
				temp2=y1[i];
				y1[i]=y1[j];
				y1[j]=temp2;
				temp3=x2[i];
				x2[i]=x2[j];
				x2[j]=temp3;
				temp4=y2[i];
				y2[i]=y2[j];
				y2[j]=temp4;
			}
		}
	}
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(x2[t]==x1[j]&&y2[t]==y1[j])
			{
				ans[i]++;
				t=j;
				
			}
		}
		t=i+1;
	}
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(ans[i]<ans[j])
			{
				temp=ans[i];
				ans[i]=ans[j];
				ans[j]=temp;
				temp1=x1[i];
				x1[i]=x1[j];
				x1[j]=temp1;
				temp2=y1[i];
				y1[i]=y1[j];
				y1[j]=temp2;
			}
		}
	}	
	printf("%d %d %d",ans[1]+1,x1[1],y1[1]);
	return 0;
}

