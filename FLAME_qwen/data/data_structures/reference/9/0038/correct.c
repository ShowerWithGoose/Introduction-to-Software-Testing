#include <stdio.h>
struct X
{
	int x1;
	int y1;
	int x2;
	int y2;
	int N;
	int M;
}L[100];
int main()
{
	int n,i,p=0,j;
	scanf("%d",&n);
	while(n--)
	{
		int x3,y3,x4,y4;
		int b;
		b=0;
		scanf("%d %d %d %d",&x3,&y3,&x4,&y4);
		for(i=0;i<p;i++)
		{
			if(x3==L[i].x2&&y3==L[i].y2)
			{
				L[i].y2=y4;
				L[i].x2=x4;
				L[i].N++;
				b=1;
				break;
			}
			if(x4==L[i].x1&&y4==L[i].y1)
			{
				L[i].y1=y3;
				L[i].x1=x3;
				L[i].N++;
				b=1;
				break;
			}
		}
		if(b==0)
		{
			L[i].x1=x3;
			L[i].x2=x4;
			L[i].y1=y3;
			L[i].y2=y4;
			L[i].N++;
			p++;
		}
	}
		for(i=0;i<p;i++)
		{
			for(j=0;j<p;j++)
			{
				if(L[i].x1==L[j].x2&&L[i].y1==L[j].y2)
				{
					L[i].x1=L[j].x1;
					L[i].y1=L[j].y1;
					if(L[j].N!=1)
					{
						L[i].N=L[i].N+L[j].N;
					}
					else
					L[i].N++;
					L[j].x1=0;
					L[j].x2=0;
					L[j].y1=0;
					L[j].y1=0;
					L[j].N=0;
					L[j].M=0;
				}
				if(L[i].x2==L[j].x1&&L[i].y2==L[j].y1)
				{
					L[i].x2=L[j].x2;
					L[i].y2=L[j].y2;
					if(L[j].N!=1)
					{
						L[i].N=L[i].N+L[j].N;
					}
					else
					L[i].N++;
					L[j].x1=0;
					L[j].x2=0;
					L[j].y1=0;
					L[j].y1=0;
					L[j].N=0;
					L[j].M=0;
				}
			}
		}
		for(i=0;i<p;i++)
		{
			for(j=0;j<p;j++)
			{
				if(L[i].N>=L[j].N)
				{
					L[i].M++;
				}
			}
		}
		for(i=0;i<p;i++)
		{
			if(L[i].M==p)
			{
				printf("%d ",L[i].N);
				printf("%d %d",L[i].x1,L[i].y1);
			}
		}	
		
		
		
		
		
		
		
		
		
		
		return 0;
	}
	
	
	
	
	
	
	
	
	


