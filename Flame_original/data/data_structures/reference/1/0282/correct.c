#include<stdio.h>
#include<string.h>
int N;
int a[20],b[20];
void print()
{
	int i;
	for(i=0;i<N-1;i++)
	{
		printf("%d ",b[i]);
	}
	printf("%d\n",b[i]);
}
void result(int layer)
{
	int i;
	if(layer==N)print();
	else
	{
		for(i=0;i<N;i++)
		{
			if(a[i]==0)
			{
				a[i]=1;
				b[layer]=i+1;
				result(layer+1);
				a[i]=0;
			}
		}
	}
}
int main()
{
	int i;
	scanf("%d",&N);
	result(0);
	return 0;
}

