#include<stdio.h>
int res[10];
int list[11]={0,0,0,0,0,0,0,0,0,0,0};
void func(int,int);
int main()
{
	int N;
	scanf("%d",&N);
	func(0,N);
	return 0;
}
void func(int index,int n)
{
	int i,m;
	if(index==n)
	{
		for(i=0;i<n;i++)
		printf("%d ",res[i]);
		printf("\n");
		return;
	}
	for(m=1;m<=n;m++)
	{
		if(list[m]==0)
		{
		res[index]=m;
		list[m]++;
		func(index+1,n);
		list[m]--;
		}
	}
}

