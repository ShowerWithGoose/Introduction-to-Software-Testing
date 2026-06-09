#include <stdio.h>
int found[105];
int stack[1000];
int first=0;
int last=0;
void deptra();
void widtra();
void visit();
void search();
void deptrae();
void widtrae();

void deptra(int ch[105][105],int i)
{
	int j;
	for(j=0;j<i;j++)
	{
		found[j]=0;
	}
	for(j=0;j<i;j++)
	{
		if(found[j]==0)
		{
			visit(ch,i,j);
		}
	}
	printf("\n");
}

void visit(int ch[105][105],int i,int j)
{
	found[j]=1;
	printf("%d ",j);
	int k;
	for(k=0;k<i;k++)
	{
		if(ch[j][k]==1&&found[k]==0)
		{
			visit(ch,i,k);
		}
	}
}

void widtra(int ch[105][105],int i)
{
	int j;
	for(j=0;j<i;j++)
	{
		found[j]=0;
		stack[j]=0;
	}
	for(j=0;j<i;j++)
	{
		if(found[j]==0)
		{
			search(ch,i,j);
		}
	}
	printf("\n");
} 

void search(int ch[105][105],int i,int j)
{
	found[j]=1;
	stack[first++]=j;
	int k;
	while(first>last)
	{
		j=stack[last++];
		printf("%d ",j);
		for(k=0;k<i;k++)
		{
			if(ch[j][k]==1&&found[k]==0)
			{
				found[k]=1;
				stack[first++]=k;
			}
		}
	}
}

void deptrae(int ch[105][105],int i,int edge)
{
	int j;
	for(j=0;j<i;j++)
	{
		found[j]=0;
	}
	found[edge]=1;
	for(j=0;j<i;j++)
	{
		if(found[j]==0)
		{
			visit(ch,i,j);
		}
	}
	printf("\n");
}

void widtrae(int ch[105][105],int i,int edge)
{
	int j;
	for(j=0;j<i;j++)
	{
		found[j]=0;
		stack[j]=0;
	}
	found[edge]=1;
	for(j=0;j<i;j++)
	{
		if(found[j]==0)
		{
			search(ch,i,j);
		}
	}
	printf("\n");
} 

int main()
{
	int ch[105][105]={{}};
	int i,j,edge,k;
	scanf("%d%d",&i,&edge);
	while(edge--)
	{
		scanf("%d%d",&j,&k);
		ch[j][k]=1;
		ch[k][j]=1;
	}
	deptra(ch,i);
	widtra(ch,i);
	scanf("%d",&edge);
	for(j=0;j<i;j++)
	{
		ch[j][edge]=0;
		ch[edge][j]=0;
	}
	deptrae(ch,i,edge);
	widtrae(ch,i,edge);
	return 0;
} 

