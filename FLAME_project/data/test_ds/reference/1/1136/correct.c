#include <stdio.h>
int main()
{
	char s[10001],a;
	int i = 0;
	gets(s);
	while(s[i] != NULL)
	{
		if(s[i] == '-')
		{
			if((((s[i - 1] <= 'Z'&&s[i - 1] >='A')&&(s[i + 1] <= 'Z'&&s[i + 1] >='A'))||((s[i - 1] <= 'z'&&s[i - 1] >='a')&&(s[i + 1] <= 'z'&&s[i + 1] >='a')))&&s[i + 1] - s[i - 1] > 0)
			{
				a = s[i - 1] + 1;
				while(a < s[i + 1])
				{
					printf("%c",a);
					a++;
				}
			}
			else if(s[i - 1] <= '9'&&s[i - 1] >='0'&&s[i + 1] <= '9'&&s[i + 1] >='0'&&s[i - 1] < s[i + 1])
			{
				a = s[i - 1] + 1;
				while(a < s[i + 1])
				{
					printf("%c",a);
					a++;
				}
			}
			else
			printf("-");
		}
		else
		printf("%c",s[i]);
		i++;
	}
	printf("\0");
	return 0;
}

