#include<stdio.h>
#include<string.h>
int a[105][4];
int s[4];
int main()
{
	int n;
	scanf("%d",&n);
	int i,j;
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
	}
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(a[i][0]>a[j][0])
			{
				s[0]=a[i][0];
				a[i][0]=a[j][0];
				a[j][0]=s[0];
				s[1]=a[i][1];
				a[i][1]=a[j][1];
				a[j][1]=s[1];
				s[2]=a[i][2];
				a[i][2]=a[j][2];
				a[j][2]=s[2];
				s[3]=a[i][3];
				a[i][3]=a[j][3];
				a[j][3]=s[3];
			}
		}
	}
	int max=0,x=0,y=0;
	for(i=0;i<n;i++)
	{
		int k=i,t=0;
		for(j=i+1;j<n;j++)
		{
			if(a[k][2]==a[j][0]&&a[k][3]==a[j][1])
			{
				t++;
				k=j;
			}
		}
		t++;
		if(t>max)
		{
			max=t;
			x=a[i][0];
			y=a[i][1];
		}
	}
	printf("%d %d %d",max,x,y);
	return 0;
 } 



