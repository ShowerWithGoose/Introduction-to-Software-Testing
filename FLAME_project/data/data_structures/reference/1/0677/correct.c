#include<stdio.h>
int a[10];
int flag[10];
int n;

void func(int step);
void print();

int main()
{
	scanf("%d",&n);
	func(0); 
	return 0;
}

void func(int step)
{
	if(step==n)
	{
		print();
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(flag[i]==0)
		{
			flag[i]=1;
			a[step]=i+1;
			func(step+1);
			flag[i]=0;
		}
	}
	return ;
}

void print()
{
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
	putchar(10);
	return;
}



