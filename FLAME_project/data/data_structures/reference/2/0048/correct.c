#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int compute (int a, char c, int b)
{
	if (c == '+')
	{
		return (a + b);
	}
	else if (c == '-')
	{
		return (a - b);
	}
	else if (c == '*')
	{
		return (a * b);
	}
	else if (c == '/')
	{
		return (a / b);
	}
}

int main()
{
	char data[1000];
	char symbol[1000];   // ·ûºÅ×é 
	char n;
	int i = 0, j = 0, k = 0, m = 0, p, q, r = 0, count = 0, num = 0, numm = 0, ans;
	int arr[1000] = {};    // Êý×Ö×é 
	int pss[1000] = {};    // ¼Ó¼õºÅÎ»ÖÃ 
	int psj[1000] = {};    //ÅÐ¶Ï¼Ó¼õºÅ
	int part[1000] = {}; 
	
	do
	{
		scanf ("%c", &n);
		if (n != ' ' && n != '=')
		{
			data[i] = n;
			i++;
			if (n == '+' || n == '-')
			{
				symbol[j] = n;
				j++;
				num++;
			}
			else if (n == '*' || n == '/')
			{
				symbol[j] = n;
				j++;
				numm++;
			}
		}
	} while (n != '=');
	
	while (1)
	{
		while (data[r] && (data[r] < '0' || data[r] > '9'))
		{
			r++;
		}
		if (data[r])
		{
			p = r;
			q = r + 1;
			arr[count] = data[r] - '0';
			while (data[q] >= '0' && data[q] <= '9')
			{
				arr[count] = 10 * arr[count] + (data[q] - '0');
				q++;
			}
			r = q;
			count++;
		}
		else
		{
			break;
		}
	}
	
	if (num == 0 && numm == 0)
	{
		printf ("%s", data);
	}
	
	else if (num == 0)
	{
		ans = arr[0];
		for (i = 1; i < count; i++)
		{
			ans = compute (ans, symbol[i - 1], arr[i]);
		}
		printf ("%d", ans);
	}
	else
	{
	for (i = 0; i < j; i++)
	{
		if (symbol[i] == '+')
		{
			pss[k] = i;
			psj[k] = 1;
			k++;
		}
		else if (symbol[i] == '-')
		{
			pss[k] = i;
			psj[k] = 2;
			k++;
		}
	}
	
	if (pss[0] == 0)
	{
		part[m] = arr[0];
		m++;
	}
	else
	{
		part[m] = arr[0];
		for (i = 0; i < pss[0]; i++)
		{
			part[m] = compute (part[m], symbol[i], arr[i + 1]);
		}
		m++;
	}
	
	for (i = 1; i < num; i++)
	{
		part[m] = arr[pss[i - 1] + 1];
		for (k = pss[i - 1] + 1; k < pss[i]; k++)
		{
			part[m] = compute(part[m], symbol[k], arr[k + 1]);
		}
		m++;
	}
	
	part[m] = arr[pss[num - 1] + 1];
	for (i = pss[num - 1] + 2; i < count; i++)
	{
		part[m] = compute(part[m], symbol[i - 1], arr[i]);
	}
	
	ans = part[0];
	for (i = 0; i < num; i++)
	{
		if (psj[i] == 1)
			ans += part[i + 1];
		else
			ans = ans - part[i + 1];
	}
	printf ("%d", ans);
	}
	return 0;
}




