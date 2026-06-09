#include<stdio.h>
#include<string.h>

int main()
{
	int a[100];
	memset(a,0,sizeof(a));
	int top=-1;
	while(1)
	{
		int op;
		scanf("%d",&op);
		if(op==1)
		{
			int temp;
			scanf("%d",&temp);
			a[++top]=temp;
		}
		else if(op==0)
		{
			if(top!=-1)
			{
				printf("%d ",a[top]);
				a[top--]=0;
			}
			else 
				printf("error ");
		}
		else if(op==-1)
			break;
	}
	return 0;
}

