#include<stdio.h>
#include<stdlib.h>

typedef struct list{
	int top;
	int data[105];
};
int main()
{
	struct list zhan;
	
	int act,num,i=0;
	
	zhan.top=0;
	while(scanf("%d ",&act) != EOF)
	{
		if(act==1)
		{
			scanf("%d ",&num);
			if(zhan.top>=100)
			{
				printf("error ");

			}
			else
			{
				zhan.data[zhan.top++]=num;
			}
		}
		else if(act==0)
		{
			if(zhan.top==0)
			{
				printf("error ");
			}
			else
			{
				printf("%d ",zhan.data[zhan.top-1]);
				zhan.top--;
			}
		}
		else
			break;
	}
	return 0;
}

