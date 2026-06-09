#include<stdio.h>
struct line{
	struct{
		int x;
		int y;
	}v1,v2;
	int next;
}l[105];
int n;
int main()
{
	int i,j,t,num=0,maxnum=0,maxi=0;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%d%d%d%d",&l[i].v1.x,&l[i].v1.y,&l[i].v2.x,&l[i].v2.y);
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(j==i)
				continue;
			if(l[i].v2.x==l[j].v1.x&&l[i].v2.y==l[j].v1.y)
			{
				l[i].next=j;
			}
		}
	}
	for(i=1;i<=n;i++)
	{
		t=l[i].next;
		num=1;
		while(t!=0)
		{
			t=l[t].next;
			num++;
		}
		if(num>maxnum)
		{
			maxnum=num;
			maxi=i;
		}
	}
	printf("%d %d %d",maxnum,l[maxi].v1.x,l[maxi].v1.y);
	/*for(i=1;i<=n;i++)
	{
		printf("%d\n",l[i].next);
	}*/
	return 0;
}

