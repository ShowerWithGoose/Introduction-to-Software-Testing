#include<stdio.h>
#include<math.h>
#include<string.h>
#include<stdlib.h>
#define MAXSIZE 100
int STAKE[MAXSIZE];
int top; 
int main()
{
	top=-1;
	int item,flag;
	while(scanf("%d",&item)!=EOF)
	{
		if(item==1)//Èë
		{
			scanf("%d",&item);
			if(top==MAXSIZE-1)
			{
				printf("error ");
				
			}
			top++;
			STAKE[top]=item;
		} 
		else if(item==0)//³ö
		{
			if(top==-1)
			{
				printf("error ");
			}
			else
			{
				printf("%d ",STAKE[top]);
			    top--;
			}
			
		 } 
		else if(item==-1)
		{
			return 0;
		}
	
	}
	
	
	return 0;
 } 

