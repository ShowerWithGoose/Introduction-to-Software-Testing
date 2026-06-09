#include<stdio.h>
#include<string.h>
#include<math.h>
char s[100000];
int main()
{
	gets(s);
	int n = strlen(s);
	int a = 0;
	for (a = 0;a < n;a++)
	{
		if (s[a] == '.')
		break;
	}
	int flag = 0;
	for (int i = 0;i < a;i++)
	{
		if (s[i] != '0')
		break;
		if (i == a - 1)
			flag = 1;
	}
	if (flag == 1)
	{
		int count = 0;
		while(s[a+1]=='0')
		{
			
			char c = s[a + 1];
			s[a + 1] = s[a];
			s[a] = c;
			count++;
			a++;
		}
		char c = s[a + 1];
		s[a + 1] = s[a];
		s[a] = c;
		count++;
		if (s[a + 2] < '0' || s[a + 2]>'9')
		{
			s[a + 1] = 0;
			for (int i = a;i < n-1;i++)
				printf("%c", s[i]);
			printf("e-");
			printf("%d", count);
		}
		else
		{
			for (int i = a;i < n;i++)
				printf("%c", s[i]);
			printf("e-");
			printf("%d", count);
		}
	}
	else
	{
		if (a == 1)
		{
			printf("%s", s);
			printf("e0");
		}
		else
		{
			int count = 0;
			while(a>1)
			{
				char c = s[a - 1];
				s[a - 1] = s[a];
				s[a] = c;
				count++;
				a--;
			}
			s[n] = 'e';
			s[n + 1] = 0;
			printf("%s", s);
			printf("%d", count);
		}
	}
	return 0;
}


