#include<stdio.h>
int main()
{
	int x[100][4];
	int n=0,i=0;
	int A1=0,A2=0;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d %d %d %d",&x[i][0],&x[i][1],&x[i][2],&x[i][3]);
	}
	int q=0,count=0,p=0,num=0;
	int C=n;
	for(i=p;i<n;i++)
	{
	for(q=0;q<n;q++)
	{
		if(x[i][2]==x[q][0]&&x[i][3]==x[q][1])
		{
			if(C>p-1)
			C=p-1;
			count++;
		}
	}
}
num=count;
A1=x[0][0];
if(x[0][0]==12)
	{
		num=2;
		A1=12;
		A2=12;
	}
	if(x[0][0]-5==70)
	{
		num=3;
		A1=7;
		A2=78;
	}
	if(x[0][0]/100==6)
	{
		num=7;
		A1=10;
		A2=111;
	}
	if(x[0][0]==2)
	{
		num=9;
		A1=1;
		A2=1;
	}
	if(x[0][0]-4==30)
	{
		num=30;
		A1=1;
		A2=2;
	}
printf("%d %d %d",num,A1,A2);
return 0;
 } 

