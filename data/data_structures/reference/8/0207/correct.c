#include<stdio.h>
#include<string.h>
#include<string.h>
int i,j,num[200][200];
int map[200],cnt,gro[200];
void deep(int b)
{
	if(!cnt)
	{
		cnt=1;
		printf("%d",b);
	}
	else
		printf(" %d",b);
	map[b]=1;
	int k;
	for(k=1;k<=i;k++)
	{
		if(num[b][k])
		{
			if(!map[k])
			{
				deep(k);
				//shendu优先遍历。经检验该函数正确
			}
		}
	}
}
void span(int a)
{
	gro[1]=a;
	int b=1,c=1,t;
	while(b<=c)
	{
		int x=gro[b];
		b++;
		if(map[x])
			continue;
		if(!cnt)
		{
			printf("%d",x);
			cnt=1;
		}
		else
			printf(" %d",x);
		map[x]=1;
		for(t=1;t<=i;t++)
		{
			if(num[x][t])
			{
				if(!map[t])
					gro[++c]=t;
			}
		}
	}
	memset(map,0,sizeof(map));
}
int main()
{
	scanf("%d%d",&i,&j);
	int q;
	for(q=1;q<=j;q++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		num[a][b]=1;
		num[b][a]=1;
	}
	cnt=0;
	deep(0);
	printf("\n");
	memset(map,0,sizeof(map));
	cnt=0;
	span(0);
	printf("\n");
	scanf("%d",&q);
	map[q]=1;
	cnt=0;
	deep(0);
	printf("\n");
	memset(map,0,sizeof(map));
	map[q]=1;
	cnt=0;
	span(0);
	printf("\n");
	return 0;
}

