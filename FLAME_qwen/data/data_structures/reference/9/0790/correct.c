#include <stdio.h>
int a[101][4]={0},b[101]={0};
int main()
{
	int n,i,j,k,m,s,temp,t=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][2]==a[j][0]&&a[i][3]==a[j][1])
			{
				b[i]++;temp=1;m=j;
			}
			while(temp==1)
			{
				temp=0;
				for(k=0;k<n;k++)
				{
					if(a[m][2]==a[k][0]&&a[m][3]==a[k][1])
					{
						b[i]++;m=k;temp=1;break;
					}
				}
			}
		}
	}
	for(i=0;i<n;i++)
	{
		if(b[i]>t)
		{
			t=b[i];s=i;
		}
	}
	printf("%d %d %d",t+1,a[s][0],a[s][1]);
	return 0;
}

