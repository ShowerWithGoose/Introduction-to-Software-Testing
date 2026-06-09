#include<stdio.h>
int main()
{
	int stack[110];//用一维数组模拟栈
	//int num=0;//位置脚标
	int op;//
	int data;//被操作的数据
	for(int num=0;;)
	{
		scanf("%d",&op);
		
		if(op==1)//入栈
		{
			scanf("%d ",&data);
			if(num==100)printf("error ");
			else
			{
				stack[num]=data;
				num++;
			}
		}
		if(op==0)//出栈
		{
			if(num==0)printf("error ");
			else{
				num--;
				printf("%d ",stack[num]);
			}
			
		}
		if(op==-1)
		break;
	}
	return 0;
}

