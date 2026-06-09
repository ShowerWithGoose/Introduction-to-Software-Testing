#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>
int N;
int i,j;
int jiecheng[11];
int output[11];

int func()
{
	jiecheng[0]=1;
	int i;
	for(i=1;i<10;i++)
	{
		jiecheng[i]=i*jiecheng[i-1];
	}
}

void print()
{
	int i=0;
	for(i=0;i<N-1;i++)
	{
		printf("%d ",output[i]);
	}
	printf("%d\n",output[i]);
}

void search_for()
{
	for(i=N-2;i>=0;i--)
	{
		if(output[i]<output[i+1])
		{
			break;
		}
	}
	int k=i;
	int low=i+1;
	for(i=k+1;i<N;i++)
	{
		if((output[i]>output[k])&&(output[i]<output[low]))
		{
			low=i;
		}
	}
	int temp;
	temp=output[k];
	output[k]=output[low];
	output[low]=temp;
	for(j=k+1,i=N-1;i>j;i--,j++)
	{
		temp=output[i];
		output[i]=output[j];
		output[j]=temp;
	}
}
int main()
{
	func();
	scanf("%d",&N);
	int i;
	for(i=0;i<N;i++)
	{
		output[i]=i+1;
	}
	print();
	for(i=1;i<jiecheng[N];i++)
	{
		search_for();
		print();
	}
	
	return 0;
}

