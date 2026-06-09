#include<stdio.h>
int stack[100]={0};
int num=0;
void push(int a[])
{
	if(num>=100)
	{
		printf("error ");
		num--;
	}
		
	else
	{
		scanf("%d",&stack[num]);
	}
}
void pop(int b[])
{
	if(num<=-1)
	{
		printf("error ");
		num++;
	}
		
	else
	{
		printf("%d ",stack[num]);
		stack[num]=0;
	}
}
int main()
{
	int ope;
	while(scanf("%d",&ope)&&ope!=-1)
		switch(ope)
		{
			case 1:
				
				push(stack);
				num++;
				break;
			case 0:
				num--;
				pop(stack);
				
				break;
		}
	return 0;
} 

