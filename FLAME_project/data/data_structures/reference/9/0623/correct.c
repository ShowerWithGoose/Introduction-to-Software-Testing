#include<stdio.h>
#include<stdlib.h>
int line[105][4];
int flag[105];
void bubbleSort(int n)
{
	int i, j, t, hold[4], flagt;
	for (i = 0; i < n-1; i++)
	{
		flagt = 0;
		for (j = 0; j < n-1-i; j++)
		{
			if (line[j][0] > line[j + 1][0])
			{
				for(t=0;t<4;t++)
				{
				hold[t]= line[j][t];
				line[j][t] = line[j + 1][t];
				line[j + 1][t] = hold[t];
				}
				flagt = 1;
			}
		}
		if (0 == flagt)
		break;
	}
}
int main()
{
	int num=1,tem=1;
	int mline[2];
	int n,i,j,t,flagk;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<4;j++)
		scanf("%d",&line[i][j]);
	}
	bubbleSort(n);

	mline[0]=line[0][0];
	mline[1]=line[0][1];
	for(i=0;i<n;i++)
	{
		if(flag[i]==0)
		{
			flag[i]=1;
			tem=1;
			for(t=i;t<n;)
			{
				flagk=0;
				for(j=t;j<n&&line[t][2]>=line[j][0];j++)
				{
					if(j<n&&flag[j]==0&&line[t][2]==line[j][0])
					{
						if(line[t][3]==line[j][1])
						{
							tem++;
							t=j;
							flagk=1;
							flag[j]=1;
							break;
						}
					}
				}
				if(flagk==0)
				{
					break;
				}
			}
			if(tem>num)
			{
				num=tem;
				mline[0]=line[i][0];
				mline[1]=line[i][1];
			}
		}
		
	}
	printf("%d %d %d",num,mline[0],mline[1]);
	return 0;
}


