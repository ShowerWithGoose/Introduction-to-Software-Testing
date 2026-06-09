/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include<stdio.h>
int str[15];
int flag[15],N;

void rank(int m,int n,int N)
{
	int i;
	if(n==0)
	{
		for(i=0;i<N;i++)
		{
			printf("%d%c",str[i],i==N-1?'\n':' ');
		}
		return;
	}
	for(i=1;i<=N;i++)
	{
		if(flag[i]==0)
		{
			flag[i]++;
			str[m]=i;
			rank(m+1,n-1,N);
			flag[i]=0;
		}
	}
}

int main()
{
	scanf("%d",&N);
	rank(0,N,N);
	return 0;
}

