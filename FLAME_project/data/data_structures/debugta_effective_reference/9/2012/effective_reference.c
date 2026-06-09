#include <stdio.h>
int main()
{
	int n,t=1;
	int left1[105],y1[105],right1[105],y2[105];
	int temp1,temp2,temp3,temp4;
	int cnt[100],temp;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d %d %d %d",&left1[i],&y1[i],&right1[i],&y2[i]);
	}
	memset(cnt,0,sizeof(cnt));
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(left1[i]>left1[j])
			{
				temp1=left1[i];
				left1[i]=left1[j];
				left1[j]=temp1;
				temp2=y1[i];
				y1[i]=y1[j];
				y1[j]=temp2;
				temp3=right1[i];
				right1[i]=right1[j];
				right1[j]=temp3;
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
			if(left1[i]==left1[j]&&y1[i]>y1[j])
			{
				temp1=left1[i];
				left1[i]=left1[j];
				left1[j]=temp1;
				temp2=y1[i];
				y1[i]=y1[j];
				y1[j]=temp2;
				temp3=right1[i];
				right1[i]=right1[j];
				right1[j]=temp3;
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
			if(right1[t]==left1[j]&&y2[t]==y1[j])
			{
				cnt[i]++;
				t=j;
				
			}
		}
		t=i+1;
	}
	for(int i=1;i<=n-1;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(cnt[i]<cnt[j])
			{
				temp=cnt[i];
				cnt[i]=cnt[j];
				cnt[j]=temp;
				temp1=left1[i];
				left1[i]=left1[j];
				left1[j]=temp1;
				temp2=y1[i];
				y1[i]=y1[j];
				y1[j]=temp2;
			}
		}
	}	
	printf("%d %d %d",cnt[1]+1,left1[1],y1[1]);
	return 0;
}

