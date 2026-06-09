#include<stdio.h>
char ch[105];
int main()
{
	int i=0,isdot=0; //isdot记录小数点位置 
	int exp=0;//记录e的指数 
	int is0=0;//记录第一位是否为0 
	while( (ch[i]=getchar() )!='\n')
	{
		if(ch[0]=='-')
		{
		printf("-");//正负处理 
		continue;
		}
		if(ch[0]!='0'&&ch[0]!='.')
		{
			if(ch[i]=='.')
			isdot=i;
			if(i==1)
			printf(".");
			if(ch[i]!='.')
			printf("%c",ch[i]);
			i++;
		}
		else 
		{
		exp--;
		is0=1;
		}
	}
	if(is0)
	printf("e%d",exp+1);
	else
	printf("e%d",isdot-1);
	return 0;
}

