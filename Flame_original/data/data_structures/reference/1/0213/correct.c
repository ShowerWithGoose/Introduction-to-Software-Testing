#include<stdio.h>
#define MAX 100000
int first[MAX];
int last[MAX];
int N;

int main()
{
	scanf("%d",&N);
	cal(0);
}

void cal(int step)
{
	int i;
	if(step == N)
	{
		print();
	}
	else
	{
		for(i = 0; i < N; i++)
		{
			if(!first[i])
			{
				first[i] = 1;
				last[step] = i + 1;
				cal(step + 1);
				first[i] = 0;
			}
		}
	}
}

void print()
{
	int i;
	for(i=0;i<N-1;i++)
	{
		printf("%d ",last[i]);
	}
	printf("%d\n",last[i]);
}




