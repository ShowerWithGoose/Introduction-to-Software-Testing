#include<stdio.h>
int main()
{
	char s[100];
	int i, x, y, num=0;
	int flag1=0, flag2=0;
	gets(s);
	for(i=0; s[i]!='\0'; i++)
	{
		if(s[i]!='.')
		{
			if(flag2==1) //小数点已输出 
			{
				printf("%d", s[i]-'0');
			}
			else //小数点未输出 
			{
				num=num*10+(s[i]-'0');
				if(num>0 && num<10) 
				{
					y=i+1-flag1; //小数点移动后小数点前的位数
					flag2=1;
					printf("%d", num);
					if(s[i+1]!='\0') printf(".");
				} 
			}
		}
		else
		{
			x=i; //小数点前的位数x
			flag1=1; 
		}
	}
	printf("e%d", x-y);
	return 0;
}

