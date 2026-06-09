#include<stdio.h>
int main()
{
	int a,b[105],top=0,c;
	while(1)
	{
		scanf("%d",&a);
		if(a==-1)
			return 0;
		else if(a==1)
		{
			if(top==100)
			{
				printf("error ");
				scanf("%d",&c);
				continue;
			}
			scanf("%d",&b[top]);
			top++;
		}
		else if(a==0)
		{
			if(top==0)
			{
				printf("error ");
				continue;
			}			
			
			printf("%d ",b[top-1]);	
			top--;
		}	
	
	}	
	return 0;
}



