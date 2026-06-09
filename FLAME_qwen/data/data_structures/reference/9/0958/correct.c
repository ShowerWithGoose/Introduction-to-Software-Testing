#include<stdio.h>
#include<string.h>
struct point{
	int x1,y1,x2,y2,length;
};
struct point list[100];
int searchlength(int s,int n);
int main()
{
	int n,i,max=0,maxi;	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&list[i].x1 ,&list[i].y1 ,&list[i].x2 ,&list[i].y2 );
	}
	for(i=0;i<n;i++)
	{
		list[i].length =searchlength(i,n);
		if(list[i].length >max)
		{
			max=list[i].length ;
			maxi=i;
		}
	}
	printf("%d %d %d",max+1,list[maxi].x1 ,list[maxi].y1 );
	return 0;
}
int searchlength(int s,int n)
{
	int l=0,i;
	for(i=0;i<n;i++)
	{
		if(list[i].x1 ==list[s].x2 &&list[i].y1 ==list[s].y2 )
		{
			l=1+searchlength(i,n);
		}
	}
	return l;
}

