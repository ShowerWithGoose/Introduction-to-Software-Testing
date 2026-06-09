#include<stdio.h>
int main()
{
	int stack[1926],i=0,cnt=0;
	while(1)
	{
		scanf("%d",&i);
		if(i==-1)
			break;
		if(i==1)
		{
			
			if(cnt==100)
			{
				printf("error ");
			}
			else{
				cnt++;
				scanf("%d",&stack[cnt]);
				//printf("cnt:%d %d//",cnt,stack[cnt]);
			}
		}
		if(i==0)
		{
			if(cnt==0)
				printf("error ");
			else
			{
				printf("%d ",stack[cnt]);
				cnt--;
			}
		}
	}
	return 0;
}

