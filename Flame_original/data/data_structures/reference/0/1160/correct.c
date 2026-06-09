#include <stdio.h>
#include <string.h>

int main()
{
	char in[1000];
	char ou[1000] = {'\0'};
	gets(in);
	int len = strlen(in);
	int i = 0;
	int j = 0;
	while (i < len)
	{
		switch (in[i])
		{
		case '-':
			if (i > 0)
			{
				char a = in[i - 1];
				char b = in[i + 1];
				if (a < b && ((a >= 'a' && a <= 'z' && b >= 'a' && b <= 'z')
							||(a >= 'A' && a <= 'Z' && b >= 'A' && b <= 'Z')
							||(a >= '0' && a <= '9' && b >= '0' && b <= '9')))
				{
					char op = a + 1;
					while (op < b)
					{
						ou[j] = op;
						j++;
						op++;
					}
					i++;
					break;
				}
				else
				{
					ou[j] = '-';
					j++;
					i++;
					break;
				}
			}
			else
			{
				ou[j] = '-';
				j++;
				i++;
				break;
			}
		default:
			ou[j] = in[i];
			j++;
			i++;
			break;
		}
	}
	printf("%s",ou);
	

	return 0;
}
