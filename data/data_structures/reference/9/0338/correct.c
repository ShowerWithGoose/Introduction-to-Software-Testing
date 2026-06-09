#include<stdio.h>
struct line
{
	int x1,y1,x2,y2,num;
};
struct line lin[200];

int i,n;
int l[1000][4];
int main()
{
	scanf("%d",&n);
	for(i=0;i<n;i++)
		scanf("%d%d%d%d",&l[i][0],&l[i][1],&l[i][2],&l[i][3]);
	int j,mark=0,k=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(j!=i&&l[i][0]==l[j][2]&&l[i][1]==l[j][3])
			{
				mark=1;
				break;
			}	
				
		}
		if(mark==0)
		{
			lin[k].x1=l[i][0];
			lin[k].y1=l[i][1];
			lin[k].x2=l[i][2];
			lin[k].y2=l[i][3];
			k++;
		}
		mark=0;
	}
	for(i=0;i<k;i++)
		lin[i].num=1;
	for(i=0;i<k;i++)
	{
		for(j=0;j<n;j++)
		{
			if(lin[i].x2==l[j][0]&&lin[i].y2==l[j][1])
			{
				lin[i].x2=l[j][2];
				lin[i].y2=l[j][3];
				lin[i].num++;
				j=-1;
			}
		}
	}
	int max=0,maxn=0;
	for(i=0;i<k;i++)
	{
		if(lin[i].num>max)
		{	
			max=lin[i].num;
			maxn=i;
		}
		
	}
	printf("%d %d %d",max,lin[maxn].x1,lin[maxn].y1);
	
	return 0;
}

