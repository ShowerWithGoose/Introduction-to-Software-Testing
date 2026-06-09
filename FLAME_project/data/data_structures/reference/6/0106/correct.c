#include<stdio.h>

int main()
{
	int front=0,rear=0,order;
	int a[100]={};
	for(;;)
	{
		scanf("%d",&order);
		if(order==-1) return 0;
		if(order==1)
		{
			if((rear==99&&front==0)||rear+1==front)
				printf("error ");
			else
			{
				rear++;
				scanf("%d",&a[rear]);	
			}
		}
		else if(order==0)
		{
			if(front==rear) printf("error ");
			else
			{
				printf("%d ",a[rear]);
				rear--;
			}
		}
	}
}

