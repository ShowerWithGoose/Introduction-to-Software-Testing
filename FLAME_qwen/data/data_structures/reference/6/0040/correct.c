#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<ctype.h>
int ammo[100];
int main()
{
	int b=-1,a=0;
	while(1)
	{
		scanf("%d",&a);//:判断操作 
		if(a==1)
		{
			scanf("%d",&ammo[++b]);//:入栈 
		}
		else if(a==0)//:出栈 
		{
			if(b==-1)//:如果空状态出栈 
			{
				printf("error ");
			}else
			{
				printf("%d ",ammo[b--]);
			}
			
		}else if(a==-1)//:结束 
		{
			break;
		}
	}
	return 0;
}



