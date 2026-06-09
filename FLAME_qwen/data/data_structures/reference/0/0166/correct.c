#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
	char str[500] = {0}, med[36] = { 0 }, left[500] = { 0 };
	int i, j, k, m;
	gets(str);
	for (i=1;str[i+1]!='\0';i++)
	{
		if (str[i] == '-'&& str[i-1]< str[i+1])
		{
			if ((str[i - 1] >= '0' && str[i + 1] <= '9') || (str[i - 1] >= 'a' && str[i + 1] <= 'z') || (str[i - 1] >= 'A' && str[i + 1] <= 'Z'))
			{
				for (j = 0; j <= str[i + 1] - str[i - 1]; j++)
				{
					med[j] = str[i - 1] + j;
				}
				med[j] = '\0';
				for (k = 0; k <= strlen(str) - i-2;k++)
				{
					left[k] = str[i + k + 2];
				}
				left[k] = '\0';
				strcpy(str + i-1, med);
				strcpy(str + i+j-1, left);
			}
		}
	}
	printf("%s", str);
	return 0;
}

