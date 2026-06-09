#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#define ll long long
#define ull unsigned long long
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
	int cnt; 
}posi[205],ans;
//int cnt[105];
 
int main()
{
	int n;
	scanf("%d", &n);
	int j=0,i=0;
	//输入线段并且添加到已有线段中 
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&posi[i].x1,&posi[i].y1,&posi[i].x2,&posi[i].y2);
		posi[i].cnt=1;
		for(j=0;j<i;j++)
		{
			if((posi[i].x1==posi[j].x2&&posi[i].y1==posi[j].y2))//接到后面 
			{
				posi[j].x2=posi[i].x2;
				posi[j].y2=posi[i].y2;
				posi[j].cnt++;
				posi[i].x1=posi[i].x2=posi[i].y1=posi[i].y2=-1;
				break;
			}
			else if(posi[i].x2==posi[j].x1&&posi[i].y2==posi[j].y1)//接到前面 
			{
				posi[j].x1=posi[i].x1;
				posi[j].y1=posi[i].y1;
				posi[j].cnt++;
				posi[i].x1=posi[i].x2=posi[i].y1=posi[i].y2=-1;
				break;
			}
		}
	}
	//遍历已有线段是否可以相连成更长的线段,同时寻找最长线段
	for(i=0;i<n;i++) 
	{
		for(j=0;j<n;j++)
		{
			if(posi[j].x1!=-1&&posi[j].y1!=-1&&posi[j].x2!=-1&&posi[j].y2!=-1)
			{
				if(posi[j].x1==posi[i].x2&&posi[j].y1==posi[i].y2)
							{
								posi[i].cnt+=posi[j].cnt;
								posi[i].x2=posi[j].x2;
								posi[i].y2=posi[j].y2;
							}
							else if(posi[j].x2==posi[i].x1&&posi[j].y2==posi[i].y1)
							{
								posi[i].cnt+=posi[j].cnt;
								posi[i].x1=posi[j].x1;
								posi[i].y1=posi[j].y1;
							}
			}
			
		}
		if(posi[i].cnt>ans.cnt)
		{
			ans=posi[i];
		}
	}
	printf("%d %d %d",ans.cnt,ans.x1,ans.y1);
	return 0;
}

