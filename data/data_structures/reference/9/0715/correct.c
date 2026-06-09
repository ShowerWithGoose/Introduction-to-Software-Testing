#include<stdio.h>

struct lines{
	int x1;
	int y1;
	int x2;
	int y2;
};

void sortbyx1(struct lines line[],int n)
{
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(line[i].x1>line[j].x1)
			{
				struct lines tmp;
				tmp=line[j];
				line[j]=line[i];
				line[i]=tmp;
			}
		}
	}
}

int max_a(int a[],int n)
{
	int ans=1;
	for(int i=2;i<=n;i++)
	{
		if(a[i]>a[ans])
		ans=i;
	}
	return ans;
}

int a[100];

int main()
{
	int n;scanf("%d",&n);
	struct lines line[100];
	for(int i=1;i<=n;i++)
	scanf("%d%d%d%d",&line[i].x1,&line[i].y1,&line[i].x2,&line[i].y2);
	sortbyx1(line,n);
	for(int i=1;i<=n;i++)
	{
		int num=1;
		int start=i;
		flag:
		for(int j=start+1;j<=n;j++)
		{
			if(line[j].x1==line[start].x2&&line[j].y1==line[start].y2)
			{
				start=j;
				num++;
				goto flag;
			}
		}
		a[i]=num;
	}
	int max=max_a(a,n);
	printf("%d %d %d\n",a[max],line[max].x1,line[max].y1);
	return 0;
}

