#include<stdio.h>
#include<stdlib.h>
struct xianduan
	{
		int headx;
		int heady;
		int rearx;
		int reary;
	}a[200];
int compare(const void*a,const void*b)
{
	struct xianduan*pa=(struct xianduan*)a;
	struct xianduan*pb=(struct xianduan*)b;
	int t=(pa->headx);
	int u=(pb->headx);
	return t-u;
}
int main()
{    
    int b;
    int max=0;
    int cnt=1;
    int minx;
    int miny;
    int maxx;
    int maxy;
    int finalx;
    int finaly;
	
	scanf("%d",&b);
	for(int i=0;i<b;i++)
	{
		scanf("%d %d %d %d",&a[i].headx,&a[i].heady,&a[i].rearx,&a[i].reary);
		
	}
	qsort(a,b,sizeof(struct xianduan),compare);
	for(int i=0;i<b;i++)
	{    
	     minx=a[i].headx;
	     miny=a[i].heady;
	     maxx=a[i].rearx;
	     maxy=a[i].reary;	     
		for(int j=i+1;j<b;j++)
		{
			if(maxx==a[j].headx&&maxy==a[j].heady)
			{
			maxx=a[j].rearx;
			maxy=a[j].reary;
			cnt++;
	    	}
			
		}
		if(cnt>max) 
		{	
		max=cnt;
		finalx=minx;
		finaly=miny;
	}
	  cnt=1;	
 } 
 printf("%d %d %d",max,finalx,finaly);
 return 0;
}

