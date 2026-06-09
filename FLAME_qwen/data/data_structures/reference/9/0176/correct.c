#include<stdio.h>
int max(int a[],int n);
struct spot
{
	int x1;
	int y1;
	int x2;
	int y2;
	struct spot *p;
}line[100];
int LENGTH(struct spot list);
int main()
{
	int n,i,j;
	scanf("%d",&n);
	int len[n];
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
	}
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if((line[j].x1==line[i].x2&&line[j].y1==line[i].y2)||
			(line[i].x1==line[j].x2&&line[i].y1==line[j].y2))
				if(line[j].x1>line[i].x1) line[i].p=&line[j];
				else line[j].p=&line[i];		
		}
	}	
	for(i=0;i<n;i++)
	{
		len[i]=LENGTH(line[i]);
	}
	for(i=0;i<n;i++)
	{
		if(len[i]==max(len,n)) break;
	}
	printf("%d %d %d",max(len,n)+1,line[i].x1,line[i].y1);
	return 0; 
} 
int LENGTH(struct spot list)
{
	int n=0;
	while(list.p!=NULL)
	{
		n++;
		list.p=(*(list.p)).p;
	}
	return n;
}
int max(int a[],int n)
{
	int i,max=a[0];
	for(i=1;i<n;i++)
		if(max<a[i]) 
			max=a[i];
	return max;	
}

