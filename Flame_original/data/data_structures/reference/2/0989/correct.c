#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	char ch[10005];
	int a[10005] = {0}, i = 0, j = 0, q = 0, b[10005] = {0}, x = 0;
	gets(ch);
	for (i = 0; i < strlen(ch); i++)
	{
		if (ch[i] != ' ' && ch[i] != '=')
		{
			if (ch[i] == '+') //-1表示+  -2表示-  -3表示*  -4表示/
			{
				a[j++] = -1;
			}
			else if (ch[i] == '-')
			{
				a[j++] = -2;
			}
			else if (ch[i] == '*')
			{
				a[j++] = -3;
			}
			else if (ch[i] == '/')
			{
				a[j++] = -4;
			}
			else
			{
				a[j] = ch[i] - '0';
				for (i++; ch[i] >= '0' && ch[i] <= '9'; i++)
				{
					a[j] = a[j] * 10 + ch[i] - '0';
				}
				i--;
				j++;
			}
		}
	}
	for (int k = 0; k < j; k++)
	{
		if (a[k] >= -2)
		{
			b[q] = a[k];
			q++;
		}
		else
		{
			q--;
			b[q] = a[k - 1];
			while (a[k] == -3 || a[k] == -4)
			{
				if (a[k] == -3)
				{
					b[q] *= a[k + 1];
				}
				else
				{
					b[q] /= a[k + 1];
				}
				k+=2;
			}
			k--;
			q++;
		}

		// if (a[k] == -3)
		// {
		// 	q--;
		// 	b[q] = a[k - 1];
		// 	while (a[k] == -3)
		// 	{
		// 		b[q] *= a[k + 1];
		// 		k += 2;
		// 	}
		// 	k--;
		// 	q++;
		// }
		// else if (a[k] == -4)
		// {
		// 	q--;
		// 	b[q] = a[k - 1];
		// 	while (a[k] == -4)
		// 	{
		// 		b[q] /= a[k + 1];
		// 		k += 2;
		// 	}
		// 	k--;
		// 	q++;
		// }
		// else
		// {
		// 	b[q] = a[k];
		// 	q++;
		// }
	}
	x = b[0];
	for (int p = 1; p < q; p += 2)
	{
		if (b[p] == -1)
		{
			x += b[p + 1];
		}
		else if (b[p] == -2)
		{
			x -= b[p + 1];
		}
	}
	printf("%d", x);
	return 0;
}

