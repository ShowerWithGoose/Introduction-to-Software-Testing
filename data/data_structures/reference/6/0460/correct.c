#include<stdio.h>
#define MAXSIZE 100
int Stack[MAXSIZE]; //0到99
int top=-1;
int isFull()
{
	if(top==MAXSIZE-1)
		return 1;
	else
		return 0;
}
int isEmpty()
{
	if(top==-1)
		return 1;
	else
		return 0;
}
int main()
{
	int m,n;
	while(~scanf("%d",&m)){
		//m为操作，n为数字
		switch (m) {
		case 1:{//入栈
			scanf("%d",&n);
			if(isFull())
				printf("error ");
			else
				Stack[++top]=n;
			break;
		}
		
		case 0:{//出栈
			if(isEmpty())
				printf("error ");
			else
				printf("%d ",Stack[top--]);
			break;
		}
		
		case -1:{//结束
			return 0;
			break;
		}
		
		}
	}
}

