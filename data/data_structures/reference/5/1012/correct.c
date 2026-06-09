#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#define MAXLINE 1024
int rcd1[1024][1024];
int rcd2[1024][1024];
int res[1024][1024];
int plus[1024][1024];
int main()
{
	int i=0;
	char c;
	scanf("%d%d%c",&rcd1[0][0],&rcd1[0][1],&c);
	i=1;
	while(c!='\n')
	{
		scanf("%d%d",&rcd1[i][0],&rcd1[i][1]);
		scanf("%c",&c);
		i++;
	}
	c=' ';
	scanf("%d%d%c",&rcd2[0][0],&rcd2[0][1],&c);
	i=1;
	while(c!='\n')
	{
		scanf("%d%d",&rcd2[i][0],&rcd2[i][1]);
		scanf("%c",&c);
		i++;
	}
	i=0;
	int j=0,k=0;
	for(i=0;rcd1[i][0]!=0;i++)
	{
		for(j=0;rcd2[j][0]!=0;j++)
		{
			res[k][0]=rcd1[i][0]*rcd2[j][0];
			res[k][1]=rcd1[i][1]+rcd2[j][1];
			k++;
		}
	}//乘完了
	int t1=0;
	j=0;
	for(i=0;res[i][0]!=0;i++)
	{
		if(res[i][0]==-1)continue;
		else
		{
			for(t1=i+1;res[t1][0]!=0;t1++)
				{
					if(res[i][1]==res[t1][1])
					{
						res[i][0]+=res[t1][0];
						res[t1][0]=-1;
					}
				}
		 			plus[j][0]=res[i][0];
		 			plus[j][1]=res[i][1];
					j++;
		}
	 } //相加结束 
	int max=0;
	for(i=0;plus[i][0]!=0;i++)
	{
		max=0;
		for(t1=1;plus[t1][0]!=0;t1++)
		{
			if(plus[max][1]>plus[t1][1])continue;
			else max=t1;
		}
		printf("%d %d ",plus[max][0],plus[max][1]);
		plus[max][0]=-1;
		plus[max][1]=0;
	}
	return 0;
}

