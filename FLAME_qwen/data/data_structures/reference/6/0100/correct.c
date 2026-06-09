#include<stdio.h>
int arr[100]={0};
int main()
{
	int rear=-1,num,n;
	scanf("%d",&n); 
	while(n!=-1)
	{
		if((rear==-1&&n==0)||(rear==99&&n==1))
		printf("error ");
		else if(n==1)
		{
			scanf("%d",&num);
			rear++;
			arr[rear]=num;
		}
		else if(n==0)
		{
			printf("%d ",arr[rear]);
			rear--;
		}
		scanf("%d",&n);
	 } 
	return 0;
}

