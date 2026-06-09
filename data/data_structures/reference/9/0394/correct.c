#include<stdio.h>
#include<string.h>
 struct line1{
 	int x1;
 	int y1;
 	int x2;
 	int y2;
 	int next;
 };
int main ()
{
	struct line1 line[105];
	int n;
	scanf("%d",&n);
	int i,j,k;
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
		line[i].next=-1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j==i)
			continue;
			if(line[j].x1==line[i].x2&&line[j].y1==line[i].y2)
			line[i].next=j;
			if(line[j].x2==line[i].x1&&line[j].y2==line[i].y1)
			line[j].next=i;
			
		 } 
	}
//	for(i=0;i<n;i++)
//	printf("%d %d\n",i,line[i].next);
	int len [105]={0};
	for(i=0;i<n;i++)
	{
		len[i]=1;
		k=i;
		while(line[k].next!=-1)
		{
			k=line[k].next;
			len[i]++;
		}
		
	}
	//for(i=0;i<n;i++)
	//printf("%d %d\n",i,len[i]);
	int max=0;
	for(i=0;i<n;i++)
	{
		if(len[i]>len[max])
		max=i;
	}
	printf("%d %d %d",len[max],line[max].x1,line[max].y1);
	
	return 0;
}

