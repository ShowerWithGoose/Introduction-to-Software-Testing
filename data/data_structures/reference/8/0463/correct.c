#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
int biao[110][110];
int V,E;
void shendu(int a);
void guangdu(int a);
void zhiling();
int flags[110]={0},flagg[110]={0};
int temp[110]={0};

int main()
{
	int m,n,de;
	int i;
	scanf("%d%d",&V,&E);
	for(i=0;i<E;i++)
	{
		scanf("%d%d",&m,&n);
		biao[m][n]=1;
		biao[n][m]=1;
	}
	shendu(0);
	putchar(10);
	guangdu(0);
	putchar(10);
	scanf("%d",&de);
	zhiling(flags);
	zhiling(flagg);
	flags[de]=1; flagg[de]=1;
	shendu(0);
	putchar(10);
	guangdu(0);
	putchar(10);
	return 0;
}


void shendu(int a)
{
	int p;
	printf("%d ",a);
	flags[a]=1;
	for(p=0;p<V;p++)
	{
		if(biao[a][p]==1&&flags[p]==0)
			shendu(p);
	}
}
void guangdu(int a)
{
	int p=0,q=0,k;
	int t;
	int jishu=0;
	temp[0]=a;
	while(p<=q)
	{
		t=temp[p++];
		if(flagg[t]==1) continue;
		printf("%d ",t);
		jishu++;
		flagg[t]=1;
		for(k=0;k<V;k++)
		{
			if(biao[t][k]==1&&flagg[k]==0)
				temp[++q]=k;
		}
	}
}

void zhiling(int k[])
{
	int i;
	for(i=0;i<110;i++)
	{
		k[i]=0;
	}
}

