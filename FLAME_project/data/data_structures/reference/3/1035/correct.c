#include<stdio.h>
int main()
{
	char s[10000];
	int i,j,begin,bit;
	gets(s);
	for(i=0;s[i]!='.';i++)
	;
	j=i;  //j 为小数点的位置 
	if(j==1&&s[0]=='0')
	{
		for(i=j+1;s[i]=='0';i++)                     //......==    !=
			; //i为第一个数字出现的位置 
		bit=j-i;  //负数 
		begin=i;
	}
	else
	{
		bit=j-1;
		begin=0;
	}
	printf("%c",s[begin]);
	if(s[begin+1]!='\0') printf(".");
	for(i=begin+1;s[i]!='\0';i++)
	{
		if(s[i]!='.') printf("%c",s[i]);
	}
	printf("e%d\n",bit);
	return 0;
}

