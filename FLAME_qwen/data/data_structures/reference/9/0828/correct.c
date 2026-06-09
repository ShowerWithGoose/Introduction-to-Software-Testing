#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<malloc.h>
#define ll long long
#define Maxsize 1000
typedef struct node
{
	int x1;
	int y1;
	int x2;
	int y2;
	int flag;
}lin;
lin line[109];
lin ans;
int n,sum;
void find(lin*q)
{
	int i=0;
	for(i=0;i<n;i++)
	{
 		if(line[i].x1==q->x2&&line[i].y1==q->y2)
		 {
		 	sum++;
		 	line[i].flag=1;
		 	find(&line[i]);
		 	return;
		 }
	}
	return ;
}
int main()
{
	int i,j,max=0;
 	scanf("%d\n",&n);
 	for(i=0;i<n;i++)scanf("%d %d %d %d\n",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
 	for(i=0;i<n;i++)
 	{
 		sum=0;
 		if(line[i].flag==1)continue;
 		else find(&line[i]);
 		if(sum>max)
 		{
 			ans.x1=line[i].x1;
 			ans.y1=line[i].y1;
			max=sum;
		 }
	}
	printf("%d %d %d",max+1,ans.x1,ans.y1);
	return 0;
}


