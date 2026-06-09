#include<stdio.h>
int main()
{
	int n=0,flag=2,zhan[105]={0},num;
	while(flag!=-1)
	{
		scanf("%d",&flag);
		if(flag==1)
		{	scanf("%d",&num);
			if(n>=100)
			{
				printf("error ");
				
			}
			else
			{
				n++;
				zhan[n]=num;
				
			}
		}
		if(flag==0)
		{
			if(n<=0)
				{
				printf("error ");
			
			}
			else
			{
				printf("%d ",zhan[n]);
				zhan[n]=0;
				n--;
			}
		}
		
	}
}

