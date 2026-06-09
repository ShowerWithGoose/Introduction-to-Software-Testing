#include<stdio.h>
#include<string.h>
#define MAXN 10005


char num[MAXN];


void print(int flag, int len, int exp)//输出科学计数法的小数 
{
	int i;
	printf("%c.", num[flag]);
	for(i=flag+1; i<len; i++)
	{
		if(num[i]!='.')
			putchar(num[i]);
	}
	printf("e%d", exp);
}


int main()
{
	//freopen("notation.in", "r", stdin);
	int i, len, cnt = 0, cntt = 0;
	gets(num);
	len = strlen(num);
	for(i=0; i<len&&num[i]!='.'; i++);
		cnt = i;//寻找小数点 记录小数点前有多少位 
	
	if(cnt==1&&num[0]!='0')//整数部分只有一位且不为零 
	{
		print(0, len, 0);
	}
	else if(num[0]=='0')//整数部分为零 注意小数可能只有一位 
	{
		for(i=cnt; num[i]=='0'||num[i]=='.'; i++)
			cntt--;
		if(i==len-1)//特判 
		{
			printf("%ce%d", num[i], cntt); 
		}
		else 
			print(i, len, cntt);//注意是i 
	}
	else if(cnt>1)//整数部分有多于一位 
	{
		print(0, len, cnt-1);
	}
	return 0;
}



