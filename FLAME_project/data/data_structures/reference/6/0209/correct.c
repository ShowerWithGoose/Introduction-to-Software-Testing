#include<stdio.h>



int main()
{
	int Stack[100],temp,op;
	int Top=-1;
	while(1)
	{
		scanf("%d",&op);
		if(op==1)
		scanf("%d",&temp);
		else if(op==-1)
		break;
		
		if(op)
		{
			if(Top!=100-1)
			{
				Stack[++Top]=temp;
			}
			else
			{
				printf("error ");
			}
		}
		else
		{
			if(Top!=-1)
			{
				printf("%d ",Stack[Top--]);
			}
			else
			{
				printf("error ");
			}
		} 
	}
	return 1;
}

