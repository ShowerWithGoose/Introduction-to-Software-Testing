#include<stdio.h>
int zhan[200];
int main()
{
	int a,b,i=0;
	while(1)
	{
		scanf("%d",&a);
		if(a==-1)
		{
			break;
		}
		if(a==1)
		{
			scanf("%d",&b);
			if(i>=100)
			{
				printf("error ");
			}
			else
			zhan[i++]=b;
		}
		if(a==0)
		{
			if(i>0)
			{
				i--;
				printf("%d ",zhan[i]);
				
			}
			else if(i<=0)
			{
				printf("error ");
			}
		}	
	}
	return 0;
}

