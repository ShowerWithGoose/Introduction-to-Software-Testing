#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct line{
	int x1;
	int y1;
	int x2;
	int y2;
	int cot;
}line[110];
int main()
{
	int n,i,j,k,l,flag,temp;
	scanf("%d",&n) ;
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2) ;
		line[i].cot=1;
	}
	for(i=0;i<n;i++)
	{
		flag=0;
		for(j=i+1;j<n;j++)
		{
			if(line[j].x1<line[i].x1)
			{
				temp=line[j].x1 ;
				line[j].x1=line[i].x1;
				line[i].x1=temp;
				temp=line[j].x2 ;
				line[j].x2=line[i].x2;
				line[i].x2=temp;
				temp=line[j].y1 ;
				line[j].y1=line[i].y1;
				line[i].y1=temp;
				temp=line[j].y2;
				line[j].y2=line[i].y2;
				line[i].y2=temp;
				flag=1;
			}
		}
		if(flag==0)
		break;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(line[i].x2==line[j].x1 && line[i].y2 == line[j].y1)
			{
				
				line[i].x2=line[j].x2;
				line[i].y2=line[j].y2;
				j=0;
				line[i].cot++;
			}
		}
	}
	k=line[0].cot;
	for(i=1;i<n;i++)
	{
		if(line[i].cot>k)
		{
			k=line[i].cot;
			l=i;
		}
	}
	printf("%d %d %d",k,line[l].x1,line[l].y1);
	return 0;
}



