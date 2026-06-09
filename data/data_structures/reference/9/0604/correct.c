#include<stdio.h>
#include<string.h>
struct li{
	int x1;
	int y1;
	int x2;
	int y2;
	
};
struct hhh{
	int hi;
	int hj;
};


	int n;
	int i,j;
	struct li xian[500];
	struct hhh hao[500];
	int h=1,m;
	int count[500]={0};
	int max=0,po=0;
	int flag=0;
	int x=0,z=0;
	
	
void xunhuan(struct hhh hao[],int h)
{
	for(x=1;x<h;x++)
		{
			if(z==hao[x].hi)
			{
				z=hao[x].hj;
				count[m]++;
				return xunhuan(hao,h);
			}
				
		}
}
int main()
{

	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d %d %d %d",&xian[i].x1,&xian[i].y1,&xian[i].x2,&xian[i].y2);
		
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			while((i!=j)&&(xian[i].x2==xian[j].x1)&&(xian[i].y2==xian[j].y1))
			{
				hao[h].hi=i;
				hao[h].hj=j;
				h++;
				break;
			}
		}
	}
//	for(m=1;m<h;m++)
//	{
//		printf("%d %d\n",hao[m].hi,hao[m].hj);
//	}
	for(m=1;m<h;m++)
	{
		count[m]++;
		z=hao[m].hj;
		xunhuan(hao,h);
		if(count[m]>max)
		{
			po=m;
			max=count[m];
			i=hao[m].hi;
		}
	}
	printf("%d %d %d",max+1,xian[i].x1,xian[i].y1);

	return 0;
}

