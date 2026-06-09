#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
	int length;
};
struct line line1[105];
int len=1;
void search(struct line line1[],struct line len1,int n);
int main()
{
	int n,i,max=0,flag=-1;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
 		scanf("%d %d %d %d",&line1[i].x1,&line1[i].y1,&line1[i].x2,&line1[i].y2);
 	for(i=1;i<=n;i++)
	{
		len=1;
		search(line1,line1[i],n);
		line1[i].length=len;	
	}
	for(i=1;i<=n;i++)
	if(line1[i].length>max)
	{
		max=line1[i].length;
		flag=i;
	}
	printf("%d %d %d",max,line1[flag].x1,line1[flag].y1);
	return 0;
}
void search(struct line line1[],struct line len1,int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		if (line1[i].x1==len1.x2&&line1[i].y1==len1.y2)
		{
			len++;
			search(line1,line1[i],n);
		}
	}	 
}

