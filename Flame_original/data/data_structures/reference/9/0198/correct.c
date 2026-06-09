#include<stdio.h>
struct line{
	int x1;
	int x2;
	int y1;
	int y2;
}l[100];
int main()
{
	int n;int s;
	scanf("%d",&n);
	struct line al;
	for(s=0;s<n;s++)
	{
		scanf("%i %i %i %i",&l[s].x1,&l[s].x2,&l[s].y1,&l[s].y2);
	}
	int d,t;
	for(d=n-1;d>=0;d--)
	{
		for(t=0;t<d;t++)
		{
			if(l[t].x1>l[t+1].x1)
			{
				al=l[t];
				l[t]=l[t+1];
				l[t+1]=al;
			}
		}
	}
	int max=1;
	for(s=0;s<n;s++)
	{
		int s1=s;int m=1;
		for(d=s+1;d<n;d++)
		{
			while(com(l[s1],l[d])==1)
			{
				s1=d;
				m++;
			}
			if(m>max)
			{
				max=m;
				al=l[s];
			}
		}
		
	}
	printf("%d %d %d",max,al.x1,al.x2);
	return 0;
}
int com(struct line a1,struct line a2)
{
	if(a1.y1==a2.x1&&a1.y2==a2.x2){
		return 1;
	}else return 0;
}

