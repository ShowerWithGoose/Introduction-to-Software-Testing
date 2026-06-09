#include<stdio.h>
int sum=0,num=1,chu=0;
char hao=0;
int main()
{
	int in=0;
	while(1)
	{
		scanf("%d",&in);
		if(!chu) num*=(in);
		else num/=(in);
		chu=0;
		while(1)
		{
			scanf("%c",&hao);
			if(hao!=' ') break;	
		}
		if(hao=='-')
		{
			sum+=num;
			num=-1;
		}
		else if(hao=='+')
		{
			sum+=num;
			num=1;
		}
		else if(hao=='/') chu=1;
		else if(hao=='=')
		{
			printf("%d",sum+num);
			break;
		}
		
	}
	return 0;
}

