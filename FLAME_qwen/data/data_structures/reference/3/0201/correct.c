#include <stdio.h>
//宏定义布尔类型
#define BOOL int
#define TRUE 1
#define FALSE 0

//定义一个布尔变量
BOOL flag = FALSE;
int main()
{
	int inte[100];
	int inte_n = 0;
	int deci[100];
	int deci_n = 0;
	int j,i;

	int is_inte = 1;
	int check_zero = 1;
	//处理输入
	char ch = getchar();
	while (ch != '\n')
	{
		if (ch == '.')
		{
			is_inte = 0;
			ch = getchar();
			continue;
		}
		if (is_inte)
		{
			if (ch != '0' || !check_zero)//整数的开头0不计入数组
			{
				inte[inte_n++] = ch - '0';
				check_zero = 0;
			}
		}
		else
		{
			deci[deci_n++] = ch - '0';
		}
		ch = getchar();
	}

	int e_ans = 0;
	char ans[100];
	int ans_num = 0;
	if (inte_n == 0)//整数为0，小数有进位
	{
		int i = 0;
		for (i = 0; i < deci_n; i++)
		{
			if (deci[i] == 0)
			{
				e_ans--;
			}
			else
			{
				//循环小数部分的第一个非0位
				//如果小数也全是0，则不做处理，在后续检测ans_num为0即表示数为0
				ans[ans_num++] = deci[i] + '0';
				if (i != deci_n - 1)
				{
					ans[ans_num++] = '.';
					for ( j = i + 1; j < deci_n; j++)
					{
						ans[ans_num++] = deci[j] + '0';
					}
				}
				e_ans = e_ans - 1;
				break;
			}
		}
	}
	else//整数有多位，需要退位
	{
		ans[ans_num++] = inte[0] + '0';
		if (inte_n > 1)
		{
			ans[ans_num++] = '.';
			for (i = 1; i < inte_n; i++)
			{
				ans[ans_num++] = inte[i] + '0';
				e_ans++;
			}
			for (i = 0; i < deci_n; i++)
			{
				ans[ans_num++] = deci[i] + '0';
			}
		}
		else if (deci_n > 0)
		{
			ans[ans_num++] = '.';
			for (i = 0; i < deci_n; i++)
			{
				ans[ans_num++] = deci[i] + '0';
			}
		}
	}
	//对输出进行梳理/即去掉小数部分末尾的0
	//0.012000 -> 1.2000e2 -> 1.2e2
	for (i = ans_num - 1; i >= 0; i--)
	{
		if (ans[i] == '0')
		{
			ans_num--;
		}
		else if (ans[i] == '.')
		{
			ans_num--;
			break;
		}
		else
		{
			break;
		}
	}
	//输出
	for (i = 0; i < ans_num; i++)
		printf("%c", ans[i]);
	if (ans_num == 0)
	{
		printf("0e0\n");
	}
	else
	{
		printf("e%d\n", e_ans);
	}
	return 0;
}

