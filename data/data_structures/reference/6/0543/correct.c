#include <stdio.h>
int s[100],top=-1;
int isfull()
{
	return top==99;
}
int isempty()
{
	return top==-1;
}
int push(int item)
{
	if(isfull())
		printf("error ");
	else
		s[++top]=item;
		
	return 0;
}
int pop()
{
	if(isempty())
		printf("error ");
	else
	{
		printf("%d ",s[top]);
		top--;
	}
	return 0;	
}
int main()
{
	int manu,num;
	while(scanf("%d",&manu)==1)
	{
		if(manu==-1)
			return 0;
		else if(manu==1)
		{
			scanf("%d",&num);
			push(num);
		}
		else if(manu==0)
			pop();
	}
	return 0;
}

