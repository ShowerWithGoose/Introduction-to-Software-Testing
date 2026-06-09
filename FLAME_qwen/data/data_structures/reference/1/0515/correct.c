#include<stdio.h>
#include<string.h>
int main()
{
	int N,i,flag=0,hash[10]={0};
	long long begin=1,final=1,j;
	char num[10]={0};
	scanf("%d",&N);
	for(i=1;i<N;i++)
	{
		begin*=10;
	}
	final=begin*10;
	for(j=begin;j<final;j++)
	{
		flag=0;
		sprintf(num,"%d",j);
		memset(hash,0,sizeof(hash));
		for(i=0;i<N;i++)
		{
			hash[num[i]-'0']++;
			if(num[i]-'0'>N||num[i]=='0')
			{
				flag=1;
				break;
			}
			if(hash[num[i]-'0']>1)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
		{
			continue;
		}
		else
		{
			for(i=0;i<N-1;i++)
			{
				printf("%d ",num[i]-'0');
			}
			printf("%d\n",num[N-1]-'0');
		}
		
	}
	return 0;
}

