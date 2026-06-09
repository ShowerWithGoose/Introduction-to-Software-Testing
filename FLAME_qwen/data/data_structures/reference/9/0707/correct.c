#include <stdio.h>
int main()
{
	int x[105][4],n,len,flag,i,j,max=0,ans1,ans2,a,b;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	for(j=0;j<4;j++)
	scanf("%d",&x[i][j]);
	for(i=0;i<n;i++)
	{len=0;
	a=x[i][2];
	b=x[i][3];	
	flag=1;
	while(flag!=0)
	{flag=0;
	for(j=0;j<n;j++)
	if(a==x[j][0]&&b==x[j][1])
	{len++;
	a=x[j][2];
	b=x[j][3];
	flag=1;
	}
	}
	if(len>max)
	{ans1=x[i][0];
	ans2=x[i][1];
	max=len;
	}
	}
	printf("%d %d %d",max+1,ans1,ans2);
	return 0;
 } 

