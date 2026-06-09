#include<stdio.h>
typedef struct {
	int an;
	int n;
} num;
int main()
{
	num num_1[105],num_2[105],result[1005];
	char c;
	int i=0,j,k=0,long_1,long_2;
	while(c!='\n')
	{
		scanf("%d %d%c",&num_1[i].an,&num_1[i].n,&c);
		i++;
	}
	long_1=i;
	c='a';
	i=0;
	while(c!='\n')
	{
		scanf("%d %d%c",&num_2[i].an,&num_2[i].n,&c);
		i++;
	}
	long_2=i;
	for(i=0;i<long_1;i++)
	{
		for(j=0;j<long_2;j++,k++)
		{
			result[k].an=num_1[i].an*num_2[j].an;
			result[k].n=num_1[i].n+num_2[j].n;
		}
	}
	for(i=0;i<k;i++)
	{
		for(j=i+1;j<k;j++)
		{
			if(result[i].n==result[j].n)
			{
				result[i].an=result[i].an+result[j].an;
				result[j].an=0;
			}
		}
	}
	int max=0,sign,times;
	for(i=0;i<k;i++)
	{
		max=-100;
		sign=-1;
		for(j=0;j<k;j++)
		{
			if(result[j].n>max&&result[j].an!=0)
			{
				max=result[j].n;
				sign=j;
				
			}
		}
		if(sign==-1) break;
		printf("%d %d ",result[sign].an,result[sign].n);
		result[sign].an=0;
	}
	return 0;
}




