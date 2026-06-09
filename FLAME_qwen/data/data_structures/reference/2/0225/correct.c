#include <stdio.h>
#include <ctype.h>
int s1[100000], s2[100000], d1 = 0, d2 = 0;
char c;

int getNum(char a)
{
	int s = a - '0';
	scanf("%c", &c);
	while (isdigit(c))
	{
		s *= 10;
		s += c - '0';
		scanf("%c", &c);
	}
	return s;
}

int main()
{
	scanf("%c", &c);
	
	while (c != '=' && c != '\n')
	{
		int flag = 0;
		switch (c)
		{
		case '+':
			s2[d2++] = 1;
			break;
		case '-':
			s2[d2++] = -1;
			break;
		case '*':
			s2[d2++] = 20;
			break;
		case '/':
			s2[d2++] = 30;
			break;
		default:
			if (isdigit(c))
			{
				int d = getNum(c);
				flag = 1;
				s1[d1++] = d;
				if (d2 != 0)
				{
					if (s2[d2 - 1] == 20)
					{
						int a = s1[--d1];
						int b = s1[--d1];
						s1[d1++] = a * b;
						d2--;
					}
					else if (s2[d2 - 1] == 30)
					{
						int a = s1[--d1];
						int b = s1[--d1];
						s1[d1++] = b / a;
						d2--;
					}
				}
			}
			break;
		}
		if (!flag)
		{
			scanf("%c", &c);
			flag = 0;
		}
	}
	int cnt = s1[0];
	while (d2 != 0)
		cnt += s1[--d1] * s2[--d2];
	printf("%d", cnt);
	return 0;
}
