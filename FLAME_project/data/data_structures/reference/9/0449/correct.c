#include <stdio.h>
#include <string.h>

int a[105][5];

int main()
{
	int n;
	scanf("%d",&n);
	int i=0,j=0;
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&a[i][0],&a[i][1],&a[i][2],&a[i][3]);
	}
	int tmp=0;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(a[j][0]>a[j+1][0])
			{
				tmp=a[j+1][0];
				a[j+1][0]=a[j][0];
				a[j][0]=tmp;
				tmp=a[j+1][1];
				a[j+1][1]=a[j][1];
				a[j][1]=tmp;
				tmp=a[j+1][2];
				a[j+1][2]=a[j][2];
				a[j][2]=tmp;
				tmp=a[j+1][3];
				a[j+1][3]=a[j][3];
				a[j][3]=tmp;
			}
		}
	}
	int cnt=1,maxcnt=1;
	int midx,midy;
	int x0=0,y0=0;
	for(i=0;i<n;i++)
	{
		cnt=1;
		midx=a[i][2];
		midy=a[i][3];
		for(j=i+1;j<n;j++)
		{
			
			if(a[j][0]==midx&&a[j][1]==midy)
			{
				cnt++;
				midx=a[j][2];
				midy=a[j][3];
			}
			else continue;
		}
		if(cnt>=maxcnt)
		{
			maxcnt=cnt;
			x0=a[i][0];
			y0=a[i][1];
		}
	}
	printf("%d %d %d",maxcnt,x0,y0);
	return 0;
 } 

