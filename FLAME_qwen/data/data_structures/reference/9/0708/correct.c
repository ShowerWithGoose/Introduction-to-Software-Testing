#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int x[1005][1005][3];
int start[1005][1005];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int x1,x2,y1,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		x[x1][y1][2]=x2;
		x[x1][y1][3]=y2;
		x[x2][y2][0]=x1;
		x[x2][y2][1]=y1;
	}
	int num=0;
	for(int i=0;i<=1005;i++)
	{
		for(int j=0;j<=1005;j++)
		{
			if(x[i][j][0]==0&&x[i][j][2]!=0)
			{
				start[num][1]=i;
				start[num][2]=j;
				num++;
			}
		}
	}
	for(int i=0;i<num;i++)
	{
		int x1=start[i][1],y1=start[i][2];
		while(x[x1][y1][3]!=0)
		{
			int lasx1=x1,lasy1=y1;
			x1=x[lasx1][lasy1][2];
			y1=x[lasx1][lasy1][3];
			start[i][3]++;
		}
	}
	int max=0,x0,y0;
	for(int i=0;i<num;i++)
	{
		if(start[i][3]>max)
		{
			max=start[i][3];
			x0=start[i][1];
			y0=start[i][2];
		}
	}
	printf("%d %d %d",max,x0,y0);
	return 0;
}



