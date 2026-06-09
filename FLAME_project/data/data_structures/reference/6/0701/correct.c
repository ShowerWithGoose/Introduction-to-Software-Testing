#include <stdio.h>
int main()
{
	int a[101];
	int temp;
	int top=0;
	int i,j,k;
	scanf("%d",&temp); 
	while(temp!=-1)
	{
		if(temp==1&&top!=101)
		{
			scanf("%d",&a[++top]);
		}
		else if(temp==0&&top!=0)
		{
			printf("%d ",a[top--]);
		}
		else if(top==0)
		{
			printf("error ");
		}
		else if(top==101)
		{
			top--;
			printf("error ");
		}
		scanf("%d",&temp);
	}
	return 0;
} 

