#include<stdio.h>
#include<string.h>
struct point{
	int x1;
	int y1;
	int x2;
	int y2;
};
int main()
{

    struct point lon[102];
    int n,i,j,k[102],len,min,max;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
	scanf("%d%d%d%d",&lon[i].x1,&lon[i].y1,&lon[i].x2,&lon[i].y2);
	k[i]=0;
	}
    for(i=0;i<n;i++)
    {
    	for(j=0;j<n-i-1;j++)
    	{
    		if(lon[j].x1>lon[j+1].x1)
    		{
    			min=lon[j].x1;
    			lon[j].x1=lon[j+1].x1;
    			lon[j+1].x1=min;
    			min=lon[j].y1;
    			lon[j].y1=lon[j+1].y1;
    			lon[j+1].y1=min;
    			min=lon[j].x2;
    			lon[j].x2=lon[j+1].x2;
    			lon[j+1].x2=min;
    			min=lon[j].y2;
    			lon[j].y2=lon[j+1].y2;
    			lon[j+1].y2=min;
			}
		}
	}
	for(i=0;i<n;i++)
	{
		k[i]=1;
		for(j=i;j<n-1;j++)
		if(lon[i].x2==lon[j+1].x1&&lon[i].y2==lon[j+1].y1)
		{
			k[i]++;
			lon[i].x2=lon[j+1].x2;
			lon[i].y2=lon[j+1].y2;
		 } 
	}
	max=0;
	for(i=0;i<n;i++)
	{
		if(max<k[i])
		{
			max=k[i];
			min=i;
		}
		else continue;
	}
	printf("%d %d %d",max,lon[min].x1,lon[min].y1);
    return 0;
}

