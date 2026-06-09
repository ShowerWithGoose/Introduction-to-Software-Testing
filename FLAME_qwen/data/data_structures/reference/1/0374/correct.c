#include<stdio.h>
#include<math.h>
#include<string.h>

void paixu(int n);
void print();
int a[10]={0},b[10]={0};
int n;

int main()
{
	scanf("%d",&n);
	paixu(0);
	return 0;
}

void print()
{
	int i=0;
	for(i=1;i<=n;i++)
	{
		printf("%d ",b[i]);
	}
	printf("\n");
}
void paixu(int k)
{
	int i;
	if(k==n)
	{
		print();
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(!a[i])
		{
			a[i]=1;
			b[k+1]=i;
			paixu(k+1);
			a[i]=0;
		}
	}
}

