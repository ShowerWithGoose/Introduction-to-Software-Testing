#include <stdio.h>
#include <string.h>
int main ()
{
	int cnt=0;
	int date=0;
	int stack[105];
	int num[1005];
	do{
		scanf("%d",&num[cnt]);
		cnt++;
	}
	while(num[cnt-1]!=-1);
	 cnt=cnt-1;
	for(int i=0;i<cnt;i++)
	{
//		printf("%d\t",num[i]);
		
		if(num[i]==1)
		{
			stack[date]=num[i+1];
//			printf("%d  ",stack[date]);
			date++;
		}
		if(num[i]==0)
		{
			if((date>0)&&(date<100))
			{
				printf("%d ",stack[date-1]);
				date--;
			}
			else
			{
				printf("error ");
			}
		}
	}
	
	return 0;
}

