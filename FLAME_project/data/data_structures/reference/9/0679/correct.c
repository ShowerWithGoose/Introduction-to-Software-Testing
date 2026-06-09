#include<stdio.h>
int num=0,n=0;
struct xiand
{
	int v1[2];
	int v2[2];
	int flag;
};
struct xiand xd[105],copy[105];
void match()
{
	for(int i=0;i<num;i++)
	{
		xd[i].flag=1;
		for(int j=0;j<num;j++)
		{
			if(j==i)
				continue;
			if(xd[i].v2[0]==copy[j].v1[0]&&xd[i].v2[1]==copy[j].v1[1])
			{
				xd[i].v2[0]=copy[j].v2[0];
				xd[i].v2[1]=copy[j].v2[1];
				xd[i].flag++;
				j=-1;
			}
		}
	}
}
int main()
{
	scanf("%d",&num);
	for(int i=0;i<num;i++)
	{
		scanf("%d%d%d%d",&xd[i].v1[0],&xd[i].v1[1],&xd[i].v2[0],&xd[i].v2[1]);
		copy[i]=xd[i];
	}
	match();
	int max=1;
	for(int i=0;i<num;i++)
	{
		if(xd[i].flag>max)
		{
			max=xd[i].flag;
			n=i;
		}
	}
	printf("%d %d %d",xd[n].flag,xd[n].v1[0],xd[n].v1[1]);
	return 0;
}
