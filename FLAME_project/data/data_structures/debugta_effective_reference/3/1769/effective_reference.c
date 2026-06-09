#include <stdio.h>
int main()
{
	int N = 100, i, x, y, flag, a;
	char s[N];
	gets(s);
	for(i = 0, flag = 1; s[i] != '\0'; i++)	//获取小数点及第一个非零数字的位置 
	{
		if(s[i] == '.')
		{
			x = i;
			continue;
		}
		if(s[i] != '0' && flag)
		{
			flag = 0;
			y = i;
		}
	}
	if(s[y + 1] == '\0')	//应对无小数点的情况 
		printf("%c", s[y]);
	else
		printf("%c%c", s[y],s[x]);
	for(i = y+1; s[i] != '\0'; i++)
	{
		if(i == x)
			continue;
		printf("%c", s[i]);
	}
	printf("%c", 'e');
	a = x - y;	//计算并给出e的数量级 
	if(a > 0)
		printf("%d", a-1);
	else if(a == 0)
		printf("%d", 0);
	else if(a < 0)
		printf("%d", a);
	return 0;
}

