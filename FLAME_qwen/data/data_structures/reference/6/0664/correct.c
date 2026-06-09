#include<stdio.h>
int num[100];
int main()
{
	int sign,i=1;
	while(1)
	{
		scanf("%d",&sign);
		if(sign==1)
		{
			if(i>=100)
			printf("error");
			else
		{
				i++;
			scanf("%d",&num[i]);}
		//	printf("£¡%d",num[3]);
		}
		else if(sign==0)
		{
			if(i-1>0)
			{
			printf("%d ",num[i--]);
			}
			else
			printf("error ");
		}
		else if(sign==-1)
		return 0;
		
	}
 } 

