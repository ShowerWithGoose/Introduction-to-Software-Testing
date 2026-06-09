#include<stdio.h>
struct stack{
	int top;
	int data[1020];
} d;
int main() 
{
	int i,j,n;
	d.top=0;
	while(~scanf("%d",&n))
	{
		if(n==-1)
		break;
		else if(n==1)
		{
			scanf("%d",&i);
			if(d.top>=100)
			{
				printf("error ");
			}
			else
			{
				d.data[d.top]=i;
				d.top++;
			}
		}
		else if(n==0)
		{
			if(d.top<=0)
			{
				printf("error ");	
			}
			else
			{
				printf("%d ",d.data[d.top-1]);
				d.top--;
			}
		}
	}
	return 0;
}

