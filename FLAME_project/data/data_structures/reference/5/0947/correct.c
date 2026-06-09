#include<stdio.h>
#include<stdlib.h>
int comp(const void* p1,const void*p2);
int x1[1005][2];
int x2[1005][2];
int result[2010][2];
int main()
{
	int i=0,j=0,n=0,k,t,flag;
	char a,b;
	while(scanf("%d%d%c",&x1[i][0],&x1[i][1],&a)!=EOF)
	{
		i++;
		if(a=='\n')
		break;
	}
	while(scanf("%d%d%c",&x2[j][0],&x2[j][1],&b)!=EOF)
	{
		j++;
		if(b=='\n')
		break;
	}	
	for(k=0;k<i;k++)
	{
		for(t=0;t<j;t++)
		{
			result[n][0]=x1[k][0]*x2[t][0];
			result[n][1]=x1[k][1]+x2[t][1];
			n++;
		}
	}
	qsort(result,n,sizeof(result[0]),comp);
	for(i=0;i<n;i++)
	{
		flag=0; 
		for(j=i+1;j<n+1;j++)
		{
			if(result[i][1]!=result[j][1])
			{
				printf("%d %d ",result[i][0],result[i][1]);
				break;
			}
			
			if(result[i][1]==result[j][1])
			{
				result[i][0]+=result[j][0];
				flag++;
				continue;
			}
		}
		i+=flag;
	}
	if(result[n-1][1]==0)
	{
		printf("%d %d",result[n-1][0],result[n-1][1]);
	}
	return 0;
}
int comp(const void* p1,const void* p2)
{
	if (((int *)p1)[1] > ((int *)p2)[1])
	return -1;
	return 1;
}
