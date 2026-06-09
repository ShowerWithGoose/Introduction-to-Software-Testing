#include <stdio.h>
#include <string.h>
char b[200] = {0};
char s[200];
int main()
{
	
	scanf("%s", s);
	int i = 0;
	int j = 0;
	int t = 0;
	int ling = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			if (s[i - 1] >= 'a' && s[i - 1] <= 'z' && s[i + 1] >= 'a' && s[i + 1] <= 'z' && s[i + 1] > s[i - 1])
			{
				for (j = 0; j < i; j++)
				{
					b[j] = s[j];
				}
				for (ling=0; ling < (s[i + 1] - s[i - 1]); ling++)
				{
					b[j] = b[j - 1] + 1;
					j++;
				}
				t = i + 1;
				for (; s[t] != '\0'; t++)
				{
					b[j++] = s[t+1];
				}
				for (j = 0; b[j] != '\0'; j++)
				{
					s[j] = b[j];
				}
			}
			else if (s[i - 1] >= 'A' && s[i - 1] <= 'Z' && s[i + 1] >= 'A' && s[i + 1] <= 'Z' && s[i + 1] > s[i - 1])
			{
				for (j = 0; j < i; j++)
				{
					b[j] = s[j];
				}
				for (ling = 0; ling < (s[i + 1] - s[i - 1]); ling++)
				{
					b[j] = b[j - 1] + 1;
					j++;
				}
				t = i + 1;
				for (; s[t] != '\0'; t++)
				{
					b[j++] = s[t+1];
				}
				for (j = 0; b[j] != '\0'; j++)
				{
					s[j] = b[j];
				}
		

			}
			else if (s[i - 1] >= '0' && s[i - 1] <= '9' && s[i + 1] >= '0' && s[i + 1] <= '9' && s[i + 1] > s[i - 1])
			{
				for (j = 0; j < i; j++)
				{
					b[j] = s[j];
				}
				for (ling = 0; ling < (s[i + 1] - s[i - 1]); ling++)
				{
					b[j] = b[j - 1] + 1;
					j++;
				}
				t = i + 1;
				for (; s[t] != '\0'; t++)
				{
					b[j++] = s[t+1];
				}
				for (j = 0; b[j] != '\0'; j++)
				{
					s[j] = b[j];
				}
			}
			else
			{
				for (j = 0; j < 200; j++)
				{
					b[j] = s[j];
				}
			}
		}
		i++;

	}
	printf("%s", b);
}




