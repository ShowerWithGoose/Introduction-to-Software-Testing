#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define ll long long
#define ull unsigned long long
struct line
{
	int x1;
	int y1;
	int x2;
	int y2;
}lines[101];
int main()
{
	int n,i,j,k;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&lines[i].x1,&lines[i].y1,&lines[i].x2,&lines[i].y2);
	}
	int x,y,max=0,cnt,x0,y0;
	for(i=0;i<n;i++)
	{
		cnt=1;
		x=lines[i].x2;
		y=lines[i].y2;
		for(j=0;j<n;j++)
		{
			for(k=0;k<n;k++)
			{
					if(lines[k].x1==x&&lines[k].y1==y)
					{
						x=lines[k].x2;
						y=lines[k].y2;
						cnt++;
					}
			}
		
		}
		if(cnt>max)
		{
			max=cnt;
			x0=lines[i].x1;
			y0=lines[i].y1;
		}
	}
	printf("%d %d %d",max,x0,y0);
    return 0;
}
/*10

80 75 125 75

60 40 80 55

80 55 90 20

140 120 195 205

10 111 70 165

22 35 43 43

22 175 80 205

43 43 60 40

90 20 125 60

70 165 140 120*/

