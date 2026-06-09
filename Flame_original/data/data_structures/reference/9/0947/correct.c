#include<stdio.h>
#include<stdlib.h>
int line[105][4];
int longest[105][4];
int comp(const void* p1,const void* p2);
int main()
{
	int n,i,j,k=0,max;
	int flag[105]={0};
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&line[i][0],&line[i][1],&line[i][2],&line[i][3]);
	}
	qsort(line,n,sizeof(line[0]),comp);
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n+1;j++)
		{
			if(line[i][2]==line[j][0]&&line[i][3]==line[j][1])
			{
				line[i][2]=line[j][2];
				line[i][3]=line[j][3];
				flag[i]++;
			}
		}
	}
	max=flag[0];
	for(i=0;i<n;i++)
	{
		if(flag[i]>max)
		{
			max=flag[i];
			k=i;
		}
	}
	printf("%d %d %d",max+1,line[k][0],line[k][1]);
	return 0;	
}
int comp(const void* p1,const void* p2)
{
	if(((int *)p1)[0]<(((int *)p2)[0]))
	return -1;
	return 1;
}

