#include <stdio.h>
int calculate(int,char,int);
int compare(char,char);
int main()
{
	int left,mid,right;
	char yi,er;
	scanf("%d",&left);
	do
	{
		scanf("%c",&yi);
	}while(yi==' ');
	if(yi=='=') printf("%d",left);
	else
	{
	scanf("%d",&mid);
	do
	{
		scanf("%c",&er);
	}while(er==' ');
	if(er=='=')
	printf("%d",calculate(left,yi,mid));
	else
	{
		while(er!='=')
		{
		scanf("%d",&right);
		if(compare(yi,er)==0)
		{
		left=calculate(left,yi,mid);
		mid=right;
		yi=er;	
		}
		else
		mid=calculate(mid,er,right);
		do
	{
		scanf("%c",&er);
	}while(er==' ');
		}
		printf("%d",calculate(left,yi,mid));
	}
	}
	return 0;
}
int calculate(int x,char b,int y)
{
	if(b=='*')
	return x*y;
	if(b=='/')
	return x/y;
	if(b=='+')
	return x+y;
	if(b=='-')
	return x-y;
}
int compare(char yi,char er)
{
	if(yi=='*'||yi=='/')
	return 0;
	else
	if(er=='*'||er=='/')
	return 1;
	else
	return 0;
}

