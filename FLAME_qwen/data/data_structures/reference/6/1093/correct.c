#include<stdio.h>
int STACK[100];
int main()
{
	int i=0;//i指向栈顶未填充 指向的下标表示栈中元素个数 
	int op,item;
	
	while(scanf("%d",&op)!=-1)
	{
		if(op==-1)
		{
			break;
		}
		else if(op==1)
		{
			scanf("%d",&item);
			STACK[i++]=item;
		}
		else
		{
			if(i==0)
			{
				printf("error ");
			}
			else
			{
				printf("%d ",STACK[--i]);
			}
		}
	}
	return 0;
}

