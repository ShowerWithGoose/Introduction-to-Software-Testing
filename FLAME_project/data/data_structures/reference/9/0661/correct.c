/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include<stdio.h>

struct point
{
	int x;
	int y;
};

struct line{
	struct point start;
	struct point final;
	int ans;
};


int main()
{
	struct line lines[105], sht[105];
	
	int flag=0,n=0,i,j,amount=0;
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
	{
		scanf("%d %d %d %d",&sht[i].start.x,&sht[i].start.y,&sht[i].final.x,&sht[i].final.y);
	}
	
	for (i = 1; i < n; i++)
	{
		flag = 0;
		for (j = 1; j < n+1-i; j++)
		{
			if (sht[j].start.x  > sht[j + 1].start.x)
			{
				struct line hold1;
				hold1 = sht[j];
				sht[j] = sht[j + 1];
				sht[j + 1] = hold1;
				flag = 1;
			}
		}
		if (0 == flag)
			break;
	}
	
	/*for(i=1;i<=n;i++)
	{
		printf("%d %d %d %d\n",sht[i].start.x,sht[i].start.y,sht[i].final.x,sht[i].final.y);
	}*/
	
	for(i=1;i<=n;i++)
	{
		flag=0;
		for(j=1;j<=amount;j++)
		{
			if(lines[j].final.x==sht[i].start.x&&lines[j].final.y==sht[i].start.y)
			{
				lines[j].final.x=sht[i].final.x;
				lines[j].final.y=sht[i].final.y;
				lines[j].ans++;
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			lines[++amount].start.x=sht[i].start.x;
			lines[amount].start.y=sht[i].start.y;
			lines[amount].final.x=sht[i].final.x;
			lines[amount].final.y=sht[i].final.y;
			lines[amount].ans=1;
		}
	}
	
	//printf("\n%d\n",amount);
	
	/*for(i=1;i<=amount;i++)
	{
		printf("\n%d\n",lines[i].ans);
	}*/

	int max=lines[1].ans,hold=1;
	for(i=2;i<=amount;i++)
	{
		if(lines[i].ans>max)
		{
			max=lines[i].ans;
			hold=i;
		}
	}

	printf("%d %d %d\n",lines[hold].ans,lines[hold].start.x,lines[hold].start.y);
	
	return 0;
}

