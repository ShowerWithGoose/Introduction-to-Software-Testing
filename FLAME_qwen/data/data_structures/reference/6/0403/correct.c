#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#define MAXSIZE 105

int main()
{
	int num,val;
	int stack[MAXSIZE],top;
	top=-1;
	while(1)
	{
		scanf("%d",&num);
		if(num==-1)
		  break;
		else if(num==1)
		{
			scanf("%d",&val);
			//printf("%d ",val);
			if(top==999)
			  printf("error ");
			else{
				++top;
				stack[top]=val;
				
			}
			
		}
		else if(num==0)
		{
		    if(top==-1)
			  printf("error ");
			else{
				printf("%d ",stack[top]);
				top--;
			}	
		}
		else
		  continue;
	}
	return 0;
}



