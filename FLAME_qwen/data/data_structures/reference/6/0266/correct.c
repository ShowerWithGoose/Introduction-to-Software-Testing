#include<stdio.h>
int main()
{
	int op,num,stack[100],final_num=0;
	while(scanf("%d",&op)!=EOF)
	{
		if(op==0)
		{
			if(final_num==0)
			{
				printf("error ");
			}
			else
			printf("%d ",stack[--final_num]);
		}
		else if(op==1)
		{
			scanf("%d",&num);
			if(final_num==100)
			printf("error ");
			else
			stack[final_num++]=num;
		}
	}
	return 0;
}

