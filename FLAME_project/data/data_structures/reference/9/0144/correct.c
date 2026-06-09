#include<stdio.h>
#include<stdio.h>

int main()
{
	int num,i,j,k,number;
	int ans[105]= {0};
	int line[105][4];
	int temp=0,flag=0;
	scanf("%d",&num);

	for(i=0; i<num; i++)
	{
		for(j=0; j<4; j++)
		{
			scanf("%d",&line[i][j]);
		}
	}
	
	for(i=0; i<num; i++)
	{
		j=i;
		for(k=0; k<num; k++)
		{
			if((line[j][2]==line[k][0])&&(line[j][3]==line[k][1]))
			{
				j=k;
				k=-1;
				ans[i]++;
			}
		}
	}

	temp=ans[0];
	for(i=0; i<num; i++)
	{
		if(ans[i]>temp)
		{
			temp=ans[i];
			flag=i;
		}
	}
	printf("%d %d %d",temp+1,line[flag][0],line[flag][1]);
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

