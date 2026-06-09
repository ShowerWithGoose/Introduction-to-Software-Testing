#include<stdio.h>
#include<stdlib.h>
int data[105][4], sum[105];
int cmp(const void*, const void*);
int main()
{
	int n,i,j,max = 0,output;
	scanf("%d",&n);
	for(i = 0; i < n; i++)
	{
		scanf("%d%d%d%d",&data[i][0],&data[i][1],&data[i][2],&data[i][3]);
	}
	qsort(data,n,sizeof(int)*4,cmp);
	for(i = 0; i < n; i++)
	{
		sum[i]=judge(i,n,1);
	}
	for(i=0;i<n;i++)
	{
		if(sum[i] > max)
		{
			max=sum[i];
			output = i;
		}
			
	}
	printf("%d %d %d",sum[output],data[output][0],data[output][1]);
	return 0;
}
int judge(int i, int n, int floor)
{
	int j,floor1=floor;
	for(j = i+1; j<n; j++)
	{
		if(data[i][2]==data[j][0]&&data[i][3]==data[j][1])
		{
			return judge(j,n,floor+1);
		}
	}
		return floor;
}
int cmp(const void *a, const void *b)
{
	int *aa = a,*bb = b;
	if(aa[0]<bb[0])
		return -1;
	else 
		return 1;
}

