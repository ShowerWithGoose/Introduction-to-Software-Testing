#include<stdio.h>
int n;
int i,j;
int shunxu[11];
int output[10];
int factorial();
void print();
void find();
int main()
{
	factorial();
	scanf("%d",&n);
	int i;
	for(i=0;i<n;i++)
	{
		output[i]=i+1;
	}
	print();
	for(i=1;i<shunxu[n];i++)
	{
		find();
		print();
	}
	return 0;
}
int factorial()
{
	shunxu[0]=1;
	int i;
	for(i=1;i<10;i++)
	{
		shunxu[i]=i*shunxu[i-1];
	}
}
void print()
{
	int i=0;
	for(i=0;i<n-1;i++)
	{
		printf("%d ",output[i]);
	}
	printf("%d\n",output[i]);
}
void find()
{
	for(i=n-2;i>=0;i--)
	{
		if(output[i]<output[i+1])
		break;
	}
	int k1=i;
	int templow=i+1;
	for(i=k1+1;i<n;i++)
	{
		if(output[i]>output[k1]&&output[i]<output[templow])
		templow=i;
	}
	int temp;
	temp=output[k1];
	output[k1]=output[templow];
	output[templow]=temp;
	for(j=k1+1,i=n-1;i>j;i--,j++)
	{
		temp=output[i];
		output[i]=output[j];
		output[j]=temp;
	}
}

