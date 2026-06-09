#include <stdio.h>
int a[100],g=100;
int top=-1;
int main()
{
	int g=100; 
	int b,c,d;
	while(g--)
	{
		scanf("%d",&b);
		if(b==-1)
		break;
		if(b==1) 
		{
			scanf("%d ",&c);
			if(top==100 )
				printf("error ");
			else
			 	{
			 		top++;
					a[top]=c;
				}
		}
		else if(b==0)
		{
			if(top==-1)
			printf("error ");
			else
			{
			printf("%d ",a[top]);
			top--;
			}
		}
	}	
	return 0;
}


