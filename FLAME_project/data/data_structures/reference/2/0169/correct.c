#include<stdio.h>
#include<string.h>
#include<ctype.h>

int len, arr[10005], num, len1 = 1, len2 = 1, flag = 1;
char s[10005], arrop[10005];

void input()//读入字符 
{
	fgets(s, 10001, stdin);
	len = strlen(s);
	s[len-1] = '\0';//去掉换行符 
	len--;
	//puts(s);
}

void delSpace()//删除空格 
{
	int i, j = 0; 
	for(i=0; i<len; i++)
	{
		if(s[i]!=' ')
			s[j++] = s[i];
	}
	len = j;
	s[j] = '\000';
	//puts(s);
} 

int calculate()//计算主程序 
{
	int i, j = 1;
	for(i=0; i<len; i++)
	{
		if(s[i]>='0'&&s[i]<='9')
		{
			num = num*10 + s[i] - '0';//处理数字 
		}
		else//将数字入栈 
		{
			arr[len1++] = num;
			num = 0;
			if(arrop[len2-1]=='*')
			{
				arr[len1-2] = arr[len1-2] * arr[len1-1];
				len1--;
				len2--;
			}
			else if(arrop[len2-1]=='/')
			{
				arr[len1-2] = arr[len1-2] / arr[len1-1];
				len1--;
				len2--;
			}
			if(s[i]=='=')
				break;
			else 
				arrop[len2++] = s[i];
		}
	}
	//弹出 所有剩余数字和运算符
	for(i=1; i<len2; i++)
	{
		if(arrop[i]=='+')
		{
			arr[j+1] = arr[j] + arr[j+1];
			j++; 
		}
		else if(arrop[i]=='-')
		{
			arr[j+1] = arr[j] - arr[j+1];
			j++;//此时要用队列 
		}
	}
	return j;
}

int main()
{
	input();
	
	delSpace();
	
	flag = calculate();
	
	printf("%d", arr[flag]);
	
	return 0;
}

