#include<stdio.h>
#define M 100
int main()
{
	int stack[M],top=-1,i,ele,order;
	while(order!=-1)
	{
		scanf("%d",&order);
		if(order==1)
		{
			i=top+1;
			scanf("%d",&ele);
			stack[i]=ele;
			top=i;
			i++;	
		}
		if(order==0)
		{
			if(top<0)
			{
				printf("error ");
			}
			if(top>=0)
			{
				printf("%d ",stack[top]);
				top--;
				
			}
			
		}
		if(order==-1)
		{
			return 0;
		}
		
		
		
		
		
		
		
		
	}
	
	
	
	
	
	
	
	
} 

