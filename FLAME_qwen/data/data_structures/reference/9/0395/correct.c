#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
};
int cmp(const void *a,const void *b);

int main()
{
	int n;
	scanf("%d",&n);
	struct line a[102];
	struct line last;
	int i;
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	}
	qsort(a,n,sizeof(a[0]),cmp);       //按起始端点x值从小到大排序 
	int b[102]={0};
	
	int j;
	for(j=0;j<n-1;j++)
	{
		int k;
		last = a[j]; 
		for(k=1;k<n;k++)
		{
			if(last.x2 == a[k].x1 && last.y2 == a[k].y1)  
			{
				last.x2 = a[k].x2;
				last.y2 = a[k].y2;
				b[j]++;
			}
		/*	else if(last.x2 == a[k].x2 && last.y2 == a[k].y2)
			{
				last.x2 = a[k].x1;
				last.y2 = a[k].y1;
				b[j]++;
			}   */
		}
		
	}
	int max=b[0];
	int flag = 0;
	int p;
	for(p=1;p<n;p++)
	{
		if(max<b[p])
			{
			max = b[p];
			flag = p;
			}
	}
	printf("%d %d %d",max+1,a[flag].x1,a[flag].y1);
	
	return 0;
}

int cmp(const void *a,const void *b){
	struct line *aa = (struct line *)a;
	struct line *bb = (struct line *)b;
	if(aa->x1 > bb->x1)
		return 1;
	return -1;
	
}

