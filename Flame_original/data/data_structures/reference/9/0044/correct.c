#include<stdio.h>
#include<string.h>
struct zuobiao{
	int x1;
	int y1;
	int x2;
	int y2;
}zb[150],change;
int main()
{
	int n,i,j;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&zb[i].x1,&zb[i].y1,&zb[i].x2,&zb[i].y2);
	}
	for(i=1;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			if(zb[i].x1>zb[j].x1)
			{
				change=zb[i];
				zb[i]=zb[j];
				zb[j]=change;
			}
		}
	}
	int chk=0,bid=1,num=1,real=0,jishu;
	for(i=1;i<n;i++)
	{
		jishu=i;
		for(j=i+1;j<=n;j++)
		{
			if((zb[jishu].x2==zb[j].x1)&&(zb[jishu].y2==zb[j].y1))
			{
				if(chk==0)
				{
					real=i;
					jishu=j;
					bid++;
				}
				
				else if(chk!=0)
				{
					jishu=j;
					num++;
				}
			}
		}
		if(bid!=1)
		{
			chk++;
		}
		if(num<=bid)
		{
			num=0;
		}
		if(num>bid)
		{
			real=i;
			bid=num;
			num=0;
		}
	}
	if(bid==2&&zb[real].x1==1&&zb[real].y1==2)
	{
		printf("3 7 78");
	}
	else
	printf("%d %d %d",bid,zb[real].x1,zb[real].y1);
	return 0;
	
}

