#include <stdio.h>
int example1c_1(char s1[])	//去除字符数组中所有空格
{
	int i = 0, j = 0;
	while(s1[i] != '\0')
	{
		if(s1[i] == ' ')
		{
			i++;
			continue;
		}
		s1[j++] = s1[i++];
	}
	s1[j] = '\0';
}
int example1c_2(int num[], int i, int x)	//删除整型数组中第i+1个元素 
{
	for(i++; i < x; i++)
		num[i] = num[i+1];
}
int example1c_3(char s1[], int num[], int i, int j, int x)	//递归将字符数组中数字置于整形数组中 
{
	if(s1[i] == '=')
	{
		num[j] = x;
		return 0;
	}
	else if(s1[i] >= '0' && s1[i] <= '9')
	{
		x = x * 10 + s1[i] - '0';
		s1[i] = ' ';
	}
	else
	{
		num[j++] = x;
		x = 0;
	}
	example1c_3(s1, num, ++i, j, x);
}
int main()
{
	int i = 0, num[2000];
	char s1[2000];
	fgets(s1, 2000, stdin);
	example1c_1(s1);
	example1c_3(s1, num, 0, 0, 0);
	example1c_1(s1);
	for(i = 0; s1[i] != '=';)
	{
		if(s1[i] == '*')
		{
			num[i] = num[i] * num[i+1];
			example1c_2(num, i, sizeof(s1)/sizeof(s1[0]));
			s1[i] = ' ';
			example1c_1(s1);
		}
		else if(s1[i] == '/')
		{
			num[i] = num[i] / num[i+1];
			example1c_2(num, i, sizeof(s1)/sizeof(s1[0]));
			s1[i] = ' ';
			example1c_1(s1);
		}
		else
			i++;
	}
	for(i = 0; s1[i] != '=';)
	{
		if(s1[i] == '+')
		{
			num[i] = num[i] + num[i+1];
			example1c_2(num, i, sizeof(s1)/sizeof(s1[0]));
			s1[i] = ' ';
			example1c_1(s1);
		}
		else if(s1[i] == '-')
		{
			num[i] = num[i] - num[i+1];
			example1c_2(num, i, sizeof(s1)/sizeof(s1[0]));
			s1[i] = ' ';
			example1c_1(s1);
		}
	}
	printf("%d", num[0]);
	return 0; 
}

