#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>

struct line
{
	int xl;
	int yl;
	int xr;
	int yr;
	int cnt;
};

int main()
{
	int i,j,n;
	struct line templine[107];
	struct line finalline[107];
	
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf(" %d%d%d%d",&templine[i].xl,&templine[i].yl,&templine[i].xr,&templine[i].yr);
	}
	
	int k=0,flag=0;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(templine[i].xl==templine[j].xr && templine[i].yl==templine[j].yr && i!=j)
			{
				flag=1;
				break;
			}
		}
		
		if(flag==0)
		{
			finalline[k].xl=templine[i].xl;
			finalline[k].xr=templine[i].xr;
			finalline[k].yl=templine[i].yl;
			finalline[k].yr=templine[i].yr;
			finalline[k].cnt=1;
			k++;
		}
		flag=0;
	}
	
	for(i=0;i<k;i++)
	{
		for(j=0;j<n;j++)
		{
			if(finalline[i].xr == templine[j].xl && finalline[i].yr == templine[j].yl)
			{
				finalline[i].xr=templine[j].xr;
				finalline[i].yr=templine[j].yr;
				finalline[i].cnt++;
				j=-1;
			}
		}
	}
	
	int max=0,p;
	for(i=0;i<k;i++)
	{
		if(finalline[i].cnt>max)
		{
			max=finalline[i].cnt;
			p=i;
		}
	}
	
	printf("%d %d %d\n",max,finalline[p].xl,finalline[p].yl);
	return 0;
}

