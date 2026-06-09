#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct line
{
	int x1;
	int y1;
	int x2;
	int y2;
	int num;
};
int main()
{
	int n,i,j,k=0,max=1,s;
	scanf("%d",&n);
	struct line a[1100];
	memset(a,0,sizeof(a));
	struct line b[1100];
	memset(b,0,sizeof(b));
	for(i=0;i<n;i++){
		scanf("%d%d%d%d",&a[i].x1,&a[i].y1,&a[i].x2,&a[i].y2);
	}
	for(i=0;i<n;i++){
		int x=0;
		for(j=0;j<n;j++){
			if(i==j)
				continue;
			if(a[i].x1==a[j].x2&&a[i].y1==a[j].y2)
			{
				x=1;//不是起点 
				break;
			}
		}
		if(x==0)
		{
			b[k].x1=a[i].x1;
			b[k].y1=a[i].y1;
			b[k].x2=a[i].x2;
			b[k].y2=a[i].y2;
			k++;
		}			
	}
	for(i=0;i<k;i++){//找终点 
		b[i].num=1;
		for(j=0;j<n;j++){
			if(b[i].x2==a[j].x1&&b[i].y2==a[j].y1)
			{
				b[i].num++;
				b[i].x2=a[j].x2;
				b[i].y2=a[j].y2;
				j=-1;
			}
		}
	}
	for(i=0;i<k;i++){
		if(max<b[i].num)
		{
			max=b[i].num;
			s=i;
		}
	}
	printf("%d %d %d\n",max,b[s].x1,b[s].y1);
	return 0;
}

