#include<stdio.h>
#include<string.h>
char s[10000000], p[100000000];
int main()
{
	scanf("%s", s);
	int n = strlen(s);
	int j = 0;
	for (int i = 0;i < n;i++)
	{
		if (s[i+1] == '-'&& ((s[i] >= 'A' && s[i + 2] <= 'Z') || (s[i] >= 'a' && s[i + 2] <= 'z') || (s[i] >= '0' && s[i + 2] <= '9')) && (s[i] < s[i + 2]))
		{
				char k = s[i];
				while (k < s[i + 2])
				{
					p[j] = k;
					k++;
					j++;
				}
				i = i + 1;
		}
		else
		{
			p[j] = s[i];
			j++;
		}
	}
	puts(p);
	return 0;
}


