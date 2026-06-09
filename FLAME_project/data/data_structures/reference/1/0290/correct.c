#include<stdio.h>
int mark[15];
int array[15];
int n;
void f(int position)
{
	if(position>n)
	{
		for(int i=1;i<=n-1;i++)
			printf("%d ",array[i]);
		printf("%d\n",array[n]);
		return;
	}
	for(int i=1;i<=n;i++)
	{
		if(mark[i]==0)
		{
			array[position]=i;
			mark[i]=1;
			f(position+1);
			mark[i]=0;
		}
	}
}
int main()
{
	scanf("%d",&n);
	f(1);
	return 0;
}

