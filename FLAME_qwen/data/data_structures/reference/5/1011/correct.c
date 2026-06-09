#include<stdio.h>

int a[1005][2],b[1005][2];
int jieguo[1005][2],temp,changshu;
int main()
{
	int i=0,j=0,k=0,m=0;
	int count1=0,count2=0;
	char c;
	while(c!='\n')
	{
		for(j=0;j<2;j++)
		{
			scanf("%d%c",&a[i][j],&c);
		}
		i++;
		count1++;
	}
	i=0;
	c='0';
	while(c!='\n')
	{
		for(j=0;j<2;j++)
		{
			scanf("%d%c",&b[i][j],&c);
		}
		i++;
		count2++;
	}
	for(i=0;i<count1;i++)
	{
		for(j=0;j<count2;j++)
		{
			jieguo[k][0] = a[i][0]*b[j][0];
			jieguo[k][1] = a[i][1]+b[j][1];
			k++;
		}
	}
	for(i=0;i<k;i++)
	{
		for(j=i+1;j<k;j++)
		{
			if(jieguo[i][1]==jieguo[j][1])
			{
				jieguo[i][0]=jieguo[i][0]+jieguo[j][0];
				jieguo[j][0]=0;
				jieguo[j][1]=0;
			}
		}
	}
	for(i=0;i<k;i++)
	{
		for(j=i+1;j<k;j++)
		{
			if(jieguo[i][1]<jieguo[j][1])
			{
				temp=jieguo[i][0];
				jieguo[i][0]=jieguo[j][0];
				jieguo[j][0]=temp;
			
				temp=jieguo[i][1];
				jieguo[i][1]=jieguo[j][1];
				jieguo[j][1]=temp;
			}				
		}
	}	
	for(i=0;jieguo[i][0]!=0;i++)
	{
		printf("%d %d ",jieguo[i][0],jieguo[i][1]);
	}

	return 0;

}

