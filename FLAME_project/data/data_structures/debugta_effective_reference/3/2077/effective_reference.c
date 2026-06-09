#include<stdio.h>
#include<string.h>
#include<math.h>
char s[100000];
int main()
{
	gets(s);
	int len = strlen(s);
	int count = 0;
	for (count = 0;count < len;count++)
	{
		if (s[count] == '.')
		break;
	}
	int flag = 0;
	for (int i = 0;i < count;i++)
	{
		if (s[i] != '0')
		break;
		if (i == count - 1)
			flag = 1;
	}
	if (flag == 1)
	{
		int count = 0;
		while(s[count+1]=='0')
		{
			
			char c = s[count + 1];
			s[count + 1] = s[count];
			s[count] = c;
			count++;
			count++;
		}
		char c = s[count + 1];
		s[count + 1] = s[count];
		s[count] = c;
		count++;
		if (s[count + 2] < '0' || s[count + 2]>'9')
		{
			s[count + 1] = 0;
			for (int i = count;i < len-1;i++)
				printf("%c", s[i]);
			printf("e-");
			printf("%d", count);
		}
		else
		{
			for (int i = count;i < len;i++)
				printf("%c", s[i]);
			printf("e-");
			printf("%d", count);
		}
	}
	else
	{
		if (count == 1)
		{
			printf("%s", s);
			printf("e0");
		}
		else
		{
			int count = 0;
			while(count>1)
			{
				char c = s[count - 1];
				s[count - 1] = s[count];
				s[count] = c;
				count++;
				count--;
			}
			s[len] = 'e';
			s[len + 1] = 0;
			printf("%s", s);
			printf("%d", count);
		}
	}
	return 0;
}


