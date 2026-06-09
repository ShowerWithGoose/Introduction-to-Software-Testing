/*用小数表示的浮点数――gets输入
判断方式：首位是否为0，
是则按e-处理，不是则e*/
#include<stdio.h>
int main()
{
	int i,j=2,k,flag=0;
	char Num[105];
	scanf("%s",Num);
	if(Num[0]=='0')
	{
		for(i=2;Num[i]!='\0';i++)
		{
			if(Num[i]=='0'&&0==flag)
			{
				j=i+1;
			}
			if(Num[i]!='0')
			{
				flag=1;
			}
		}
		if(i-j>1)
		{
			printf("%c.",Num[j]);
			for(k=j+1;k<i;k++)
			{
				printf("%c",Num[k]);
		    }
		}
		else
		{
			printf("%c",Num[j]);
		}
		printf("e-%d",j-1);
	}
	else
	{
		printf("%c.",Num[0]);
		for(i=0;Num[i]!='\0';i++)
		{
			if(Num[i]!='.'&&0==flag)
			{
				j=i;
			}
			else if(Num[i]=='.')
			{
				flag=1;
			}
			if(i!=0&&Num[i]!='.')
			{
				printf("%c",Num[i]);
			}
		}
		printf("e%d",j);
	}
	return 0;
} 

