#include<stdio.h>
void expend(char x,char y)//扩展x到y之间的字符，并且立即输出 
{
	x++;//第一个不输出,输出过了 
	while(x<y)
	{
		printf("%c",x);
		x++;
	 } 
}
int check(char x)//检测类型  1-->数字  2-->大写字母  3-->小写字母   其它-->0 
{
	if(x>='0'&&x<='9')
	return 1;
	if(x>='A'&&x<='Z')
	return 2;
	if(x>='a'&&x<='z')
	return 3;
	return 0;
 } 
int main()
{
	char ch[10005]="\0";
	scanf("%s",ch);
	printf("%c",ch[0]);
	int i=1;
	while(ch[i]!='\0')
	{
		if(ch[i]=='-')
		{
			if( ( ( check(ch[i-1]) )==check(ch[i+1]) )&&check(ch[i-1])!=0 )
			expend(ch[i-1],ch[i+1]);
			else printf("-");
		}
		else printf("%c",ch[i]);
		i++;
	}
	return 0;
	}

