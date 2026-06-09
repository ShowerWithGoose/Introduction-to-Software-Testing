#include<stdio.h>
#include<string.h>
struct xianduan
{
	int x1;
	int y1;
	int x2;
	int y2;
};
struct count
{
	int N;
	int x0;
	int y0;
	int x3;
	int y3;
};
int main()
{
	struct xianduan info[1000];
	struct count ff[1000];
	int n,i,j,k,m,a[1000];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&info[i].x1,&info[i].y1,&info[i].x2,&info[i].y2);
	}
	for(i=0;i<n;i++)
	{
		ff[i].x0=info[i].x1;
		ff[i].y0=info[i].y1;
		ff[i].x3=info[i].x2;
		ff[i].y3=info[i].y2;
		a[i]=1;
		for(j=0;j<n;j++)
		{
			if((info[j].x1==ff[i].x3)&&(info[j].y1==ff[i].y3))
			{
				a[i]=a[i]+1;
		        ff[i].x3=info[j].x2;
		        ff[i].y3=info[j].y2;
		        j=0;
			}
			if((info[j].x2==ff[i].x0)&&(info[j].y2==ff[i].y0))
			{
				a[i]=a[i]+1;
				ff[i].x0=info[j].x1;
		        ff[i].y0=info[j].y1;
		        j=0;
			}
		}
	}
	k=a[0];
	m=0;
	for(i=1;i<n;i++)
	{
		if(a[i]>k)
		{
			k=a[i];
			m=i;
		}
		
	}
	printf("%d %d %d",k,ff[m].x0,ff[m].y0);
	return 0;
}



