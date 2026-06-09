/* 本次作业由本人独立实现完成，如有抄袭行为，愿承担由此带来的一切不良后果 */
#include<stdio.h>
#define MAXSIZ 100
void PUSH(int num);
void POP();
int stack[MAXSIZ+5];
int top=-1;
int main()
{
	int k,num;
	while(~scanf("%d",&k))
	{
		switch (k)
	{
		case 1:
			scanf("%d",&num);
			PUSH(num);
			//printf("\n%d\n",num);
			break;
		case 0:
			POP();
			break;
		case -1:
			//printf(" ");
			return 0;
	}
	}
	
	
	return 0;
}
void PUSH(int num)
{
	if(top==MAXSIZ-1)
	{
		printf("error ");
		return ;
	}
	stack[++top]=num;
	return ;
}

void POP()
{
	if(top==-1)
	{
		printf("error ");
		return ;
	}
	printf("%d ",stack[top--]);
	return ;
}


