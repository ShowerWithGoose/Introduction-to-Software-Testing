#include<stdio.h>
int a[101];
int top=-1;
int main()
{
	int status,now;
	while(1)
	{   scanf("%d",&status);
	if(status==-1)
	return 0;
		else if(status==1)
		{   scanf("%d",&now);
		if(top==99)
		{
			printf("error ");
			continue;
		}   
		    else
			{
			a[++top]=now;
			}
			
		}
		else 
		{
			if(top==-1)
			{
				printf("error ");
				continue;
			}
			else
			{   printf("%d ",a[top]);
				top--;
			}
		}
	}
}

