#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<time.h>

int line[105][5];
int time1=1;
int n;
void cot(int p,int t)//p最后一条线段下标  t已经连线的长度 
{
	int i;
	line[p][4]=1;
	for(i=0;i<n;i++)
	{
		if(line[i][0]==line[p][2]&&line[i][1]==line[p][3]&&line[i][4]==0)
		{
			line[i][4]=1;
			cot(i,t+1);
			line[i][4]=0;
			//printf("%d ",t);
		}
	}
	time1=time1>t?time1:t;
	return ;
}

int main()
{
	int i;
	int ans1=0,ans2=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d%d%d",&line[i][0],&line[i][1],&line[i][2],&line[i][3]);
		//printf("%d %d %d %d\n",line[i][0],line[i][1],line[i][2],line[i][3]); 
	}
	int j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			line[j][4]=0;
		time1=1;
		cot(i,1);
		if(ans1<time1)
		{
			ans1=time1;
			ans2=i;
		}	
		//printf("%d ",time1);
	}
	printf("%d %d %d",ans1,line[ans2][0],line[ans2][1]);
	return 0;
}
/*
10
80 75 125 75
60 40 80 55
80 55 90 20
140 120 195 205
10 111 70 165
22 35 43 43
22 175 80 205
43 43 60 40
90 20 125 60
70 165 140 120
*/

