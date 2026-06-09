#include<stdio.h>
#include<string.h>
int main()
{
	int zhan[1000],i=0,sign,data;
	while(sign==1||sign==0||sign==-1)
	{
		scanf("%d",&sign);
		if(sign==1)
		{
			scanf("%d",&data);
			if(i>=100)
				printf("error ");
			else
				zhan[i++]=data;	
		}
		
		if(sign==0)
		{
			if(i<=0)
				printf("error ");
			else
				printf("%d ",zhan[--i]);
		}	
		
		if(sign==-1)
			break;		
	}
	return 0;
}

