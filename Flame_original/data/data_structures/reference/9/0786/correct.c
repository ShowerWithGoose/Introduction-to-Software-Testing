#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define FOR(a,b,c) for(a=b;a<c;a++)
#define ll long long
#define ull unsigned long long
int main()
{
	int line[101][4];//每条线段的两个端点的坐标 
	int num[101]={'0'};//
	int k=0,total,m=0,w=0; 
	scanf("%d\n",&total);
	for(int i=0;i<total;i++)
	{
		scanf("%d%d%d%d",&line[i][0],&line[i][1],&line[i][2],&line[i][3]);
	}
	for(int i=0;i<total;i++)
	{
		k=i;
		w=i; 
		num[k]=1;
		for(int j=0;j<total;j++)
		{
			if(line[w][2]==line[j][0]&&line[w][3]==line[j][1])
			{
				num[k]++;
				w=j;
				j=-1;
			}
		}
	}
	for(int i=0;i<100;i++)
	{
		if(num[i]>m)
		{
			m=num[i];
			k=i;
		}
	}	
	printf("%d %d %d\n",m,line[k][0],line[k][1]);
	return 0;
}



