#include<stdio.h>
int main()
{
	int stack[100]={0};
	int key,count=0;
	scanf("%d",&key);
	while(key!=-1)
	{
		if(key==1)
		{
			if(count<100)
				scanf("%d%d",&stack[count++],&key);
			else
			{
				printf("error ");
				scanf("%d",&key);
				continue;	
			}
		}
		if(key==0)
		{
			if(count!=0)
			{
				printf("%d ",stack[--count]);				
				scanf("%d",&key);
				continue;
			}
			else
			{
				printf("error ");
				scanf("%d",&key);
			}
		}
	}
	return 0;
}

