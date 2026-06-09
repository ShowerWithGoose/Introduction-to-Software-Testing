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
	int x2,y2;
	int maxx=0,maxy=0;
	for(i=0;i<n;i++)
	{
		cnt=1;
		x2=a[i][2];
		y2=a[i][3];
		for(j=i+1;j<n;j++)
		{
			
			if(a[j][0]==x2&&a[j][1]==y2)
			{
				cnt++;
				x2=a[j][2];
				y2=a[j][3];
			}
			else continue;
		}
		if(cnt>=maxcnt)
		{
			maxcnt=cnt;
			maxx=a[i][0];
			maxy=a[i][1];
		}
	}
	printf("%d %d %d",maxcnt,maxx,maxy);
	return 0;
 } 

